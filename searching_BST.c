#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode( int data ){
    struct node *newnode=(struct node *) malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=data;
}


struct node * insertnode(int data , struct node *root){
        if (root==NULL)
        {
            root=newnode(data);
        } else if (data>=root->data)
        {
            root->right =insertnode(data,root->right);
        }else{
             root -> left = insertnode(data, root->left);
        }
    return root;       
}

bool Search(struct node *root , int element){
    if (root==NULL)
    {
        return false;
    }else if (root->data==element)
    {
        return true;        
    }else if (root->data>= element) // left subtree value greater or equal
    {
        return search(root->left , element);
    }else{
        return search(root->right , element);
    }   
}

// struct node * deletenode(struct node * root){

// } 


int main(){
    struct node *root;
    insertnode(1,root);
    insertnode(2,root);
    insertnode(3,root);
    insertnode(4,root);
    insertnode(5,root);
    preorder(root);
    postorder(root);
    inorder(root);
}


