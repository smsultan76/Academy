#include <stdio.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;
int mutex = 1;
int full = 0;
int empty = SIZE;

int wait(int *s) {
    if (*s > 0) {
        (*s)--;
        return 1;
    }
    return 0;
}

void signal(int *s) {
    (*s)++;
}

void produce(int item) {
    if (wait(&mutex) && wait(&empty)) {
        buffer[in] = item;
        printf("Produced %d at index %d\n", item, in);
        in = (in + 1) % SIZE;
        signal(&full);
        signal(&mutex);
    } else {
        printf("Buffer full or locked. Cannot produce.\n");
    }
}

void consume() {
    if (wait(&mutex) && wait(&full)) {
        int item = buffer[out];
        printf("Consumed %d from index %d\n", item, out);
        out = (out + 1) % SIZE;
        signal(&empty);
        signal(&mutex);
    } else {
        printf("Buffer empty or locked. Cannot consume.\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to produce: ");
                scanf("%d", &item);
                produce(item);
                break;
            case 2:
                consume();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}