#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node *next;
};

struct node *start = NULL;

struct node* createNode(int data) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->info = data;
    p->next = NULL;
    return p;
}


void insertEnd(int data) {
    struct node *p = createNode(data);

    if (start == NULL) {
        start = p;
        return;
    }

    struct node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
}


void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node* concatenate(struct node *head1, struct node *head2) {
    if (head1 == NULL)
        return head2;

    struct node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}


int main() {
    struct node *list1 = NULL;
    struct node *list2 = NULL;


    start = NULL;
    insertEnd(30);
    insertEnd(10);
    insertEnd(20);
    list1 = start;

    printf("List1 before sorting: ");
    display(list1);

    sortList(list1);
    printf("List1 after sorting: ");
    display(list1);

    list1 = reverseList(list1);
    printf("List1 after reversing: ");
    display(list1);

    // Create second list
    list2 = createNode(40);
    list2->next = createNode(50);

    printf("List2: ");
    display(list2);

    // Concatenate lists
    list1 = concatenate(list1, list2);
    printf("Concatenated List: ");
    display(list1);

    return 0;
}
