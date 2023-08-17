//optimised bubble sort

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=10;
    int arr[n];
    printf("enter elements of array\n");

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        int flag = 0;// flag initialization
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1]) // here we take the inner loop this way cause there is no part such as sorted and unsorted
            // even just before last passing the arr[0] might not be the least element of array 
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                flag=1; // flag value update

            }
            
        }
        if(flag==0) // flag code
            break;
        
    }
    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("\n%d\n",arr[i]);
    }
    
    
}

