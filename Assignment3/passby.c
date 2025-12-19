#include<stdio.h>
int passByValue(int num){
    num++; 
    return num;
}
int passByReference(int *num){
    (*num)++;
    return *num;
}
int main(){
    int num=10;
    printf("Value before function call:%d\n",num);

    passByValue(num);
    printf("Value after pass by value:%d\n",num);

    passByReference(&num);
    printf("Value after pass by reference:%d\n",num);
    return 0;
}