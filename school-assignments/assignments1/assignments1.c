#include <stdio.h>
#define MAX 10000

int main()
{
    int scholarship[MAX];
    int studentNum, totalScholarships;
    int max = 0, left = 0, right, mid, sum, answer = 0;

    scanf("%d", &studentNum);

    for (int i = 0; i < studentNum; i++)
    {
        scanf("%d", &scholarship[i]);
        if (max < scholarship[i])
            max = scholarship[i];
    }
    right = max;

    scanf("%d", &totalScholarships);

    while (left <= right)
    {
        sum = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < studentNum; i++)
            sum += (scholarship[i] > mid) ? mid : scholarship[i];
        
        if (sum <= totalScholarships)
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