#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int K, N;
int array[10000];

int main()
{
    scanf("%d %d", &K, &N);

    long long sum;
    int left = 1;
    int right = 0;
    int mid, answer = 0;

    for (int i = 0; i < K; i++)
    {
        scanf("%d", &array[i]);
        if (right < array[i])
        {
            right = array[i];
        }
    }

    while (left <= right)
    {
        mid = (left + right) / 2;
        sum = 0;

        for (int i = 0; i < K; i++)
        {
            sum += array[i] / mid;
        }

        if (sum >= N)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}