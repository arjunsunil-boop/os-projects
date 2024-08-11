#include<stdio.h>
#include<string.h>

void main() {
    int tracks[20], head, tracks, i, totalHeadMovements = 0, headMovement;

    printf("Enter the number of tracks : ");
    scanf("%d", &tracks);

    printf("Enter the head pointer position : ");
    scanf("%d", &head);

    printf("Enter the tracks to be traversed : ");
    for(i = 0; i < tracks; i++) {
        headMovement = 0;
        scanf("%d", &tracks[i]);
        headMovement = head - tracks[i];
        if(headMovement < 0) {
            headMovement = tracks[i] - head;
        }
        head = tracks[i];
        totalHeadMovements += headMovement;
    }

    printf("Traversed order : ");
    for(i = 0; i < tracks; i++)
        printf("%d => ", tracks[i]);
    printf("\b\b\b.   \nTotal head movements : %d\n", totalHeadMovements);
}