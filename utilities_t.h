//
// Created by Patrick Mintram on 27/04/2017.
//

#ifndef DUNGEON_UTILITIES_T_H
#define DUNGEON_UTILITIES_T_H


#include <ctime>
#include <cstdlib>
#include <string>

class utilities_t
{

public:
	static const utilities_t& get( void );
	int get_rand_in_range( const int max ) const;
	void debug_print( const std::string& msg ) const;

private:
	static utilities_t *p;
	utilities_t( void )
	{
		srand(time( nullptr ));
	}

};


#endif //DUNGEON_UTILITIES_T_H
