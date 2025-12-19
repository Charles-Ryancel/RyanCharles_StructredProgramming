#include<stdio.h>
int pointerupdate(){
    int Count=5;
    int *pCount=&Count;
    *pCount=17;
    printf("Updated value:%d",*pCount);
    return 0;
}
int main(){
    pointerupdate();
    return 0;
}