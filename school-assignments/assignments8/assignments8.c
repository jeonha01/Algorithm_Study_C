#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
#define shuffle 50000
int array[MAX];
int merge(int p, int q, int r);

int mergeSort(int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(p, q);
        mergeSort(q + 1, r);
        merge(p, q, r);
    }
    return 0;
}

int merge(int p, int q, int r)
{
    int t = 0;
    int i = p;
    int j = q + 1;
    int tmp[MAX];

    while (i <= q && j <= r)
    {
        if (array[i] < array[j])
        {
            tmp[t] = array[i];
            t++;
            i++;
        }
        else if (array[j] < array[i])
        {
            tmp[t] = array[j];
            t++;
            j++;
        }
    }

    if (i > q)
    {
        while (j <= r && t <= r)
        {
            tmp[t] = array[j];
            t++;
            j++;
        }
    }
    else if (j > r)
    {
        while (i <= q && t <= r)
        {
            tmp[t] = array[i];
            t++;
            i++;
        }
    }

    for (int k = 0; k < t; k++)
    {
        array[p + k] = tmp[k];
    }

    return 0;
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

    FILE *fp = fopen("C:/Algorithm_Study/school-assignments/assignments8/random_data.txt", "w");
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

    fp = fopen("C:/Algorithm_Study/school-assignments/assignments8/random_data.txt", "r");
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

    mergeSort(0, 99999);

    fp = fopen("C:/Algorithm_Study/school-assignments/assignments8/sorted_data.txt", "w");
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