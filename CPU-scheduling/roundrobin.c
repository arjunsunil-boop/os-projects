#include <stdio.h>

int main() {
    int n, tq;
    int bt[10];
    int initial_bt[10];
    int ct[10];
    int tat[10];
    int wt[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        initial_bt[i] = bt[i];
    }

   
    int curr_time = 0;
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (bt[i] > 0) {
                if (bt[i] <= tq) {
                    curr_time += bt[i];
                    bt[i] = 0;
                    ct[i] = curr_time;
                } else {
                    curr_time += tq;
                    bt[i] -= tq;
                }

                if (bt[i] == 0) {
                    completed++;
                }
            }
        }
    }

  
    int total_tat = 0;
    int total_wt = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - initial_bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("Process\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, initial_bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);

    return 0;
}