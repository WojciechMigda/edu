#include <stdio.h>

int main()
{
    printf("__STDC__ %u\n", __STDC__);
#ifdef __STDC_VERSION__
    printf("__STDC_VERSION__ %u\n", __STDC_VERSION__);
#else
    puts("No __STDC_VERSION__");
#endif

    printf("__STDC_ISO_10646__ %u\n", __STDC_ISO_10646__);

#ifdef __STDC_MB_MIGHT_NEQ_WC__
    printf("__STDC_MB_MIGHT_NEQ_WC__ %u\n", __STDC_MB_MIGHT_NEQ_WC__);
#else
    puts("No __STDC_MB_MIGHT_NEQ_WC__");
#endif

#ifdef __STDC_UTF_16__
    printf("__STDC_UTF_16__ %u\n", __STDC_UTF_16__);
#else
    puts("No __STDC_UTF_16__");
#endif

#ifdef __STDC_UTF_32__
    printf("__STDC_UTF_32__ %u\n", __STDC_UTF_32__);
#else
    puts("No __STDC_UTF_32__");
#endif

#ifdef __STDC_ANALYZABLE__
    printf("__STDC_ANALYZABLE__ %u\n", __STDC_ANALYZABLE__);
#else
    puts("No __STDC_ANALYZABLE__");
#endif

#ifdef __STDC_IEC_559__
    printf("__STDC_IEC_559__ %u\n", __STDC_IEC_559__);
#else
    puts("No __STDC_IEC_559__");
#endif

#ifdef __STDC_IEC_559_COMPLEX__
    printf("__STDC_IEC_559_COMPLEX__ %u\n", __STDC_IEC_559_COMPLEX__);
#else
    puts("No __STDC_IEC_559_COMPLEX__");
#endif

#ifdef __STDC_LIB_EXT1__
    printf("__STDC_LIB_EXT1__ %u\n", __STDC_LIB_EXT1__);
#else
    puts("No __STDC_LIB_EXT1__");
#endif

#ifdef __STDC_NO_ATOMICS__
    printf("__STDC_NO_ATOMICS__ %u\n", __STDC_NO_ATOMICS__);
#else
    puts("No __STDC_NO_ATOMICS__");
#endif

#ifdef __STDC_NO_COMPLEX__
    printf("__STDC_NO_COMPLEX__ %u\n", __STDC_NO_COMPLEX__);
#else
    puts("No __STDC_NO_COMPLEX__");
#endif

#ifdef __STDC_NO_THREADS__
    printf("__STDC_NO_THREADS__ %u\n", __STDC_NO_THREADS__);
#else
    puts("No __STDC_NO_THREADS__");
#endif

#ifdef __STDC_NO_VLA__
    printf("__STDC_NO_VLA__ %u\n", __STDC_NO_VLA__);
#else
    puts("No __STDC_NO_VLA__");
#endif

    return 0;
}
