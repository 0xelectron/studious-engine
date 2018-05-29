#include <stdio.h>
#include <stdlib.h>

int get_ndigits_of_type(char *string, size_t len, char c);

int
main ()
{
    int count;
    char *string;
    size_t len, nread;

    string = NULL;
    len = nread = 0;
    count = 0;

    do {
        printf("Enter the number: ");
    } while ((nread = getline(&string, &len, stdin)) == -1);

    count = get_ndigits_of_type(string, nread, '7');
    if (count == -1)
        printf("[!] NaN\n");
    else
        printf("Number of digits in an integer that contain seven in base 10: %d\n", count);

    free(string);

    return 0;
}

int
get_ndigits_of_type (char *string, size_t len, char c)
{
    int i, count;

    if (string == NULL || (c < 48 || c > 57))
        return -1;

    for (i = count = 0; i < len - 1; ++i) {
        /* Make sure it's a digit */
        if (string[i] < 48 || string[i] > 57)
            return -1;

        if (string[i] == c)
            count++;
    }

    return count;
}