#include <stdio.h>

int fibonacci(int num)
{
    if (num == 1 || num == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main()
{
    int num, result;

    printf("n값 입력: ");
    scanf("%d", &num);

    result = fibonacci(num);

    printf("n번째 피보나치 수열: %d", result);

    return 0;
}