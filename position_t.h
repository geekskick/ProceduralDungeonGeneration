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
			: m_x(x), m_y(y)
	{}

	int get_x( void ) const{ return m_x; }
	void set_x( int x ) { m_x = x; }
	int get_y( void ) const { return m_y; }
	void set_y( int y ){ m_y = y; }

protected:
	int m_x, m_y;
};


#endif //DUNGEON_POSITION_T_H
