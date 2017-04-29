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

	char get_icon( void ) const { return m_icon; }
	position_t &position( void ) { return m_location; }
	const position_t &position( void ) const { return m_location; }

	player_t(const player_t& p)
			: m_location(p.position()),
			  m_icon(p.get_icon())  { }
protected:
	position_t m_location;
	char m_icon;

};


#endif //DUNGEON_PLAYER_T_H
