cmake_minimum_required( VERSION 2.8.3 )

set( CMAKE_ECLIPSE_VERSION 3.7 )
set( _ECLIPSE_VERSION 3.7 )

add_definitions( -O0 -ggdb -std=c++98 )

################################################################################

add_executable( test test.cpp )
