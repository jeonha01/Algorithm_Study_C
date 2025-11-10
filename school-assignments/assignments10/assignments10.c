#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
#define shuffle 50000
int array[MAX];
void quickSort(int p, int r);
int partition(int p, int r);

void quickSort(int p, int r)
{
    if (p < r)
    {
        int q = partition(p, r);
        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}

int partition(int p, int r)
{
    int pivot = array[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[r];
    array[r] = array[i + 1];
    array[i + 1] = temp;

    return i + 1;
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

    FILE *fp = fopen("C:/Algorithm_Study/school-assignments/assignments10/random_data.txt", "w");
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

    fp = fopen("C:/Algorithm_Study/school-assignments/assignments10/random_data.txt", "r");
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

    quickSort(0, 99999);

    fp = fopen("C:/Algorithm_Study/school-assignments/assignments10/sorted_data.txt", "w");
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