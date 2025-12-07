#include <stdio.h>
#include<string.h>
#include<time.h>

int login();
int menu();
int check_balance();
int withdraw();
int deposit();
int leave(); 

int main(){
    login();
    return 0;
}

int login(){
    int passcode=5678;
    int usercode;
    int attempts=3;

    while(attempts<=3){

        printf("Input passcode:");
        scanf("%d",&usercode);

        if(usercode!=passcode)
        {
            printf("Incorrect passcode!\n");
            attempts--;
            printf("Remaining attempts:%i\n",attempts);

            if (attempts==0)
        {
            printf("Too many attempts!System Locked");
            break;
        }

        }
        else
        {
            printf("Access Granted!!!\n");
            menu();
            break;
        }
    }
}

int menu(){
    int userchoice;
    printf("***Menu***\n"
        "1.Balance Inquiry\n"
        "2.Deposit\n"
        "3.Withdraw\n"
        "4.Exit\n"
        );

    printf("Input choice:\n");
    scanf("%d",&userchoice);

    if(userchoice==1){
        check_balance();
    }
    else if(userchoice==2){
        deposit();
    }
    else if(userchoice==3){
        withdraw();
    }
    else{
        leave();
    }
    return 0;
   
}

int bal=5000;
int check_balance(){
    printf("Account balance:%d",bal);
    menu();
    return 0;
}

int deposit(){
    int depo;
    printf("Input amount to deposit:");
    scanf("%d",&depo);
    bal=bal+depo;
    printf("New updated balance:%d\n",bal);
    menu();
    return 0;
}

int withdraw(){
    int with;
    printf("Input amount to withdraw:");
    scanf("%d",&with);
    if(with>bal){
        printf("Insufficient funds!!!\n");
        withdraw();
    }
    else{
        bal=bal-with;
        printf("New updated balance:%d\n",bal);
    }
    menu();
    return 0;
}

int leave(){
    printf("Thank you for visiting us!!Goodbye");
    return 0;
}