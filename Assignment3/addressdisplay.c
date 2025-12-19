#include <stdio.h>

int pointers(){
    int num=15;
    int *ptr=&num;
    printf("Address of num:%p\n",ptr);
    printf("Value of num:%d",*ptr);
    return 0;
}
int main(){
    pointers();
    return 0;
}