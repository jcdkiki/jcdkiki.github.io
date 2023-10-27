#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NMAX 10

void solve_int()
{
    int arr[NMAX];
    int n = 0;

    for (int i = 0; i < NMAX; i++) {
        int res = scanf("%d", &arr[i]);
        if (res == 0)
            break;

        n++;
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[res])
            res = i;
    }

    printf("%d\n", res);
}

void solve_float()
{
    float arr[NMAX];
    int n = 0;

    for (int i = 0; i < NMAX; i++) {
        int res = scanf("%f", &arr[i]);
        if (res == 0)
            break;

        n++;
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[res])
            res = i;
    }

    printf("%d\n", res);
}

void solve_str()
{
    char arr[NMAX][128];
    int n = 0;

    for (int i = 0; i < NMAX; i++) {
        int res = scanf("%s", arr[i]);
        if (res == 0)
            break;

        n++;
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
        if (strlen(arr[i]) >= strlen(arr[res]))
            res = i;
    }

    printf("%d\n", res);
}

void solve(int type)
{
    switch (type) {
        case 1:
            solve_int();
            break;
        case 2:
            solve_float();
            break;
        case 3:
            solve_str();
    }
}

int main()
{
    int type;
    scanf("%d", &type);
    solve(type);
}