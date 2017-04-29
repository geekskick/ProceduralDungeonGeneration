//
// Created by Patrick Mintram on 27/04/2017.
//

#ifndef DUNGEON_POSITION_T_H
#define DUNGEON_POSITION_T_H

#include <utility>

class position_t: public std::pair<int, int>
{
public:
	position_t(const int y, const int x)
			: std::pair<int, int>(y, x)
	{}

	int get_x( void ) const{ return second; }
	void set_x( int x ) { second = x; }
	int get_y( void ) const { return first; }
	void set_y( int y ){ first = y; }

protected:

};


#endif //DUNGEON_POSITION_T_H
