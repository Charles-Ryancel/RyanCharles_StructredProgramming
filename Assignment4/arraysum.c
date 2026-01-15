#include <stdio.h>

int main(){
    int i;
    int n=3;
    int arr[]={2,3,5};
    int sum=0;

    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("The total sum of the array:%d",sum);
    return 0;
}