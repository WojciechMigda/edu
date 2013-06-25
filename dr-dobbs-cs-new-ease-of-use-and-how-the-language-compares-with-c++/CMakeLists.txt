cmake_minimum_required( VERSION 2.8.3 )

# http://gcc.gnu.org/wiki/C11Status

add_definitions( -Wall -pedantic -ggdb -O0 )

set( CMAKE_REQUIRED_FLAGS -std=c1x )

##################################################

include( CheckTypeSize )
check_type_size( "_Bool" C11_BOOL )

##################################################

include( CheckCSourceCompiles )

check_c_source_compiles(
"
int b = alignof(double);
int main()
{
return 0;
}" HAVE_ALIGNOF )

##################################################

check_c_source_compiles(
"
int alignas(8) b;
int main()
{
return 0;
}" HAVE_ALIGNAS )

##################################################

check_c_source_compiles(
"
char a[] = u8\"żółw\";
int main()
{
return 0;
}" HAVE_U8_PREFIX )

##################################################

check_c_source_compiles(
"
char a[] = u\"żółw\";
int main()
{
return 0;
}" HAVE_U16_PREFIX )

##################################################

check_c_source_compiles(
"
char a[] = U\"żółw\";
int main()
{
return 0;
}" HAVE_U32_PREFIX )

##################################################

check_c_source_compiles(
"
void f1(char a){a ^= 128;}
void f2(int a){a ^= 47;}
int main()
{
int b = 123;
_Generic(b,
char: f1,
int: f2)(b);
return 0;
}" HAVE_GENERIC_SELECTION )

##################################################

check_c_source_compiles(
"
int main()
{
_Static_assert(sizeof (int) > 0, \"sizeof (int) <= 0 !!!\");
return 0;
}" HAVE_STATIC_ASSERT )

##################################################
