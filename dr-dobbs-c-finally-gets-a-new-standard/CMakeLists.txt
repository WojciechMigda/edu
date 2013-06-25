cmake_minimum_required( VERSION 2.8.3 )

# http://gcc.gnu.org/wiki/C11Status

add_definitions( -Wall -pedantic -ggdb -O0 )

set( CMAKE_REQUIRED_FLAGS -std=c1x )


include( CheckIncludeFiles )
check_include_files( threads.h HAVE_THREADS_H )
