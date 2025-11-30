#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));      
    int ComRan = rand() % 1000 + 1;  
    int count = 0;
    int ans;

    while (1)
    {
        scanf("%d", &ans);
        count++;

        if (ans == ComRan)
        {
            printf("%d번 만에 성공\n", count);
            break;
        }
        else if (ans > ComRan)
        {
            printf("다운\n");
        }
        else
        {
            printf("업\n");
        }
    }
}
