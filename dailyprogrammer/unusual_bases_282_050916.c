#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#define DEF_SIZE 50

long *genfibonacci(long n);
long fibtodec(char *s);
char *dectofib(long n);
void __attribute__ ((noreturn)) die(char *fmt, ...);

int
main()
{
        size_t MAXLINE = 200;
        long *fibarr;
        char *line, *string, type[2];

        if ((line = (char *) malloc((MAXLINE + 1) * sizeof(*line))) == NULL)
                die("[!](main) failed to allocate memory.\n");

        if ((string = (char *) malloc((MAXLINE + 1) * sizeof(*string))) == NULL)
                die("[!](main) failed to allocate memory\n");


        fibarr = genfibonacci(DEF_SIZE);

        while (getline(&line, &MAXLINE, stdin) > 0) {

                if (sscanf(line, "%2c %s", type, string) != 2)
                        die("[!](main) Invalid input\n");

                if (strncmp(type, "10", 2) == 0)
                        printf("%s\n", dectofib(atoi(string)));

                else if (strncmp(type, "F", 1) == 0)
                        printf("%ld\n", fibtodec(string));
                else
                        die("[!](main) Invalied input\n");
        }
        return 0;
}

/*
 * genfibonnaci: generate atleast n fibonacci numbers
 * and return the array.
 */
long *
genfibonacci(long n)
{
        static long *fibarr;
        long *p;

        if (fibarr != NULL && *(fibarr - 1) >= n)
                return fibarr;

        if (!fibarr) {
                if ((fibarr = (long *) malloc((n + 1) * sizeof(*fibarr))) == NULL)
                        die("[!](genfibonnaci) failed to allocate memory\n");
                *fibarr++ = n;    /* stash the size of array */
                p = fibarr;
                *p++ = 1;
                --n;
                *p++ = 1;
                --n;

        } else if (*(fibarr - 1) < n) {
                int prev_size = *(fibarr - 1);
                if ((fibarr = realloc(fibarr - 1, (n + 1) * sizeof(*fibarr))) == NULL)
                        die("[!](genfibonnaci)failed to expand array\n");
                *fibarr++ = n;    /* stash the size of array */
                p = fibarr + prev_size + 1;
                n -= prev_size;
        }

        while (n-- > 0) {
                *p = *(p - 1) + *(p - 2);
                ++p;
        }

        return fibarr;
}

/*
 * fibtodec: convert string s in base fibonnaci to decimal(10).
 * ex: (13, 8, 5, 3, 2, 1, 1)1010010 = 19 'deciaml(10)'
 */
long
fibtodec(char *s)
{
        unsigned n = strlen(s);
        int i;
        long ans, *fibarr;
        ans = 0;
        fibarr = genfibonacci(n);

        for (i = n - 1; i >= 0; --i, s++)
                if (*s == '1')
                        ans += fibarr[i];
                else if (*s != '0')
                        die("[!](fibtodec) Invalid input\n");
        return ans;
}

/*
 * dectofib: convert number n in decimal(10) to base fibonnaci.
 * ex: 19 = (13, 8, 5, 3, 2, 1, 1)1010010 'Base Fib'
 */
char *
dectofib(long n)
{
        char *s, *p;
        int start, i, flag;
        long *fibarr;

        if ((p = s = malloc(sizeof(DEF_SIZE) * sizeof(*s))) == NULL)
                die("[!](dectofib) failed to allocate memory");

        fibarr = genfibonacci(DEF_SIZE);

        start = *(fibarr - 1) - 1;
        flag = 0;
        while (n > 0)
                for (i = start; i >= 0; --i) {
                        if (fibarr[i] <= n) {
                                n -= fibarr[i];
                                start = i - 1;
                                *p++ = '1';
                                flag = 1;
                                break;
                        }
                        if (flag)
                                *p++ = '0';
                }
        while (start-- >= 0)
                *p++ = '0';
        *p = '\n';

        return s;
}

/*
 * die: exit progarm printing error to stderr
 */
void
die(char *fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        vprintf(fmt, ap);
        va_end(ap);
        exit(1);
}