#include <stdio.h>
#include <stddef.h>
#include <string.h>

void substr_rev(char * const istr, const size_t in_endpos)
{
    size_t  back_idx;
    size_t  front_idx;

    for (front_idx = 0, back_idx = in_endpos; front_idx < back_idx; ++front_idx, --back_idx)
    {
        char    temp = istr[back_idx];

        istr[back_idx] = istr[front_idx];
        istr[front_idx] = temp;
    }
}

void str_rev(char * const istr)
{
    size_t      full_len = strlen(istr);
    char *      curr_ptr = istr;
    char *      next_ptr;

    if (full_len < 2)
    {
        return;
    }

    /* reverse the string itself */
    substr_rev(istr, full_len - 1);

    /* reverse each word until last white space */
    while (next_ptr = strchr(curr_ptr, ' '))
    {
        if (next_ptr - curr_ptr > 1)
        {
            substr_rev(curr_ptr, next_ptr - curr_ptr - 1);
        }
        curr_ptr = next_ptr + 1;
    }

    /* reverse last word until null-terminator */
    next_ptr = strchr(curr_ptr, 0x00);
    if (next_ptr - curr_ptr > 1)
    {
        substr_rev(curr_ptr, next_ptr - curr_ptr - 1);
    }
}

int main()
{
    char    t1[] = "Hello world I am pleased to see you!";
    char    t2[] = "  Hello world I am pleased to see you!";
    char    t3[] = "Hello world I am pleased to see you!  ";
    char    t4[] = "    Hello world I am pleased to see you!  ";
    char    t5[] = "";
    char    t6[] = " ";
    char    t7[] = "   ";
    char    t8[] = "A";

    str_rev(t1);
    printf("[%s]\n", t1);

    str_rev(t2);
    printf("[%s]\n", t2);

    str_rev(t3);
    printf("[%s]\n", t3);

    str_rev(t4);
    printf("[%s]\n", t4);

    str_rev(t5);
    printf("[%s]\n", t5);

    str_rev(t6);
    printf("[%s]\n", t6);

    str_rev(t7);
    printf("[%s]\n", t7);

    str_rev(t8);
    printf("[%s]\n", t8);

    return 0;
}
