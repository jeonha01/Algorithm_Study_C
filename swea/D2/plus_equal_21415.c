#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int calculate(int a, int b, int n)
{
    int count = 0;
    int small, large = 0;

    if (a >= b)
    {
        small = b;
        large = a;
    }
    else
    {
        small = a;
        large = b;
    }

    do
    {
        if (small > large)
        {
            int temp = 0;

            temp = small;
            small = large;
            large = temp;
        }

        ++count;
        small += large;
    } while (small <= n);

    return count;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        int A, B, N;
        scanf("%d %d %d", &A, &B, &N);

        int ans = calculate(A, B, N);
        printf("%d\n", ans);
    }
    return 0;
}