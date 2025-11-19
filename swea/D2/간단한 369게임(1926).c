#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

char *conversion(int num)
{
    static char s[10];
    sprintf(s, "%d", num);
    int clap = 0;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '3' || s[i] == '6' || s[i] == '9')
        {
            clap++;
        }
    }

    if (clap > 0)
    {
        strcpy(s, "");
        for (int i = 0; i < clap; i++)
            strcat(s, "-");
    }

    return s;
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int tc = 1; tc <= N; tc++)
    {
        printf("%s ", conversion(tc));
    }
    return 0;
}