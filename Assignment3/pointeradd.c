#include <stdio.h>
int addition(){
    int num1=5;
    int num2=15;

    int*ptr1=&num1;
    int*ptr2=&num2;

    int sum=*ptr1+*ptr2;
    printf("The sum total is:%d",sum);
    return 0;
}
int main(){
    addition();
    return 0;
}