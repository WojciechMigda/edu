#include <cassert>
#include "counted_ptr.hpp"

void ctor__type__default_deleter(void)
{
    int     *raw;

    raw = new int;
    counted_ptr<int>    sp1;

    raw = new int;
    counted_ptr<int>    sp2 = counted_ptr<int>(raw);

    (void)sp1;
    (void)sp2;
}

void custom_deleter(void * ptr)
{
    delete((int *)ptr);
}

void ctor__type__custom_deleter(void)
{
    int     *raw = new int;

    counted_ptr<int, &custom_deleter>    sp2(raw);
}

void get_deleter(void)
{
    int     *raw;

    raw = new int;
    counted_ptr<int>    sp1(raw);
    assert(counted_ptr<int>::get_deleter(sp1) == &operator delete);

    raw = new int;
    counted_ptr<int, &custom_deleter>    sp2(raw);
    assert((counted_ptr<int, &custom_deleter>::get_deleter(sp2)) == &custom_deleter);
}

int main()
{
    return 0;
}
