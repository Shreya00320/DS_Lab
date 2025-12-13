#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;


void insertCQ(int item) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    cq[rear] = item;
    printf("%d inserted into queue\n", item);
}

int deleteCQ() {
    int item;

    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    item = cq[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return item;
}

void displayCQ() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; ; i = (i + 1) % SIZE) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insertCQ(item);
                break;

            case 2:
                item = deleteCQ();
                if (item != -1)
                    printf("Deleted item: %d\n", item);
                break;

            case 3:
                displayCQ();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
