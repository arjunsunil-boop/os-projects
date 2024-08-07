#include <stdio.h>
void main()
{

    int PID[20], AT[20], CT[20], BT[20], TAT[20], WT[20];
    int temp, n, i, j, k;
    printf("Enter the no: of process:\n");
    scanf("%d", &n);
    printf("Enter the Process ID:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &PID[i]);
    }
    printf("Enter the Arrival time of the process:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &AT[i]);
    }
    printf("Enter the Burst Time:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &BT[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (AT[j] > AT[j + 1])
            {

                temp = PID[j];
                PID[j] = PID[j + 1];
                PID[j + 1] = temp;

                temp = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp;

                temp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp;
            }
        }
    }

    CT[0] = AT[0] + BT[0];
    for (i = 1; i < n; i++)
    {
        CT[i] = CT[i - 1] + BT[i];
    }

    for (i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
    }

    for (i = 0; i < n; i++)
    {
        WT[i] = TAT[i] - BT[i];
    }

    float totalTAT = 0.0;
    float totalWT = 0.0;
    float avgTAT;
    float avgWT;

    for (i = 0; i < n; i++)
    {
        totalTAT = totalTAT + TAT[i];
    }
    for (i = 0; i < n; i++)
    {
        totalWT = totalWT + WT[i];
    }

    avgTAT = totalTAT / n;
    avgWT = totalWT / n;

    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", PID[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    printf("Average Turnaround Time: %f\n", avgTAT);
    printf("Average Waiting Time: %f\n", avgWT);
}