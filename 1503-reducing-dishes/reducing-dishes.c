#include <stdlib.h>

int cmp(const void *x, const void *y)
{
    return (*(int *)x - *(int *)y);
}

int maxSatisfaction(int* satisfaction, int satisfactionSize)
{
    qsort(satisfaction, satisfactionSize, sizeof(int), cmp);

    int running = 0;
    int answer = 0;

    for (int i = satisfactionSize - 1; i >= 0; i--)
    {
        running += satisfaction[i];

        if (running <= 0)
            break;

        answer += running;
    }

    return answer;
}