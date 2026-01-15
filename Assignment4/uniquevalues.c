#include <stdio.h>

int main() {
    int i, j;
    int n = 4;
    int arr[] = {2, 3, 5, 3};

    for (i = 0; i < n; i++) {
        int reps = 0;

        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                reps++;
            }
        }

        if (reps == 1) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
