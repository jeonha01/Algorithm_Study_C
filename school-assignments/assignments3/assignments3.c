#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
#define shuffle 50000
int array[MAX];

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

    FILE *fp = fopen("C:/Algorithm_Study/school-assignments/assignments3/random_data.txt", "w");
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

    fp = fopen("C:/Algorithm_Study/school-assignments/assignments3/random_data.txt", "r");
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

    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = 0; j < MAX - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }

    fp = fopen("C:/Algorithm_Study/school-assignments/assignments3/sorted_data.txt", "w");
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