#include <stdio.h>

#define opt 1

int
main ()
{
#if !opt
    printf("hello\n");
#else
    printf("uhoh!\n");
#endif
}
