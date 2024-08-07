#include <stdio.h>
void main()
{
    int i, j, n, f, page[20], pf = 0, k = 0, frame[10];
    printf("Enter no of pages:");
    scanf("%d", &n);
    printf("\nEnter the page sequence:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &page[i]);
    }
    printf("\nEnter the number of frames:");
    scanf("%d", &f);
    for (j = 0; j < f; j++)
    {
        frame[j] = -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < f; j++)
        {
            if (frame[j] == page[i])
            {
                break;
            }
        }
        if (j == f)
        {
            frame[k] = page[i];
            k++;
            pf++;
        }
        for (j = 0; j < f; j++)
        {
            printf("%d\t", frame[j]);
        }
        printf("\tTotal page faults:%d\n", pf);
        if (k == f)
        {
            k = 0;
        }
    }
    printf("No. of page hits:%d\n", n - pf);
}