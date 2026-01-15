#include <stdio.h>

int main() {
    int i;
    int n = 3;
    int arr[] = {2, 5, 7};

    printf("The values stored in the array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nThe values stored in the array in reverse: ");
    for (i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);

    return 0;
}
