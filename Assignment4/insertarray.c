#include <stdio.h>

int main() {
    int arr[10] = {1, 8, 7, 10};
    int n = 4;
    int value = 5;
    int pos = 1;   
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;

    printf("After inserting the element, the new list: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
