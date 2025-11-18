#include<stdio.h>
#include<string.h>

int addition(int x,int y){
    int z=x+y;
    printf("%d",z);
}
int subtraction(int x,int y){
    int z=x-y;
    printf("%d",z);
}
int multiplication(int x,int y){
    int z=x*y;
    printf("%d",z);
}
int division(int x,int y){
    if(y!=0){
        int z=x/y;
        printf("%d",z);
    }else{
        printf("Zero Division Error");
    }
}

int menu(){
    char operation[10];
    int x,y;
    printf("Calculator\n");

    printf("Choose Operation:\n");

    scanf("%s",operation);

    printf("Input first value:");
    scanf("%d",&x);
    printf("Input second value:");
    scanf("%d",&y);


    if(strcmp(operation,"add")==0){
        addition(x,y);
    }else if(strcmp(operation,"sub")==0){
        subtraction(x,y);
    }else if(strcmp(operation,"mult")==0){
        multiplication(x,y);
    }else if(strcmp(operation,"div")==0){
        division(x,y);
    }else{
        printf("Invalid Input!!");
    }
    
}

int main(){
   menu();
   return 0;
}