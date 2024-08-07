#include <stdio.h>

void main() {
    int i, j, n, f, page[20], pf = 0, frame[10], recent[10], least, flag;

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
        recent[j] = 0; 
    }

    for (i = 0; i < n; i++) {
        flag = 0;

        for (j = 0; j < f; j++) {
            if (frame[j] == page[i]) {
                flag = 1;
                recent[j] = i + 1; 
                break;
            }
        }

        if (flag == 0) {
            int emptyFrame = 0;
            for (j = 0; j < f; j++) {
                if (frame[j] == -1) {  
                    frame[j] = page[i];  
                    recent[j] = i + 1;
                    emptyFrame = 1;
                    break;
                }
            }
            if (!emptyFrame) {
                if (i >= f) {
                    least = 0;
                    for (j = 1; j < f; j++) {
                        if (recent[j] < recent[least]) {
                            least = j;
                        }
                    }
                    frame[least] = page[i];
                    recent[least] = i + 1;
                }
            }
            pf++;  
        }

        for (j = 0; j < f; j++) {
            printf("%d\t", frame[j]);
        }
        printf("\tTotal page faults: %d\n", pf);
    }
    printf("No. of page hits:%d\n", n - pf);
}
