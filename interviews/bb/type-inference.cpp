#include <stdio.h>

int main()
{
    char    z = 'a';

    auto c = z++;
    printf("sizeof (z++) = %d\n", sizeof (c));

    auto n1 = z + 2;
    printf("sizeof (z + 2) = %d\n", sizeof (n1));

    auto n2 = 2 + z;
    printf("sizeof (2 + z) = %d\n", sizeof (n2));

//    short x = 1;
    auto n3 = z + (short)1;
//    auto n3 = z + x;
    printf("sizeof (z + (short)1) = %d\n", sizeof (n3));

    auto n4 = z + (long long)1;
    printf("sizeof (z + (long long)1) = %d\n", sizeof (n4));

    return 0;
}
