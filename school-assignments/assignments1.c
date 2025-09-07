#include <stdio.h>

int main()
{
    int sum = 0;
    int studentNum;
    scanf("%d", &studentNum);

    int scholarship[studentNum];
    for (int i = 0; i < studentNum; i++)
    {
        scanf("%d", &scholarship[i]);
        sum += scholarship[i];
    };

    int totalScholarships;
    scanf("%d", &totalScholarships);

    int max = 0;

    while (sum > totalScholarships)
    {
        max = 0;

        for (int i = 0; i < studentNum; i++)
        {
            if (max <= scholarship[i])
            {
                max = scholarship[i];
            }
        }

        for (int i = 0; i < studentNum; i++)
        {
            if (max == scholarship[i])
            {
                scholarship[i] -= 1;
            }
        }

        sum = 0;
        for (int i = 0; i < studentNum; i++)
        {
            sum += scholarship[i];
        }
    }

    printf("%d\n", max - 1);

    return 0;
}