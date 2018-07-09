#include<stdio.h>
#include<stdlib.h>

void printArray(int **a);
void zeroArray(int **a);

int
main(void) {
    int a[2][2];
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            a[i][j] = rand() % 100;
        }
    }
    printArray((int**) a);
    zeroArray((int **) a);
    printArray((int **) a);

}

void
printArray(int **a) {
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

void
zeroArray(int **a) {
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            a[i][j] = 0;
        }
    }
}
