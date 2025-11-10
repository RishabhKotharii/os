#include <stdio.h>

#define N 5  
#define M 3  

int main() {
    int i, j;

    int available[M] = {3, 3, 2};

    int allocation[N][M] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[N][M] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int need[N][M];
    int work[M];
    int finish[N] = {0};
    int safeSequence[N];

    // -------- Calculate Need Matrix --------
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int p = 1; 
    int request[M] = {1,0,2};

    // -------- Check if request <= need --------
    for (j = 0; j < M; j++) {
        if (request[j] > need[p][j]) {
            printf("\nResources cannot be granted\n");
            return 0;
        }
    }

    // -------- Check if request <= available --------
    for (j = 0; j < M; j++) {
        if (request[j] > available[j]) {
            printf("\nResources cannot be granted.\n");
            return 0;
        }
    }

    // -------- Pretend to allocate resources --------
    for (j = 0; j < M; j++) {
        available[j] -= request[j];
        allocation[p][j] += request[j];
        need[p][j] -= request[j];
    }
    
    // -------- Safety Algorithm --------
    for (i = 0; i < M; i++) {
        work[i] = available[i];
    }

    for (i = 0; i < N; i++) {
        finish[i] = 0;
    }

    int count = 0;
    while (count < N) {
        int found = 0;

        for (i = 0; i < N; i++) {
            if (finish[i] == 0) {
                int canProceed = 1;

                for (j = 0; j < M; j++) {
                    if (need[i][j] > work[j]) {
                        canProceed = 0;
                        break;
                    }
                }

                if (canProceed == 1) {
                    for (j = 0; j < M; j++) {
                        work[j] += allocation[i][j];
                    }

                    finish[i] = 1;
                    safeSequence[count] = i;
                    count++;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("\nRequest cannot be granted as it is in unsafe state.\n");
            return 0;
        }
    }

    // -------- Safe State Output --------
    printf("\nRequest can be granted.\nSystem is in a safe state.\nSafe sequence is: ");
    for (i = 0; i < N; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");

    return 0;
}
