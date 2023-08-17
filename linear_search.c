#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[10];
     printf("enter elements of array\n");
     for (int i = 0; i < 10 ; i++)
     {
        scanf("%d",&arr[i]);
     }
     printf("the elemet you want to search\n");
     int element;
     scanf("%d",&element);

     for (int i = 0; i < 10; i++) // time complexity O(n)
     {
        if (arr[i]==element)
        {
            return i;
        }else
        {
            return -1;
        }
     }    
     
}