#include <stdio.h>

#define MAX 10

int allocation[MAX][MAX]; // R → P (resource assigned to process)
int request[MAX][MAX];    // P → R (process requesting resource)
int process_count, resource_count;

void input() {
    printf("Enter number of processes: ");
    scanf("%d", &process_count);
    printf("Enter number of resources: ");
    scanf("%d", &resource_count);

    printf("Enter Allocation Matrix (R → P):\n");
    for (int i = 0; i < resource_count; i++) {
        for (int j = 0; j < process_count; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter Request Matrix (P → R):\n");
    for (int i = 0; i < process_count; i++) {
        for (int j = 0; j < resource_count; j++) {
            scanf("%d", &request[i][j]);
        }
    }
}

int detect_cycle() {
    int visited[MAX] = {0};
    int rec_stack[MAX] = {0};

    for (int p = 0; p < process_count; p++) {
        if (!visited[p]) {
            if (dfs(p, visited, rec_stack)) {
                return 1; // Cycle found
            }
        }
    }
    return 0;
}

int dfs(int p, int visited[], int rec_stack[]) {
    visited[p] = 1;
    rec_stack[p] = 1;

    for (int r = 0; r < resource_count; r++) {
        if (request[p][r]) {
            for (int q = 0; q < process_count; q++) {
                if (allocation[r][q]) {
                    if (!visited[q] && dfs(q, visited, rec_stack)) {
                        return 1;
                    } else if (rec_stack[q]) {
                        return 1;
                    }
                }
            }
        }
    }

    rec_stack[p] = 0;
    return 0;
}

int main() {
    input();

    if (detect_cycle()) {
        printf("Deadlock detected in the Resource-Allocation Graph.\n");
    } else {
        printf("No deadlock detected.\n");
    }

    return 0;
}