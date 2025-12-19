#include<stdio.h>
int swapNumbers(int*a, int*b);
int main(){
    int a;
    int b;
    swapNumbers(&a,&b);
    return 0;
}

int swapNumbers(int*a, int*b){
    *a=10;
    *b=15;
    printf("Original Values of a:%d and b:%d\n",*a,*b);
    int new=*a;
    *a=*b;
    *b=new;
    printf("Swapped Values of a:%d and b:%d",*a,*b);
}