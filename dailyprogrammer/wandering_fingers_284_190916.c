#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

/* len of alphabets */
#define LEN 26
/* Minimum word length */
#define MIN_WORD 5
/* get the len of array */
#define arr_len(x) (sizeof(x) / sizeof(x[0]))
/* get index of letters a-z */
#define indexof(x) ((int) x - (int) 'a')

/*
 * trienode: struct to represent a trie of letters a-z
 */
struct trienode
{
        struct trienode *child[LEN];
        /* if '1', marks end of word */
        int isword;
};

void __attribute__((noreturn)) usage(const char *prog);
void __attribute__((noreturn)) die(const char *fmt, ...);
static void load_dic(struct trienode *r, FILE *f);
static struct trienode *get_node(void);
static void insert(const char *w, struct trienode *r);
static void find_words(char *pre_str, char *sub_str, struct trienode *p);

/*
 * dailyprogrammer challenge #277 Wandering Fingers
 */
int
main(int argc, char *argv[])
{
        FILE *f;
        size_t l_len = 0;
        char *line, *s, *w, c[2];
        line = w = NULL;
        struct trienode *root, *p;

        if (argc != 2)
                usage(argv[0]);

        if ((f = fopen(argv[1], "r")) == NULL)
                die("[!] (in main) Cannot open file %s", argv[1]);

        root = get_node();

        load_dic(root, f);

        while (getline(&line, &l_len, stdin) != -1) {
                if ((sscanf(line, "%m[a-z]", &s)) != 1)
                        die("Invalid Input!");
                c[0] = s[0];
                c[1] = '\0';
                if ((p = root->child[indexof(c[0])])) {
                        find_words(c, &s[1], p);
                        printf("\n");
                }
                free(s);
        }

        fclose(f);
        free(line);
}


/*
 * usage: Print usage and exit.
 */
void usage(const char *prog)
{
        printf("Usage: %s [dictionary filename]\n", prog);
        exit(1);
}


/*
 * die: exit progarm printing error to stderr
 */
void
die(const char *fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        vprintf(fmt, ap);
        va_end(ap);
        exit(1);
}


/*
 * load_dic: load dictionary from f into r using
 * trie data structure.
 */
static void
load_dic(struct trienode *r, FILE *f)
{
        /* int read; */
        char *w = NULL;

        while (fscanf(f, "%m[^\r\n]\r", &w) > 0) {
                insert(w, r);
                free(w);
        }
}

/*
 * get_node: get a new node.
 */
static struct trienode *
get_node()
{
        struct trienode *p;
        unsigned long i;

        if ((p = malloc(sizeof(*p))) == NULL)
                die("[!] (in get_node) Unable to allocate memory for trinode.");

        p->isword = 0;
        for (i = 0; i < arr_len(p->child); ++i)
                p->child[i] = NULL;

        return p;
}

/*
 * insert: insert word w into trie r.
 */
void
insert(const char *w, struct trienode *r)
{
        struct trienode *p = r;
        char *s = strdup(w);
        int i;


        while (*s) {
                i = indexof(*s++);
                if (! p->child[i])
                        p->child[i] = get_node();
                p = p->child[i];
        }
        p->isword = 1;
}

/*
 * find_words: find and print matching words from dictionary
 * starting with pre_str including any letters from sub_str.
 */
void
find_words(char *pre_str, char *sub_str, struct trienode *p)
{
        int i, j, p_size, s_size;
        p_size = strlen(pre_str);
        s_size = strlen(sub_str);
        char pre[p_size + 2];

        if (p->isword && (s_size == 0) && p_size >= 5)
                printf("%s ", pre_str);

        if (s_size == 0)
                return;

        for (i = -1; i < s_size; ++i) {
                j = indexof(sub_str[i]);
                if (!p->child[j])
                        continue;

                strcpy(pre, pre_str);
                pre[p_size] = sub_str[i];
                pre[p_size + 1] = '\0';

                find_words(pre, &sub_str[i+1], p->child[j]);
        }

        return;
}    