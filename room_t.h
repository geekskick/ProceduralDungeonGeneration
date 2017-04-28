//
// Created by Patrick Mintram on 27/04/2017.
//

#ifndef DUNGEON_ROOM_T_H
#define DUNGEON_ROOM_T_H

#include "position_t.h"

class room_t
{
public:
	room_t(const int h, const int w)
			: m_h(h),m_w(w), m_location(0,0)
	{}

	room_t(const int h, const int w, const position_t p)
			: m_h(h), m_w(w), m_location(p)
	{}

	void set_location(const position_t p) { m_location = p; }
	const position_t& get_location( void ) const{ return m_location; }
	position_t& get_mutable_location( void ) { return m_location; }
	int get_top_edge( void ) const { return m_location.get_y(); }
	int get_bottom_edge( void ) const { return m_location.get_y() + m_h; }
	int get_left_edge( void ) const { return m_location.get_x(); }
	int get_right_edge( void ) const { return m_location.get_x() + m_w; }
	int get_height( void ) const { return m_h; }
	int get_width( void ) const { return  m_w; }
	position_t get_centre( void ) const { return { get_top_edge() + (m_h/2), get_left_edge() + (m_w/2) }; }
protected:
	const int m_h, m_w;
	position_t m_location;
};

#endif //DUNGEON_ROOM_T_H
