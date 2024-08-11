#include <stdio.h>
#include <stdlib.h>

int numTracks, headPosition, temp, k, total = 0;
int p = 0;
int tracks[100], sortedTracks[100], difference;
int j;
int endTrack;

void main()
{
    printf("Enter the number of tracks: ");
    scanf("%d", &numTracks);
    printf("Enter the head position: ");
    scanf("%d", &headPosition);
    printf("Enter the tracks to be traversed: ");
    for (int i = 0; i < numTracks; i++)
    {
        scanf("%d", &tracks[i]);
    }
    printf("Enter the end track: ");
    scanf("%d", &endTrack);

    tracks[numTracks] = headPosition;
    tracks[numTracks + 1] = 0;
    tracks[numTracks + 2] = endTrack;
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

    printf("Sorted tracks: ");
    for (int i = 0; i < numTracks; i++)
    {
        printf("%d ", tracks[i]);
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

    
    if (headPosition < (endTrack - headPosition))
    {
        for (int i = k; i >= 0; i--, p++)
        {
            sortedTracks[p] = tracks[i];
        }
        for (int i = k + 1; i < numTracks - 1; i++, p++)
        {
            sortedTracks[p] = tracks[i];
        }
    }
    else
    {
        for (int i = k; i < numTracks; i++, p++)
        {
            sortedTracks[p] = tracks[i];
        }
        for (int i = k - 1; i >= 0; i--, p++)
        {
            sortedTracks[p] = tracks[i];
        }
    }

    printf("Traversed Order: ");
    for (int i = 0; i < p; i++)
    {
        printf("%d => ", sortedTracks[i]);
    }

    total = 0;
    for (j = 0; j < p - 1; j++)
    {
        difference = abs(sortedTracks[j + 1] - sortedTracks[j]);
        total += difference;
    }

    printf("\b\b\b. \nTotal head movement: %d\n", total);
}
