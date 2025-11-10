#include <stdio.h>
#include <limits.h>

int main() {
    int n, framescount;
    printf("Enter the total number of entries count : ");
    scanf("%d", &n);

    printf("Enter the size of frame : ");
    scanf("%d", &framescount);

    int pages[n];
    int frames[framescount];
    int lastUsed[framescount]; // timestamp of last use for each frame
    int hit = 0;
    int fault = 0;
    int timeCounter = 0; // increments each page access

    printf("Enter the values one by one :");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // initialize frames to -1 (empty) and lastUsed to -1
    for (int i = 0; i < framescount; i++) {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // check if page is already in some frame (hit)
        for (int j = 0; j < framescount; j++) {
            if (frames[j] == page) {
                found = 1;
                hit++;
                timeCounter++;
                lastUsed[j] = timeCounter; // update recent usage
                break;
            }
        }

        if (!found) {
            // page fault
            fault++;
            timeCounter++;

            // first try to find an empty frame
            int emptyIndex = -1;
            for (int j = 0; j < framescount; j++) {
                if (frames[j] == -1) {
                    emptyIndex = j;
                    break;
                }
            }

            if (emptyIndex != -1) {
                // use empty frame
                frames[emptyIndex] = page;
                lastUsed[emptyIndex] = timeCounter;
            } else {
                // find LRU frame: smallest lastUsed value
                int lruIndex = 0;
                int minTime = lastUsed[0];
                for (int j = 1; j < framescount; j++) {
                    if (lastUsed[j] < minTime) {
                        minTime = lastUsed[j];
                        lruIndex = j;
                    }
                }
                // replace LRU frame
                frames[lruIndex] = page;
                lastUsed[lruIndex] = timeCounter;
            }
        }

        // print current step & frames
        printf("Step no %d : ", i + 1);
        for (int j = 0; j < framescount; j++) {
            if (frames[j] == -1) {
                printf(" - ");
            } else {
                printf(" %d ", frames[j]);
            }
        }
        if (found)
            printf("   (hit)\n");
        else
            printf("   (fault)\n");
    }

    printf("Total no of hits : %d \n", hit);
    printf("Total no of faults : %d\n", fault);

    return 0;
}
