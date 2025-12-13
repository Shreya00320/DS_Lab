#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void push(struct Node** top, int value) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    p->data = value;
    p->next = *top;
    *top = p;
    printf("%d pushed to stack\n", value);
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* p = *top;
    printf("%d popped from stack\n", p->data);
    *top = p->next;
    free(p);
}

void displayStack(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    p->data = value;
    p->next = NULL;

    if (*rear == NULL) {
        *front = *rear = p;
    } else {
        (*rear)->next = p;
        *rear = p;
    }
    printf("%d enqueued to queue\n", value);
}

void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* p = *front;
    printf("%d dequeued from queue\n", p->data);
    *front = p->next;
    if (*front == NULL)
        *rear = NULL;
    free(p);
}

void displayQueue(struct Node* front) {
    printf("Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;


    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    displayStack(stackTop);
    pop(&stackTop);
    displayStack(stackTop);

    enqueue(&queueFront, &queueRear, 100);
    enqueue(&queueFront, &queueRear, 200);
    enqueue(&queueFront, &queueRear, 300);
    displayQueue(queueFront);
    dequeue(&queueFront, &queueRear);
    displayQueue(queueFront);

    return 0;
}
