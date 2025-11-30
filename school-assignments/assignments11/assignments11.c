#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
int array[MAX];
int count = 0;

int main()
{
    srand(time(NULL));

    int ComRan = rand() % 1000 + 1;

    for (int i = 0; i < MAX; i++)
    {
        array[i] = i + 1;
    }

    while (1)
    {
        int ans;
        scanf("%d", &ans);
        count++;

        if (ans == ComRan)
        {
            break;
        }
        else if (array[ans + 1] > ComRan)
        {
            printf("다운\n");
            continue;
        }
        else
        {
            printf("업\n");
            continue;
        }
    }

    printf("%d번 만에 성공", count);
}