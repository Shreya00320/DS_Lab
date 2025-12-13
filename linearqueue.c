#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insertLQ(int item) {
    if (rear == SIZE - 1) {
        printf("QUEUE IS FULL\n");
    }
    else if (front == -1) {
        front = 0;
        rear = 0;
        queue[rear] = item;
    }
    else {
        rear++;
        queue[rear] = item;
    }
}

int deleteLQ() {
    int item;

    if (front == -1) {
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    else if (front == rear) {
        item = queue[front];
        front = -1;
        rear = -1;
        return item;
    }
    else {
        item = queue[front];
        front++;
        return item;
    }
}

void displayLQ() {
    if (front == -1) {
        printf("QUEUE IS EMPTY\n");
    }
    else {
        printf("QUEUE ELEMENTS: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                insertLQ(item);
                break;

            case 2:
                item = deleteLQ();
                if (item != -1)
                    printf("Deleted element: %d\n", item);
                break;

            case 3:
                displayLQ();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
