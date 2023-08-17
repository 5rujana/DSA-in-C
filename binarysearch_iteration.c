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

     int mid, l , h;
     l=0;
     h=10-1; //n-1
     while (l<=h)
     {
        mid= (l+h)/2;
        if (element = arr[mid])
        {
            return mid;
        }else if (element>arr[mid])
        {
            l = mid +1;
        }else
        {
            h=mid -1;
        }
     }  
}