#include <stdio.h>

int main() {
    int arr[] = {2, 7, 4, 5, 9};
    int n = 5;
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Elements of array in sorted ascending order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
