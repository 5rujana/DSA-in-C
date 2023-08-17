#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int value;
    struct Node* next;
};

/* Degenerate Tree structure */
struct DegenerateTree {
    struct Node* root;
    struct Node* last_node;
};

/* Helper function that allocates a new node with the given value and NULL next pointer. */
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = val;
    node->next = NULL;
    return node;
}

/* Initializes a new Degenerate Tree. */
void initDegenerateTree(struct DegenerateTree* tree) {
    tree->root = NULL;
    tree->last_node = NULL;
}

/* Inserts a new node with the given value to the Degenerate Tree. */
void insert(struct DegenerateTree* tree, int value) {
    struct Node* new_node = newNode(value);
    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        tree->last_node->next = new_node;
    }
    tree->last_node = new_node;
}

int main() {
    struct DegenerateTree tree;
    initDegenerateTree(&tree);
    insert(&tree, 1);
    insert(&tree, 2);
    insert(&tree, 3);
    insert(&tree, 4);
    return 0;
}
