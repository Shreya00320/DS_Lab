#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *left, *right;
};


struct node* createnode(int value) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

struct node* insert(struct node *root, int value) {
    if (root == NULL)
        return createnode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void preorder(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void postorder(struct node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


void display(struct node *root) {
    printf("BST Elements (In-order): ");
    inorder(root);
    printf("\n");
}

int main() {
    struct node *root = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nIn-order Traversal: ");
    inorder(root);

    printf("\nPre-order Traversal: ");
    preorder(root);

    printf("\nPost-order Traversal: ");
    postorder(root);

    return 0;
}
