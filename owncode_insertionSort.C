#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[10];
    printf("enter elements of array\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("original array\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\n%d\n",arr[i]);
    }
    
    for (int i = 1; i < 10; i++)
    {
        int j=i-1;//left side element of current element;
        while(j>=0 && arr[j+1]<arr[j])  // checking is the element is smaller than the other element of sorted array
                                         // and sorting accordingly
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                j--; 
            }
    }   
    printf("\ninsertion sort array\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\n%d\n",arr[i]);
    }  
}