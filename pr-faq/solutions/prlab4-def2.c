#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct word {
    char str[128];
    int ord;
} word;

word words[11];

int comparator(const void *a, const void *b)
{
    word *wa = (word*)a;
    word *wb = (word*)b;
    return strcmp(wa->str, wb->str);
}

int main()
{
    int len = 0;

    for (int i = 0; i < 11; i++) {
        int res = scanf("%s", words[i].str);
        if (res == 0)
            break;

        len++;
    }

    word needle = words[len - 1];
    int n = len - 1;

    for (int i = 0; i < n; i++) {
        words[i].ord = i;
    }


    qsort(words, n, sizeof(word), comparator);

    word *res = bsearch(&needle, words, n, sizeof(word), comparator);
    if (res == NULL)
        puts("-1");
    else
        printf("%d\n", res->ord);
    
    return 0;
}