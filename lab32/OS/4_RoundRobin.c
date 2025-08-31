#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process *p = (struct Process *)malloc(n * sizeof(struct Process));

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int current_time = 0, completed = 0;
    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    // Enqueue first arrived processes
    for (int i = 0; i < n; i++) {
        if (p[i].arrival == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) {
        if (front == rear) {
            current_time++;
            for (int i = 0; i < n; i++) {
                if (p[i].arrival <= current_time && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];
        if (p[idx].remaining > tq) {
            p[idx].remaining -= tq;
            current_time += tq;
        } else {
            current_time += p[idx].remaining;
            p[idx].remaining = 0;
            p[idx].completion = current_time;
            completed++;
        }

        // Enqueue newly arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // Re-enqueue current process if not finished
        if (p[idx].remaining > 0) {
            queue[rear++] = idx;
        }
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }

    // Display results
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }

    free(p);
    free(queue);
    return 0;
}