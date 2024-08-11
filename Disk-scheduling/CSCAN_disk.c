#include <stdio.h>
#include <stdlib.h>

int numTracks, headPosition, endTrack, temp, k, j, total = 0;
int tracks[100], sortedTracks[100], traversedOrder[100];

void main()
{
    printf("Enter the number of tracks: ");
    scanf("%d", &numTracks);

    printf("Enter the head pointer position: ");
    scanf("%d", &headPosition);

    printf("Enter the end track: ");
    scanf("%d", &endTrack);

    printf("Enter the tracks to be traversed: ");
    for (int i = 0; i < numTracks; i++)
    {
        scanf("%d", &tracks[i]);
    }

    tracks[numTracks + 2] = endTrack;
    tracks[numTracks + 1] = 0;
    tracks[numTracks] = headPosition;
    numTracks = numTracks + 3;

    for (int i = 0; i < numTracks; i++)
    {
        for (int j = 0; j < numTracks - i - 1; j++)
        {
            if (tracks[j] > tracks[j + 1])
            {
                temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < numTracks; i++)
    {
        if (tracks[i] == headPosition)
        {
            k = i;
            break;
        }
    }
    // The direction is found by comparing the distance between the head position and the track at the end of the disk.
    // If the head position is less than the distance between the end track and the head position, the head moves towards the end track.
    // Otherwise, the head moves towards the start track.
    int p = 0;
    if (headPosition < (endTrack - headPosition))
    {
        for (int i = k; i >= 0; i--, p++)
        {
            traversedOrder[p] = tracks[i];
        }
        for (int i = numTracks - 1; i > k; i--, p++)
        {
            traversedOrder[p] = tracks[i];
        }
    }
    else
    {
        for (int i = k; i < numTracks; i++, p++)
        {
            traversedOrder[p] = tracks[i];
        }
        for (int i = 0; i < k; i++, p++)
        {
            traversedOrder[p] = tracks[i];
        }
    }

    printf("Traversed order: ");
    for (int i = 0; i < p; i++)
    {
        printf("%d => ", traversedOrder[i]);
    }

    for (total = 0, j = 0; j < p - 1; j++)
    {
        int diff = abs(traversedOrder[j] - traversedOrder[j + 1]);
        total += diff;
    }

    printf("\b\b\b. \nTotal head movements: %d\n", total);
}
