#include <stdio.h>

int read_count = 0;
int mutex = 1;
int rw_mutex = 1;

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

void reader(int id) {
    if (wait(&mutex)) {
        read_count++;
        if (read_count == 1) {
            wait(&rw_mutex); // First reader locks writers
        }
        signal(&mutex);

        printf("Reader %d is reading...\n", id);

        if (wait(&mutex)) {
            read_count--;
            if (read_count == 0) {
                signal(&rw_mutex); // Last reader unlocks writers
            }
            signal(&mutex);
        }
    } else {
        printf("Reader %d is blocked.\n", id);
    }
}

void writer(int id) {
    if (wait(&rw_mutex)) {
        printf("Writer %d is writing...\n", id);
        signal(&rw_mutex);
    } else {
        printf("Writer %d is blocked.\n", id);
    }
}

int main() {
    int choice, id;

    while (1) {
        printf("\n1. Reader\n2. Writer\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Reader ID: ");
                scanf("%d", &id);
                reader(id);
                break;
            case 2:
                printf("Enter Writer ID: ");
                scanf("%d", &id);
                writer(id);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}