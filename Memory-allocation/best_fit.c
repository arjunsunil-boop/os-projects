#include<stdio.h>

void main()
{
    int bsize[10], psize[10], bno, pno, allocation[10] , i, j;
    
    printf("Enter no. of blocks: ");
    scanf("%d", &bno);
    printf("\nEnter size of each block: ");
    for(i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("\nEnter no. of processes: ");
    scanf("%d", &pno);
    printf("\nEnter size of each process: ");
    for(i = 0; i < pno; i++)
        scanf("%d", &psize[i]);
    for ( i = 0; i < pno; i++)
    {
        allocation[i] = -1;
    }
    
    for (i = 0; i < pno; i++)
    {
        int bestblock = -1;
        for (j = 0; j < bno; j++)
        {
            if (bsize[j] >= psize[i])
            {
                if (bestblock == -1)
                    bestblock = j;
                else if (bsize[bestblock] > bsize[j])
                    bestblock = j;
            }
        }
        if (bestblock != -1)
        {
            allocation[i] = bestblock;
            bsize[bestblock] = bsize[bestblock] - psize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < pno; i++)
    {
        printf(" %d\t\t%d\t\t", i+1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}