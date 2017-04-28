//
// Created by Patrick Mintram on 27/04/2017.
//

#include <iostream>
#include "utilities_t.h"

utilities_t* utilities_t::p = nullptr;

const utilities_t &utilities_t::get( void )
{
	if( !p )
	{
		p = new utilities_t();
	}

	return *p;
}

int utilities_t::get_rand_in_range( const int max ) const
{
	return rand()  % max;
}

void utilities_t::debug_print( const std::string &msg ) const
{
	//std::cout << msg << std::endl;
}
