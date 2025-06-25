#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}

struct node *insertLevelOrder(int a[], int i, int n) {
    if (i >= n) return NULL;

    struct node *root = createnode(a[i]);
    root->left = insertLevelOrder(a, 2 * i + 1, n);
    root->right = insertLevelOrder(a, 2 * i + 2, n);

    return root;
}

int max(int a,int b){
    return a>b ? a:b;
}
int height(struct node *root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}

void printLevel(struct node *root, int level) {
    if (root == NULL) return;
    if (level == 1)
        printf("%d ", root->data);
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrderTraversal(struct node *root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    struct node *root = insertLevelOrder(a, 0, n);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    free(a);
    return 0;
}
