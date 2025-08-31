#include <stdio.h>

#define P 5 // Number of processes
#define R 3 // Number of resources

int available[R] = {3, 3, 2}; // Available resources
int max[P][R] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};
int allocation[P][R] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int need[P][R];

void calculate_need() {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

int is_safe() {
    int work[R], finish[P] = {0}, safe_seq[P], count = 0;
    for (int i = 0; i < R; i++) work[i] = available[i];

    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j]) break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[i][k];
                    safe_seq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) return 0; // Unsafe state
    }

    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safe_seq[i]);
    printf("\n");
    return 1;
}

int main() {
    calculate_need();
    if (!is_safe())
        printf("System is NOT in a safe state. Deadlock may occur.\n");
    return 0;
}