#include <stdio.h>

int main() {
    int arr[] = {4,5,1};
    int n = 3;

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Maximum element is : %d\n", max);
    printf("Minimum element is : %d", min);

    return 0;
}
