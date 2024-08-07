#include <stdio.h>
void main()
{

    int PID[20], AT[20], CT[20], BT[20], TAT[20], WT[20];
    int temp, n, i, j, k;
    int exec[20];

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
        exec[i] = 0;
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

    int currentTime = 0;
    int completed = 0;

    currentTime = AT[0] + BT[0];
    CT[0] = currentTime;
    TAT[0] = CT[0] - AT[0];
    WT[0] = TAT[0] - BT[0];
    exec[0] = 1;
    completed++;

    while (completed < n)
    {

        int nextProcessIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (exec[i] == 0 && AT[i] <= currentTime)
            {
                if (nextProcessIndex == -1 || BT[i] < BT[nextProcessIndex])
                {
                    nextProcessIndex = i;
                }
            }
        }

        if (nextProcessIndex == -1)
        {
            currentTime++;
            continue;
        }

        currentTime += BT[nextProcessIndex];
        CT[nextProcessIndex] = currentTime;
        TAT[nextProcessIndex] = CT[nextProcessIndex] - AT[nextProcessIndex];
        WT[nextProcessIndex] = TAT[nextProcessIndex] - BT[nextProcessIndex];
        exec[nextProcessIndex] = 1;
        completed++;
    }

    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", PID[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
    float totalTAT = 0, totalWT = 0;

    float avgTAT = 0;
    float avgWT = 0;
    for (int i = 0; i < n; i++)
    {
        totalTAT = totalTAT + TAT[i];
        totalWT = totalWT + WT[i];
    }
    avgTAT = totalTAT / n;
    avgWT = totalWT / n;
    printf("Average Turnaround Time: %f\n", avgTAT);
    printf("Average Waiting Time: %f\n", avgWT);
}