//
// Created by Patrick Mintram on 27/04/2017.
//

#ifndef DUNGEON_DUNGEON_T_H
#define DUNGEON_DUNGEON_T_H


#include <vector>
#include <iostream>

#include "room_t.h"
#include "room_join_strat_t.h"
#include "player_t.h"

class dungeon_t
{
public:
	enum relative_direction_t { N, E, S, W };
	dungeon_t( const int h, const int w, const char wall = '#');
	size_t add_room(const room_t r);
	void show( void ) const;
	void clear_all_rooms( void );
	void join_rooms( void );
	int get_width( void ) const { return m_w; }
	int get_height(void) const { return m_h; }
	const room_t& get_room( const int i ) const { return m_rooms[i]; }
	const player_t& get_player(void) const { return *m_player; }
	const position_t& update_player_position(const position_t new_position);

protected:
	std::vector<room_t> m_rooms;
	std::vector<std::vector<char>> m_map;
	const int m_w, m_h;
	const char m_wall;
	player_t* m_player;
	room_join_strat_t* m_rj_strat;

	void join_last_added_room( void );
	void add_room_to_map( const room_t& r);
	void check_bounds( const room_t& r ) const;
	bool rooms_overlap(const room_t& first, const room_t &second) const;
	bool player_is_in_room( const position_t new_position ) const;

};

#endif //DUNGEON_DUNGEON_T_H
