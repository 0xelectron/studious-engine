#include <stdio.h>
#include <stdlib.h>

int
main ()
{
    int i;
    int *p = (int *) malloc(sizeof(int) * 4);
    
    for (i = 0; i < 4; ++i)
        p[i] = i;
    for (i = 0; i < 4; ++i) {
        printf("Address of p[%d] = %p\n", i, &p[i]);
        printf("p[%d] = %d\n", i, p[i]);
    }
    return 0;
}
