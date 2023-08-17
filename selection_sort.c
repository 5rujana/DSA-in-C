#include<stdio.h>
#include<stdlib.h>

int main(){
	int n = 10;
    int arr[n];
    printf("enter elements of array");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < n-1; i++) // no of passes
    {
        int min=i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;           // finding the minimum element from unsorted array
            }
            int temp = arr[i];
            arr[i]=arr[min]; // swapping elements
            arr[min]=temp;
            
        }
        
    }

    printf(" sorted array :\n");
    for (int i = 0; i < n ; i++)
    {
        printf("%d\t",arr[i]);
    }
          
}