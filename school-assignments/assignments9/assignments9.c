#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
#define shuffle 50000
int array[MAX];
int heapArray[MAX + 1];
int buildHeap(int n);
int heapify();
int maxn = 0;

int heapSort()
{
    for (int i = 0; i < MAX; i++)
    {
        buildHeap(array[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        array[i] = heapify();
    }
}

int heapify() {
    int r = heapArray[1];
    heapArray[1] = heapArray[maxn--];
    int parent = 1;
    int child;

    while (parent * 2 <= maxn) {
        int left = parent * 2;
        int right = parent * 2 + 1;

        if (right <= maxn && heapArray[right] < heapArray[left])
            child = right;
        else
            child = left;

        if (heapArray[parent] > heapArray[child]) {
            int temp = heapArray[parent];
            heapArray[parent] = heapArray[child];
            heapArray[child] = temp;
            parent = child;
        } else {
            break;
        }
    }

    return r;
}

int buildHeap(int n)
{
    heapArray[++maxn] = n;
    int child = maxn;
    int parent = maxn / 2;

    while (parent > 0)
    {
        if (heapArray[child] < heapArray[parent])
        {
            int temp = heapArray[child];
            heapArray[child] = heapArray[parent];
            heapArray[parent] = temp;
            child = parent;
            parent = child / 2;
        }
        else
            break;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < MAX; i++)
    {
        array[i] = i + 1;
    }

    for (int i = 0; i < shuffle; i++)
    {
        int rand_large_a = (rand() << 15) | rand();
        rand_large_a = rand_large_a % MAX;

        int rand_large_b = (rand() << 15) | rand();
        rand_large_b = rand_large_b % MAX;

        int a = rand_large_a;
        int b = rand_large_b;

        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }

    FILE *fp = fopen("C:/Algorithm_Study/school-assignments/assignments9/random_data.txt", "w");
    if (fp == NULL)
    {
        perror("파일 열기 실패");
        return 1;
    }

    for (int i = 0; i < MAX; i++)
    {
        fprintf(fp, "%d\n", array[i]);
    }

    fclose(fp);

    fp = fopen("C:/Algorithm_Study/school-assignments/assignments9/random_data.txt", "r");
    if (fp == NULL)
    {
        perror("파일 열기 실패 (읽기)");
        return 1;
    }
    for (int i = 0; i < MAX; i++)
    {
        if (fscanf(fp, "%d", &array[i]) != 1)
        {
            fprintf(stderr, "파일에서 숫자 읽기 실패\n");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    heapSort();

    fp = fopen("C:/Algorithm_Study/school-assignments/assignments9/sorted_data.txt", "w");
    if (fp == NULL)
    {
        perror("파일 열기 실패 (정렬 결과 저장)");
        return 1;
    }
    for (int i = 0; i < MAX; i++)
    {
        fprintf(fp, "%d\n", array[i]);
    }
    fclose(fp);

    return 0;
}