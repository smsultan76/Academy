#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int completion;
    int turnaround;
    int waiting;
    int visited;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process *p = (struct Process *)malloc(n * sizeof(struct Process));

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time, Burst Time, and Priority for Process %d: ", p[i].pid);
        scanf("%d %d %d", &p[i].arrival, &p[i].burst, &p[i].priority);
        p[i].visited = 0;
    }

    int completed = 0, current_time = 0;

    while (completed < n) {
        int idx = -1;
        int highest_priority = 9999;

        // Select process with highest priority among arrived and unvisited
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && p[i].visited == 0) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].completion = current_time + p[idx].burst;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            current_time = p[idx].completion;
            p[idx].visited = 1;
            completed++;
        } else {
            current_time++; // No process ready, move time forward
        }
    }

    // Display results
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst, p[i].priority,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }

    free(p);
    return 0;
}