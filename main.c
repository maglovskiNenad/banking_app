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
    int choice;
    for(int i = 0; i < MAX_ACCOUNT; i++){
        if(strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0){
            printf("Welcome %s\n",accounts[i].username);
            printf("####################################\n");
            printf("Your balance is: %.2f\n",accounts[i].balance);
            printf("In this moment you have to pay: %.2f\n",accounts[i].payments);
            printf("####################################\n");
            printf("Your id:%s\n",accounts[i].id);
            printf("####################################\n");
            printf("\n"); 
        }
    }
    return 0;
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
    
void loggin(Account accounts[],char *username,char *password) {
    char username_input[10];
    char password_input[10];
    int entered_username = 1;
    int entered_password = 1;
    int choice;

    printf("Username:\n");
    while (1)
    {
        scanf("%s",username_input);
        if(isValidUsername(username_input)){
            entered_username = 0;
            break;
        }
    }

    printf("Password:\n");
    while (1)
    {
        //Ovde treba da se sakrije pasword
        scanf("%s",password_input);
        if(isValidPassword(password_input)){
            entered_password = 0;
            break;
        }
    }

    //U pitanju je infinitnvni loop ##########################################################################################
    while (1)
    {
        printf("-----------------------------------\n");
        printf("1.Balance\n2.Transwer\n1.Exit\n");
        printf("-----------------------------------\n");
        switch (choice){
            case 1:
                printf("-----------------------------------\n");
                balance(accounts,username_input,password_input);
                printf("-----------------------------------\n");
                break;
            case 2:
                printf("-----------------------------------\n");
                transfer();
                printf("-----------------------------------\n");
                break;
            case 3:
                loggout();
            default:
                errorMsg();
                break;
            }
     }
}
 
 //#############################################################################################################################

int findFreeIndex(Account accounts[]) {
    for(int i = 0; i < MAX_ACCOUNT; i++){
        if(accounts[i].id == 0){
            return i;
        }
    }
    return -1;
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

int transfer() {
    printf("Comming soon...\n");
    return 0;
}

int main() {
    intruducingApp();
    loggin(accounts,&username,&password);
    return 0;
}
