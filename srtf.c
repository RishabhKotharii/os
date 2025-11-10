#include <stdio.h>

int main() {
    int n, time = 0, completed = 0, shortest = -1;
    int arrival[10], burst[10], remaining[10], finish[10], waiting[10], turnaround[10];
    int min_remaining;
    int is_process_found = 0;

    printf("Enter number of processes (max 10): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    while (completed < n) {
        min_remaining = 10000;
        is_process_found = 0;

        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0 && remaining[i] < min_remaining) {
                min_remaining = remaining[i];
                shortest = i;
                is_process_found = 1;
            }
        }

        if (is_process_found == 0) {
            time++;
            continue;
        }

        remaining[shortest]--;
        time++;

        if (remaining[shortest] == 0) {
            completed++;
            finish[shortest] = time;
            turnaround[shortest] = finish[shortest] - arrival[shortest];
            waiting[shortest] = turnaround[shortest] - burst[shortest];
        }
    }

    printf("Process\tArrival\tBurst\tFinish\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", i + 1, arrival[i], burst[i], finish[i], turnaround[i], waiting[i]);
    }
    
    // Calculate total and average turnaround and waiting times
    float total_turnaround = 0;
    float total_waiting = 0;

    for (int i = 0; i < n; i++) {
        total_turnaround += turnaround[i];
        total_waiting += waiting[i];
    }

    float avg_turnaround = total_turnaround / n;
    float avg_waiting = total_waiting / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);

    return 0;
}