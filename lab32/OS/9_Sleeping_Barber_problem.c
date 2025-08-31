#include <stdio.h>

#define MAX_CHAIRS 3

int waiting = 0;     // Number of customers waiting
int barber_busy = 0; // 0 = sleeping, 1 = cutting hair

void customer_arrives(int id) {
    if (waiting < MAX_CHAIRS) {
        waiting++;
        printf("Customer %d enters and waits. Waiting chairs: %d\n", id, waiting);

        if (!barber_busy) {
            barber_busy = 1;
            waiting--;
            printf("Barber wakes up and starts cutting hair of Customer %d\n", id);
        }
    } else {
        printf("Customer %d leaves. No empty chair.\n", id);
    }
}

void barber_done() {
    if (waiting > 0) {
        waiting--;
        printf("Barber calls next customer. Remaining waiting: %d\n", waiting);
    } else {
        barber_busy = 0;
        printf("No customers. Barber goes to sleep.\n");
    }
}

int main() {
    int choice, id = 1;

    while (1) {
        printf("\n1. New Customer Arrives\n2. Barber Finishes Haircut\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customer_arrives(id++);
                break;
            case 2:
                barber_done();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}