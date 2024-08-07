#include <stdio.h>

void main() {
    int i, j, n, f, page[20], pf = 0, frame[10], frequency[10], age[10], least, flag, time = 0;

    printf("Enter no of pages: ");
    scanf("%d", &n);

    printf("\nEnter the page sequence:");
    for (i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (j = 0; j < f; j++) {
        frame[j] = -1;  
        frequency[j] = 0;
        age[j] = 0;
    }

    for (i = 0; i < n; i++) {
        flag = 0;
        time++;

        for (j = 0; j < f; j++) {
            if (frame[j] == page[i]) {
                flag = 1;
                frequency[j]++;
                age[j] = time;
                break;
            }
        }

        if (flag == 0) {
            int emptyFrame = 0;
            for (j = 0; j < f; j++) {
                if (frame[j] == -1) {  
                    frame[j] = page[i];  
                    frequency[j] = 1;
                    age[j] = time;
                    emptyFrame = 1;
                    break;
                }
            }
            if (!emptyFrame) {
                if (i >= f) {
                    least = 0;
                    for (j = 1; j < f; j++) {
                        if (frequency[j] < frequency[least]) {
                            least = j;
                        } else if (frequency[j] == frequency[least] && age[j] < age[least]) {
                            least = j; 
                        }
                    }
                    frame[least] = page[i];
                    frequency[least] = 1;
                    age[least] = time;
                }
            }
            pf++;  
        }

        for (j = 0; j < f; j++) {
            printf("%d\t", frame[j]);
        }
        printf("\tTotal page faults: %d\n", pf);
    }
    printf("No. of page hits: %d\n", n - pf);
}