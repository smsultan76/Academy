#include <stdio.h>

int forks[5] = {1, 1, 1, 1, 1}; // 1 means fork is available

void eat(int id) {
    int left = id;
    int right = (id + 1) % 5;

    if (forks[left] && forks[right]) {
        forks[left] = 0;
        forks[right] = 0;

        printf("Philosopher %d is eating using forks %d and %d\n", id, left, right);

        forks[left] = 1;
        forks[right] = 1;
    } else {
        printf("Philosopher %d cannot eat now. Forks not available.\n", id);
    }
}

int main() {
    int choice, id;

    while (1) {
        printf("\n1. Philosopher tries to eat\n2. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Philosopher ID (0–4): ");
            scanf("%d", &id);
            if (id >= 0 && id < 5)
                eat(id);
            else
                printf("Invalid ID.\n");
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}