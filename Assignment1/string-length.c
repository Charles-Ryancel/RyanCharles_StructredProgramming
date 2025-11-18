#include <stdio.h>
#include <string.h>

int main(){
    char name[30];
    printf("Input your string:\n");
    scanf("%s",&name);
    printf("Your string is:%s",name);
    printf("Length of string:%d",strlen(name));
    return 0;
}