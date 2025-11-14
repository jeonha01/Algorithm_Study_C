#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int prices[1000000];

long long profit(int A[], int n)
{
    int max = 0;
    long long sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] > max)
            max = A[i];
        else
            sum += max - A[i];
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &prices[j]);
        }

        long long ans = profit(prices, n);
        printf("#%d %lld\n", i + 1, ans);
    }
}