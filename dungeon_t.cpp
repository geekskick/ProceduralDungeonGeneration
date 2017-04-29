//
// Created by Patrick Mintram on 27/04/2017.
//

#include <cmath>
#include <sstream>
#include "dungeon_t.h"
#include "utilities_t.h"

size_t dungeon_t::add_room(const room_t r)
{
	try
	{
		check_bounds(r);
		utilities_t::get().debug_print("Adding room");
		m_rooms.push_back( r );
		add_room_to_map( r );
		join_last_added_room();
	}
	catch(std::runtime_error &r)
	{
		utilities_t::get().debug_print(r.what());
	}
	return m_rooms.size();
}

void dungeon_t::show( void ) const
{
	std::cout << std::string(100,'\n');
	utilities_t::get().debug_print("Dungeon is as follows:");
	for(std::vector<std::vector<char>>::const_iterator it = m_map.begin(); it != m_map.end(); it++)
	{
		for(std::vector<char>::const_iterator init = it->begin(); init != it->end(); init++)
		{
			std::cout << *init;
		}
		std::cout<< std::endl;
	}
}

dungeon_t::dungeon_t( const int h, const int w, const char wall )
		: m_rooms(), m_map(h, std::vector<char>(w, wall)), m_w(w), m_h(h), m_wall(wall),
		  m_player(), m_exit_location({0,0})
{}

void dungeon_t::add_room_to_map( const room_t &r )
{
	for( int i = r.get_top_edge(); i < r.get_bottom_edge(); i++ )
	{
		for( int j = r.get_left_edge(); j < r.get_right_edge(); j++ )
		{
			m_map[i][j] = ' ';
		}
	}
}

void dungeon_t::check_bounds( const room_t &r ) const
{
	if( r.get_right_edge() >= m_map[0].size() ||
		r.get_bottom_edge() >= m_map.size() ) { throw  std::runtime_error("Room goes outside of dungeon"); }

	for(std::vector<room_t>::const_iterator it = m_rooms.begin(); it != m_rooms.end(); it++)
	{
		if( rooms_overlap(*it, r) ) { throw std::runtime_error("Rooms overlap"); }
	}
}

void dungeon_t::clear_all_rooms( void )
{
	m_rooms.clear();
	for(std::vector<std::vector<char>>::iterator it = m_map.begin(); it != m_map.end(); it++)
	{
		for(std::vector<char>::iterator init = it->begin(); init != it->end(); init++)
		{
			*init = m_wall;
		}
	}

}

bool dungeon_t::rooms_overlap( const room_t &first, const room_t &second ) const
{
	return (
			( second.get_left_edge() < first.get_right_edge() ) &&
			( second.get_right_edge() > first.get_left_edge() ) &&
			( second.get_top_edge() < first.get_bottom_edge() ) &&
			( second.get_bottom_edge() > first.get_top_edge() )
	);
}

void dungeon_t::join_rooms( void )
{
	m_rj_strat = new half_rjs();
	for(int i = 1; i < m_rooms.size(); i++)
	{
		m_rj_strat->join_rooms( m_rooms[i-1], m_rooms[i], m_map );
	}

	delete m_rj_strat;
}

void dungeon_t::join_last_added_room( void )
{
	m_rj_strat = new half_rjs();
	if( m_rooms.size() > 1 )
	{
		m_rj_strat->join_rooms( m_rooms[m_rooms.size() - 2], m_rooms[m_rooms.size() - 1], m_map );
	}
}

const position_t &dungeon_t::update_player_position( position_t new_position )
{
	if(player_is_in_room(new_position))
	{
		//clear old locations on map
		m_map[m_player.get_y()][m_player.get_x()] = ' ';

		//set the new location on the map
		m_player.position() = new_position;
		m_map[m_player.get_y()][m_player.get_x()];
		m_map[m_player.get_y()][m_player.get_x()] = m_player.get_icon();

		//debugging
		std::stringstream ss;
		ss << "The player is at (" << m_player.get_y() << "," << m_player.get_x() << ")";
		utilities_t::get().debug_print(ss.str());
	}
	return m_player.position();
}

bool dungeon_t::player_is_in_room( const position_t& new_position ) const
{
	return m_map[new_position.get_y()][new_position.get_x()] != m_wall;
}

bool dungeon_t::player_has_found_exit( void ) const
{
	return m_player.position() == m_exit_location;
}

void dungeon_t::create_exit( void )
{
	// Create an exit in the middle of one of the rooms
	int rand_room = utilities_t::get().get_rand_in_range(m_rooms.size()-1);
	room_t& r = m_rooms[rand_room];
	position_t c = r.get_centre();
	m_exit_location = c;
	m_map[m_exit_location.get_y()][m_exit_location.get_x()] = '@';

}

const position_t &dungeon_t::add_player( player_t &player )
{

	if(player_is_in_room(player.position()))
	{
		//set the new location
		m_player = player;
		m_map[m_player.get_y()][m_player.get_x()];
		m_map[m_player.get_y()][m_player.get_x()] = m_player.get_icon();

		//debugging
		std::stringstream ss;
		ss << "The player is at (" << m_player.get_y() << "," << m_player.get_x() << ")";
		utilities_t::get().debug_print(ss.str());
	}
	else{
		// if not a viable location recursively find the next most viable location
		utilities_t::get().debug_print( "No player added trying again");
		if(player.get_y() - 1 != m_wall) { player.position().set_y(player.get_y() - 1); }
		else if(player.get_y() + 1 != m_wall) { player.position().set_y(player.get_y() + 1);}
		else if(player.get_x() - 1 != m_wall) { player.position().set_x(player.get_x() - 1);}
		else if(player.get_x() + 1 != m_wall) { player.position().set_x(player.get_x() + 1);}
		add_player(player);
	}
	return m_player.position();
}

