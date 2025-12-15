#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int N;
long long M;

int main()
{
    int array[10000];
    scanf("%d", &N);

    long long left = 0;
    long long right = 0;
    long long sum, answer = 0, mid;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
        if (right < array[i])
            right = array[i];
    }

    scanf("%lld", &M);

    while (left <= right)
    {
        sum = 0;
        mid = (left + right) / 2;

        for (int i = 0; i < N; i++)
        {
            sum += (array[i] < mid) ? array[i] : mid;
        }

        if (sum <= M)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("%lld\n", answer);
    return 0;
}