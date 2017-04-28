//
// Created by Patrick Mintram on 28/04/2017.
//

#include "room_join_strat_t.h"
#include "utilities_t.h"
#include <cmath>
#include <sstream>

void half_rjs::join_rooms( const room_t &from, const room_t &to, std::vector<std::vector<char>> &map )
{
	position_t from_centre = from.get_centre();
	position_t to_centre = to.get_centre();
	const position_t change_point = get_half_way(from_centre, to_centre);
	const relative_direction_t dir = get_relative(from, to);

	switch(dir)
	{
		case W:
			swap(from_centre, to_centre);
		case E:
			draw_horizontal(from_centre.get_y(), from_centre, change_point, map);
			draw_vertical(change_point.get_x(), from_centre, to_centre, map);
			draw_horizontal(to_centre.get_y(), change_point, to_centre, map);
			break;
		case N:
			swap(from_centre, to_centre);
		case S:
			draw_vertical(from_centre.get_x(), from_centre, change_point, map);
			draw_horizontal(change_point.get_y(), from_centre, to_centre, map);
			draw_vertical(to_centre.get_x(), change_point, to_centre, map);
			break;
	}

}

position_t half_rjs::get_half_way( const position_t &from, const position_t &to ) const
{
	return { from.get_y() + ((to.get_y() - from.get_y())/2), from.get_x() + ((to.get_x() - from.get_x())/2) };
}

room_join_strat_t::relative_direction_t room_join_strat_t::get_relative( const room_t &from, const room_t &to ) const
{
	// use trig to get polar angle
	const position_t from_p = from.get_centre();
	const position_t to_p = to.get_centre();
	const double d_x = to_p.get_x() - from_p.get_x();
	const double d_y = to_p.get_y() - from_p.get_y();
	const double theta_rads = atan( d_y / d_x );
	double theta_degs = theta_rads * 180 / M_PI;

	// make all the angles with reference to up
	// these are calculated by trial and error only rather than any maths
	if( d_x < 0 && d_y > 0 ) { theta_degs = 270 + theta_degs; }
	if( d_x > 0 && d_y > 0 ) { theta_degs += 90; }
	if( d_x < 0 && d_y < 0 ) { theta_degs += 270; }
	if( d_x > 0 && d_y < 0 ) { theta_degs += 90; }
	theta_degs = fmod( theta_degs, 360.0 );

	std::stringstream ss;
	ss << "From " << from_p.get_x() << ", " << from_p.get_y() << " to " << to_p.get_x() << ", " << to_p.get_y() << " is an angle of " << theta_rads << " [" << theta_degs << "]";
	utilities_t::get().debug_print(ss.str());

	// roughly split into a direction based on the angle
	if( theta_degs >= 45.0 && theta_degs < 135.0 ) { return E; }
	if( theta_degs >= 135.0 && theta_degs < 225.0 ) { return S; }
	if( theta_degs >= 225.0 && theta_degs < 315.0 ) { return W; }
	return N;

}

void room_join_strat_t::swap( position_t &a, position_t &b )
{
	position_t temp = a;
	a = b;
	b = temp;
}

void room_join_strat_t::draw_vertical( const int column, const position_t &from, const position_t &to,
									   std::vector<std::vector<char>> &map )
{
    //go down/up to next line
	if( from.get_y() < to.get_y() )
	{
		//go down
		for( int i = from.get_y(); i < to.get_y(); i++ )
		{
			map[i][column] = ' ';
		}
	}
	else
	{
		//go up
		for( int i = from.get_y(); i > to.get_y(); i-- )
		{
			map[i][column] = ' ';
		}
	}
}

void room_join_strat_t::draw_horizontal( const int row, const position_t &from, const position_t &to,
										 std::vector<std::vector<char>> &map )
{

	if( from.get_x() < to.get_x())
	{
		//go left
		for( int i = from.get_x(); i < to.get_x(); i++ )
		{
			map[row][i] = ' ';
		}
	}
	else //go right
	{
		for( int i = from.get_x(); i > to.get_x(); i-- )
		{
			map[row][i] = ' ';
		}
	}
}
