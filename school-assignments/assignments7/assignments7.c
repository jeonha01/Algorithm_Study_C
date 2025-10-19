#include <stdio.h>
#include <time.h>

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

long long index[100] = {0};
long long memo_fibonacci(int num)
{
    if (num <= 1)
        return num;
    if (index[num] != 0)
        return index[num];
    index[num] = memo_fibonacci(num - 1) + memo_fibonacci(num - 2);
    return index[num];
}

int main() {
    int test_cases[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        int n = test_cases[i];
        clock_t start, end;

      
        start = clock();
        fibonacci(n);
        end = clock();
        printf("재귀 n=%d: %.5lf초\n", n, (double)(end - start) / CLOCKS_PER_SEC);

      
        start = clock();
        memo_fibonacci(n);
        end = clock();
        printf("메모 n=%d: %.5lf초\n", n, (double)(end - start) / CLOCKS_PER_SEC);
    }
    return 0;
}