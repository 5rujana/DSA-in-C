#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct isfulltree{
    struct node * root;
};

void insert ( struct isfulltree *tree , int data){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    
    if (tree->root==NULL)
    {
        tree->root=newnode;
     }else{
        struct node *current_node=newnode;

    while (1)
    {
            if (current_node->left ==NULL)
            {
                current_node->left=newnode;
                break;
            }

            else if (current_node->right==NULL)
            {
                current_node->right=newnode;
                break;
            }
            
            else if (current_node->left !=NULL&&current_node->right !=NULL)
            {
                current_node=current_node->left;
                break;
            }   
    }
            }

}


int main(){
    struct isfulltree *tree;
    tree->root=NULL;
        insert(&tree,1);
        insert(&tree,2);
        insert(&tree,3);
        insert(&tree,4);
        insert(&tree,5);
        insert(&tree,6);
        insert(&tree,7);
}