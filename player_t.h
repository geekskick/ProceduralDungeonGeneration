//
// Created by Patrick Mintram on 28/04/2017.
//

#ifndef DUNGEON_PLAYER_T_H
#define DUNGEON_PLAYER_T_H

#include "position_t.h"

class player_t
{
public:
	player_t( const char icon = 'O' )
			: m_location( {0, 0} ),
			  m_icon( icon ) { }

	const int get_x( void ) const { return m_location.get_x(); }

	const int get_y( void ) const { return m_location.get_y(); }

	position_t &position( void ) { return m_location; }

protected:
	position_t m_location;
	const char m_icon;
};

#endif //DUNGEON_PLAYER_T_H
