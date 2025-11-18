#include <stdio.h>

int main() {
    float x;
    float formula;

    printf("Input the radius:\n");
    scanf("%f", &x);

    formula = 4 * 3.142 * x * x;

    printf("%f", formula);

    return 0;
}

