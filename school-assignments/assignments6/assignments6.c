#include <stdio.h>
long long index[10000] = {0};

long long fibonacci(int num)
{
    if (num <= 1)
        return num;
    if (index[num] != 0)
        return index[num];
    index[num] = fibonacci(num - 1) + fibonacci(num - 2);
    return index[num];
}

int main()
{
    int num;
    long long result;

    printf("n값 입력: ");
    scanf("%d", &num);

    result = fibonacci(num);

    printf("n번째 피보나치 수열: %lld", result);

    return 0;
}