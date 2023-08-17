#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node * left;
    struct node *right;
};
 
 //structure for tree
struct node *newnode(int data){
    struct node *newnode= (struct node *)malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=data;
    return (newnode);
}

// function for preorder
void postorder( struct node *root){
    if(root==NULL)
        return;

    postorder((root)->left);
    postorder((root)->right);
    printf("%c\t", (root)->data);
}

//function for post order
void preorder( struct node *root){
    if (root==NULL)
        return;

    printf("%c\t", (root)->data);
    preorder((root)->left);
    preorder((root)->right);
}

//function for in order
void inorder( struct node *root){
    if (root==NULL)
        return;

    inorder((root)->left);
    printf("%c\t", (root)->data);
    inorder((root)->right);
}

// main function
int main(){
    struct node *root= newnode('A');
    root->left=newnode('B');
    root->right=newnode('E');
    root->left->left=newnode('C');
    root->left->right=newnode('D');
    root->right->left=newnode('F');
    root->right->left->left=newnode('G');
    root->right->left->left->left=newnode('I');
    root->right->left->left->right=newnode('H');
    printf("\n postorder\n");
    postorder(root);
    printf("\npreorder\n");
    preorder(root);
    printf("\ninorder\n");
    inorder(root);
}

