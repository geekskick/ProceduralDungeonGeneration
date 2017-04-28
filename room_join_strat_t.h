//
// Created by Patrick Mintram on 28/04/2017.
//

#ifndef DUNGEON_ROOM_JOIN_STRAT_T_H
#define DUNGEON_ROOM_JOIN_STRAT_T_H

#include <vector>
#include <string>
#include "room_t.h"

class room_join_strat_t
{
public:
	enum relative_direction_t{ N,E,S,W };
	room_join_strat_t( void ) :m_dir_strs({ "North", "East", "South", "West" }){}
	virtual ~room_join_strat_t( ) {}
	virtual void join_rooms(const room_t& from, const room_t& to, std::vector<std::vector<char>>& map) = 0;
protected:
	const std::vector<std::string> m_dir_strs;
	std::string to_string(const relative_direction_t& r) { const std::string rc(m_dir_strs[r]); return rc; }
	relative_direction_t get_relative( const room_t& from, const room_t& to) const;
	void swap(position_t& a, position_t& b);
	void draw_vertical( const int column, const position_t& from, const position_t& to, std::vector<std::vector<char>>& map );
	void draw_horizontal( const int row, const position_t& from, const position_t& to, std::vector<std::vector<char>>& map );
};

class half_rjs: public room_join_strat_t
{
public:
	virtual void join_rooms(const room_t& from, const room_t& to, std::vector<std::vector<char>>& map);

protected:
	position_t get_half_way( const position_t& from, const position_t& to) const;
};

//the intent here is to have other ways of joining the rooms together than just finding a half way point

#endif //DUNGEON_ROOM_JOIN_STRAT_T_H
