cmake_minimum_required( VERSION 2.8.3 )

project( counted_ptr )

add_definitions( -O0 -ggdb -std=c++98 -Wall -pedantic )

################################################################################

add_executable( test src/test.cpp )
