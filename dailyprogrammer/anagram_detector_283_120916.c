#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include<ctype.h>

void __attribute__ ((noreturn)) die(char *fmt, ...);
int isanagaram(const char *w1, const char *w2);
void count_letters(char *wc, const char *w);
void m_free(unsigned n, ...);

/*
 * dailyprogrammer challenge #238 Anagram Detector
 */
int
main()
{
        int read;
        size_t len = 0;
        char *line, *w1, *w2;
        line = w1 = w2 = NULL;

        while (getline(&line, &len, stdin) != -1) {
                if ((read = sscanf(line, " \"%m[^\"]\" ? \"%m[^\"]\"\n", &w1, &w2)) != 2) {
                        if (read == 1)
                                m_free(2, line, w1);
                        else
                                free(line);
                        die("[!] Invalid Input.\n");
                }

                if (isanagaram(w1, w2))
                        printf("\"%s\" is an anagram of \"%s\"\n", w1, w2);
                else
                        printf("\"%s\" is NOT an anagram of \"%s\"\n", w1, w2);

                m_free(2, w1, w2);
        }
        free(line);
}

/*
 * isanagaram: detects if w1 is an anagram of w2
 */
int isanagaram(const char *w1, const char *w2)
{
        int i;
        char w1_lcnt[26] = {0};
        char w2_lcnt[26] = {0};

        count_letters(w1_lcnt, w1);
        count_letters(w2_lcnt, w2);

        for (i = 0; i < 26; ++i)
                if (w1_lcnt[i] != w2_lcnt[i])
                        return 0;
        return 1;
}

/*
 * count_letters: counts occurences of letters in wc of word w.
 * ignores case, spaces, punctuation.
 */
void
count_letters(char *wc, const char *w)
{
        unsigned long i;
        char *s = strdup(w);
        /* char *p = s; */

        /* convert to lowercase */
        for (i = 0; i < strlen(s); ++i)
                s[i] = tolower(s[i]);

        /* valgrind is giving erros in this one liner. */
        /* any help will be appreciated. */

        /* for ( ; *p ; ++p) *p = tolower(*p); */
        /* p = s; */

        for (i = 0; i < strlen(s); ++i)
                if (s[i] >= 'a' && s[i] <= 'z')
                        wc[s[i]-97]++;

        free(s);
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

void
m_free(unsigned n, ...)
{
        unsigned i;
        va_list p_list;
        va_start(p_list, n);
        for (i = 0; i < n; ++i)
                free(va_arg(p_list, void *));
        va_end(p_list);
}