#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_ACCOUNT 10

char username;
char password;
int input_username;
int input_password;
int choice;
double money;

typedef struct{
    char id[10];
    char auth[10];
    char username[10];
    char password[100];
    char email[20];
    char address[20];
    double balance;
    double payments;
}Account; 

Account accounts[MAX_ACCOUNT] = {
        {
            .id = "001",
            .auth = "User",
            .username = "Jack",
            .password = "2233",
            .email = "jack@jacky.com",
            .address = "Titanic",
            .balance = 55.55,
            .payments = 45.66,
        },
        {
            .id = "002",
            .auth = "User",
            .username = "Sam",
            .password = "1122",
            .email = "sam@smith.com",
            .address = "Golden Samy",
            .balance = 5055.55,
            .payments = 45.66,
        },
        {
            .id = "007",
            .auth = "Admin",
            .username = "James",
            .password = "007",
            .email = "james@bond.com",
            .address = "Unknown",
            .balance = 9999,
            .payments = 00.00,
        },
    };

void intruducingApp() {
    printf("-----------------------------------\n");
    printf("    Simple banking application     \n");
    printf("-----------------------------------\n");
    printf("          Hello dear User          \n");
    printf("      Please chose the number      \n");
    printf("      ...So you can loggin...      \n");
    printf("-----------------------------------\n");
}


int balance(Account accounts[],char *username,char *password) {
    for(int i = 0; i < MAX_ACCOUNT; i++){
        if(strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0){
            printf("Welcome %s\n",accounts[i].username);
            printf("####################################\n");
            printf("Your balance is: %.2f\n",accounts[i].balance);
            printf("In this moment you have to pay: %.2f\n",accounts[i].payments);
            printf("####################################\n");
            printf("You have biling proces for:% ld",accounts[i].payments);
            printf("Your id:%s\n",accounts[i].id);
            printf("####################################\n");
            printf("\n");
            printf("1.Transver\n2.Request new or Credit card\n3.Exit\n");
            int choice;
            printf("Chose: ");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1:
                    transfer(accounts,accounts[i].username,accounts[i].password);
                    break;
                case 2:
                    cardRequesting(accounts,accounts[i].username,accounts[i].password);
                    break;
                case 3:
                    loggout();
                    break;
                default:
                    errorMsg();

            }
        }
              
    }
    return 0;
}

void cardRequesting(Account accounts[],char *username,char *password) {
    int choice;
    douboe answerMone;
    
    printf("We have a few questions for you...\n");
    printf("How much do you earn?");
    scanf("%lf",answerMonet);
    printf("Which Card would you like to have:\n1.Gold\n2.Regular\n3.Exit\n");
    scanf("%d",&choice);
    if(choice == 1){
        printf("1");
    }else if(choice == 2){
        printf("2");
    }else if(choce == 3){
        printf("3");
    }
    printf("Comming soon");
}

int isValidPassword(char *password) {
    int lenght = strlen(password);
    int has_upper = 0;
    int has_lower = 0;
    int  has_special = 0;

    for(int i = 0; i < lenght; i++){
        if(isupper(password[i])) has_upper = 1;
        if(islower(password[i])) has_lower = 1;
        if(ispunct(password[i])) has_special = 1;
    }

    if(has_upper && has_lower && has_special){
        return 0;
    }else{
        return 1;
    }
}
 
int isValidUsername(char *username) {
    int length = strlen(username);

    if(length < 0 && length > 10){
        return 0;
    }

    for(int i = 0; i < length; i++){
        if(!isalnum(username[i])){
            return 0;
        }
    }
    return 1;
}

void loggout() {
    printf("-----------------------------------\n");
    printf("       ...Exiting program...       \n");
    printf("-----------------------------------\n");
    exit(0);
}

void errorMsg() {
    printf("-----------------------------------\n");
    printf("       ...Invalid choice...        \n");
    printf("-----------------------------------\n");
}

void transferCheck(Account accounts[],char *username,double *money) {  
        double getMoney;
        printf("-----------------------------------\n");
        printf("   ...Transfering please wait...   \n");
        printf("-----------------------------------\n");
        for(int i = 0; i < MAX_ACCOUNT; i++){
            if (strcmp(accounts[i].username,username) == 0)
            {
                getMoney = accounts[i].balance + *money;
                accounts[i].balance = getMoney;
            }else{
                errorMsg();
            }
        }
}

void transfer(Account accounts[],char *username,char *password) {
    double sentMoney;
    char person[10];
    int choice;
    double moneyIsSent;

    printf("How much money would you like to send:");
    scanf("%lf",&sentMoney);
    printf("The persin which you send money would be:");
    scanf("%s",person);

    for(int i = 0; i < MAX_ACCOUNT; i++){
        if(strcmp(accounts[i].username,username) == 0 && strcmp(accounts[i].password,password) == 0){
            printf("You are sending %lf\n",sentMoney);
            printf("The name of person is: %s\n",person);
            printf("If your answer is yes press 1, or if your answer is no press 2:");
            scanf("%d",&choice);

            if(choice == 1 && accounts[i].balance > sentMoney && accounts[i].balance > 0){
                moneyIsSent = accounts[i].balance - sentMoney;
                accounts[i].balance = moneyIsSent;
                transferCheck(accounts,person,&sentMoney);
            }else{
                printf("-----------------------------------\n");
                printf("...............Decline.............\n");
                printf("-----------------------------------\n");
            }
        }  
    }
}


void loggin(Account accounts[],char *username,char *password) {
    char username_input[10];
    char password_input[10];
    int entered_username = 1;
    int entered_password = 1;
    int choice;

    printf("Username: ");
    while (1)
    {
        scanf("%s",username_input);
        if(isValidUsername(username_input)){
            entered_username = 0;
            break;
        }
    }

    printf("Password: ");
    while (1)
    {
        scanf("%s",password_input);
        if(isValidPassword(password_input)){
            entered_password = 0;
            break;
        }
    }
    
    if(entered_username == 0 && entered_password == 0){
            balance(accounts,username_input,password_input);
        }else{
            errorMsg();
        }
}

int main() {
    int choice;
    intruducingApp();
    loggin(accounts,&username,&password);
    return 0;
}
