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

	player_t p1;
	dungeon_t dung(dungeon_height,dungeon_width);

	//tests::room_overlap(dung);
	//tests::utils();

	for( int d = 0; d < num_dungeons; d++ )
	{
		std::cout << "Dungeon number " << d+1 << " is :" << std::endl;
		dung.clear_all_rooms();

		//generate dungeon
		for( int i = 0; i < max_rooms; i++ )
		{
			position_t room_top_left = {utilities_t::get().get_rand_in_range( dungeon_height ),
										utilities_t::get().get_rand_in_range( dungeon_width )};

			room_t temp_room( utilities_t::get().get_rand_in_range( max_room_dim ),
							  utilities_t::get().get_rand_in_range( max_room_dim ), room_top_left );

			dung.add_room( temp_room );
		}

		//Create player in first room
		dung.create_exit();
		p1.position() = dung.get_room(0).get_centre();
		dung.add_player(p1);
		dung.show();

		// move the player
		char inp;
		std::cin >> inp;

		while(inp != 'q')
		{
			switch(inp)
			{
				case 'a': //left
					p1.position().set_x(p1.get_x() - 1);
					break;
				case 's': //down
					p1.position().set_y(p1.get_y() + 1);
					break;
				case 'd': //right
					p1.position().set_x(p1.get_x() + 1);
					break;
				case 'w': //up
					p1.position().set_y(p1.get_y() - 1);
					break;
				default:
					break;
			}
			p1.position() = dung.update_player_position(p1.position());

			if( dung.player_has_found_exit() )
			{
				std::cout << "ESCAPE!" << std::endl;
				break;
			}
			dung.show();

			std::cin >> inp;
		}
	}


	return 0;
}