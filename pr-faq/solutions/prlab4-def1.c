#include <stdio.h>
#include <string.h>
#include <ctype.h>

char words[11][128];

int revstrcmp(char *a, char *b)
{
    int l1 = strlen(a), l2 = strlen(b);
    if (l1 != l2) return 0;

    for (int i = 0; i < l1 / 2 + 1; i++) {
        if (tolower(a[l1 - i - 1]) != tolower(b[i])) return 0;
    }

    return 1;
}

int mystrcmp(char *a, char *b)
{
    int l1 = strlen(a), l2 = strlen(b);
    if (l1 != l2) return 0;

    for (int i = 0; i < l1 / 2 + 1; i++) {
        if (tolower(a[i]) != tolower(b[i])) return 0;
    }

    return 1;
}

int mycmp(char *a, char *b)
{
    return mystrcmp(a, b) || revstrcmp(a, b);
}

int main()
{
    int len = 0;

    for (int i = 0; i < 11; i++) {
        int res = scanf("%s", words[i]);
        if (res == 0)
            break;

        len++;
    }

    char *needle = words[len - 1];
    int n = len - 1;

    for (int i = 0; i < n; i++) {
        if (mycmp(words[i], needle)) {
            puts("1");
            return 0;
        }
    }

    puts("0");
    return 0;
}