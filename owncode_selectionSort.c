#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int arr[n];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;// intially index of minimum element is i
        for (int j = i + 1; j < n; j++) { // this loop is used to find index of the smallest element than arr[i]
            if (arr[j] < arr[min_index]) {
                min_index = j;   // index of the element smallest than arr[i] is stored in min_index
            }
        }
        int min = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = min;
    }

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
