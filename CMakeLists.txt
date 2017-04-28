cmake_minimum_required(VERSION 3.7)
project(Dungeon)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp room_t.cpp room_t.h position_t.cpp position_t.h dungeon_t.cpp dungeon_t.h tests.cpp tests.h utilities_t.cpp utilities_t.h room_join_strat_t.cpp room_join_strat_t.h)
add_executable(Dungeon ${SOURCE_FILES})