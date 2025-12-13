#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


void create(int n) {
    struct node *p, *temp;
    int i;

    for (i = 0; i < n; i++) {
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter info: ");
        scanf("%d", &p->info);

        p->prev = NULL;
        p->next = NULL;

        if (head == NULL) {
            head = p;
            temp = p;
        } else {
            temp->next = p;
            p->prev = temp;
            temp = p;
        }
    }
}


void insert_left(int key, int info) {
    struct node *temp = head, *p;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found\n", key);
        return;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->info = info;
    p->next = temp;
    p->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = p;
    else
        head = p;

    temp->prev = p;
}


void delete_value(int key) {
    struct node *temp = head;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found\n", key);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node with value %d deleted\n", key);
}


void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, key, info;

    while (1) {
        printf("\n1.Create\n2.Insert Left\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            create(n);
            break;

        case 2:
            printf("Enter value to insert left of: ");
            scanf("%d", &key);
            printf("Enter new info: ");
            scanf("%d", &info);
            insert_left(key, info);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &key);
            delete_value(key);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

