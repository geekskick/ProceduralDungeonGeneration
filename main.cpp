#include <iostream>
#include <cmath>
#include <vector>

#include "dungeon_t.h"
#include "tests.h"
#include "utilities_t.h"

int main( )
{
	const int dungeon_width = 50;
	const int dungeon_height = 20;
	const int max_rooms = 20;
	const int max_room_dim = std::max(dungeon_height, dungeon_width)/4;
	const int num_dungeons = 5;

	dungeon_t dung(dungeon_height,dungeon_width);

	//tests::room_overlap(dung);
	//tests::utils();

	for( int d = 0; d < num_dungeons; d++ )
	{
		std::cout << "Dungeon number " << d+1 << " is :" << std::endl;
		dung.clear_all_rooms();
		for( int i = 0; i < max_rooms; i++ )
		{
			position_t room_top_left = {utilities_t::get().get_rand_in_range( dungeon_height ),
										utilities_t::get().get_rand_in_range( dungeon_width )};

			room_t temp_room( utilities_t::get().get_rand_in_range( max_room_dim ),
							  utilities_t::get().get_rand_in_range( max_room_dim ), room_top_left );

			dung.add_room( temp_room );
		}

		dung.show();
	}


	return 0;
}