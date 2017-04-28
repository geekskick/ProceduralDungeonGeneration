//
// Created by Patrick Mintram on 27/04/2017.
//

#include "tests.h"
#include "utilities_t.h"

void tests::room_overlap( dungeon_t &dung )
{
	// should be added
	room_t sec_room(3, 5, { 3,0 });
	std::cout << "There are now " <<dung.add_room(sec_room)<< " rooms " << std::endl;
	dung.show();
	position_t c = sec_room.get_centre();
	//std::cout << "The room's centre is at " << c.get_y() << ", " << c.get_x() << std::endl;
	//dung.join_rooms();

	room_t newroom(3,5, {10, 10});
	std::cout << "There are now " << dung.add_room(newroom) << " rooms " << std::endl;
	dung.show();
	c = newroom.get_centre();
	//std::cout << "The room's centre is at " << c.get_y() << ", " << c.get_x() << std::endl;
	//dung.join_rooms();


	// should fail
	room_t third_room(3, 5, { 0,7 });
	std::cout << "There are now " <<dung.add_room(third_room)<< " rooms " << std::endl;
	dung.show();
	c = third_room.get_centre();
	//std::cout << "The room's centre is at " << c.get_y() << ", " << c.get_x() << std::endl;
	//dung.join_rooms();

	//should fail
	room_t fourth_room(2,1,{2,0});
	std::cout << "There are now " <<dung.add_room(fourth_room)<< " rooms " << std::endl;
	dung.show();
	c = fourth_room.get_centre();
	//std::cout << "The room's centre is at " << c.get_y() << ", " << c.get_x() << std::endl;
	//dung.join_rooms();

	//should pass
	room_t fifth_room(5,5,{10,30});
	std::cout << "There are now " <<dung.add_room(fifth_room)<< " rooms " << std::endl;
	dung.show();
	c = fifth_room.get_centre();
	//std::cout << "The room's centre is at " << c.get_y() << ", " << c.get_x() << std::endl;
	//dung.join_rooms();

	//should pass
	room_t six_room(1,2,{18,30});
	std::cout << "There are now " <<dung.add_room(six_room)<< " rooms " << std::endl;
	dung.show();
	c = six_room.get_centre();
	//std::cout << "The room's centre is at " << c.get_y() << ", " << c.get_x() << std::endl;
	//dung.join_rooms();

	//should pass
	room_t sev_room(1,2,{17,30});
	std::cout << "There are now " <<dung.add_room(sev_room)<< " rooms " << std::endl;
	dung.show();
	c = sev_room.get_centre();
	//std::cout << "The room's centre is at " << c.get_y() << ", " << c.get_x() << std::endl;

	room_t e_room(3,3,{0, 45});
	std::cout << "There are now " <<dung.add_room(e_room)<< " rooms " << std::endl;
	dung.show();

	room_t n_room(3,3,{6, 15});
	std::cout << "There are now " <<dung.add_room(n_room)<< " rooms " << std::endl;
	dung.show();

	dung.join_rooms();
	dung.show();


	dung.clear_all_rooms();
	//dung.show();

}

void tests::utils( void )
{
	std::cout << "Testing the utilities" << std::endl;
	const int max = 10;
	bool passed = true;
	for( int i = 0; i < max * 10; i++ )
	{
		const int r = utilities_t::get().get_rand_in_range(max);
		if( r >= max )
		{
			std:: cout << "Random number [" << r << "]  is not in range " << max << std::endl;
			passed = false;
			break;
		}
		else
		{
			std:: cout << "Random number [" << r << "]  is in range " << max << std::endl;
		}
	}
	if( passed )
	{
		std::cout << "Random numbers are correct in the sample" << std::endl;
	}
}
