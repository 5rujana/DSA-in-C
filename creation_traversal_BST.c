#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;
    return newnode;
}

struct node* insertnode(int data , struct node* root){
    if (root == NULL) {
        root = newnode(data);
    } else if (data >= root->data) {
        root->right = insertnode(data, root->right);
    } else {
        root->left = insertnode(data, root->left);
    }
    return root;
}

// pre order
void preorder(struct node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// inorder
void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// post order
void postorder(struct node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root = NULL;
    root = insertnode(1, root);
    root = insertnode(2, root);
    root = insertnode(3, root);
    root = insertnode(4, root);
    root = insertnode(5, root);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
