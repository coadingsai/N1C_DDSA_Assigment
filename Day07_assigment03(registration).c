//
// Created by Asus on 12/28/2023.
//
#include "stdio.h"
#include "stdlib.h"


void menu();

void login();

void login_checking(char l_mail[30],char l_pass[30]);

void registration();

void copy_two_charArray(char first[30],char second[30]);

int size_of_charArray(char arr[30]);

int compare_two_charArray(char first[30],char second[30]);

void user_account();

void store_status();



//Global Variable space
int g_user_count=0;

int g_login_checking=-1;


struct Db{
    char userName[30];
    char userEmail[30];
    char userPassword[20];
    int phoneNumber;

    char store[30];
};

struct Db data[10];

int main(){

    menu();

    return 0;
}

void menu(){
    while (1){
        printf("...........Welcome our system..........\n");

        int option=0;
        printf(" Enter:1 to login\n Enter:2 to register\n Enter:3 to exit our program\n Please enter a number:");
        scanf("%d",&option);

        if(option == 1){
            login();
        } else if(option == 2){
            registration();
        } else{
            exit(0);
        }
    }
}

void login(){
    printf("......login to your Register account......\n");

    char l_userEmail[30];
    char l_userPassword[20];
    printf("Enter your email to login:");
    scanf(" %[^\n]",&l_userEmail);

    printf("Enter your password to login:");
    scanf(" %[^\n]",&l_userPassword);

    login_checking(l_userEmail,l_userPassword);
    if(g_login_checking != -1){
        printf("login success\n");
        user_account();
    } else{
        printf("login fail\n");
        menu();
    }
}

void user_account(){
    printf("Welcome to your account\n");

    int action=0;
    printf("Enter:1 to logout\nEnter:2 to store status\n Enter:");
    scanf("%d",&action);

    if(action == 1){
        menu();
    } else if(action == 2){
        store_status();
    } else{
        printf("Wrong action....");
        user_account();
    }
}

void store_status(){
    printf("....Store status option....\n");

    char status[30];
    printf("type something to store here\n (Warning: only 30 words can store):");
    scanf(" %[^\n]",&status);

    //collection store status data

    copy_two_charArray(data[g_user_count].store,status);
    printf("check your status: %s\n",data[g_user_count].store);

    user_account();
}


void login_checking(char l_mail[30],char l_pass[20]){

    g_login_checking=-1;
   for(int i=0; i<g_user_count; i++){
       int email_check = compare_two_charArray(data[i].userEmail,l_mail);
       if(email_check == 1){
           int password_check = compare_two_charArray(data[i].userPassword,l_pass);
           if(password_check == 1){
               g_login_checking=i;
               break;
           }
       }
   }
}

void registration(){
    printf(".......Registeration option.......\n");

    char r_userName[30];
    char r_userEmail[30];
    char r_userpassword[20];
    int r_phoneNumber=0;

    printf("Enter your Name:");
    scanf(" %[^\n]",&r_userName);

    printf("Enter your Email:");
    scanf(" %[^\n]",&r_userEmail);

    printf("Enter your password:");
    scanf(" %[^\n]",&r_userpassword);

    printf("Enter your phone number:");
    scanf("%d",&r_phoneNumber);



    //collecting data part

    copy_two_charArray(data[g_user_count].userName,r_userName);
    printf("check your name : %s\n",data[g_user_count].userName);

    copy_two_charArray(data[g_user_count].userEmail,r_userEmail);
    printf("check your email : %s\n",data[g_user_count].userEmail);

    copy_two_charArray(data[g_user_count].userPassword,r_userpassword);
    printf("check your password : %s\n",data[g_user_count].userPassword);

    data[g_user_count].phoneNumber = r_phoneNumber;
    printf("check your phone number : %d\n",data[g_user_count].phoneNumber);

    printf(".........Registration Complete...........\n");

    //action
    g_user_count++;

}

void copy_two_charArray(char first[30],char second[30]){

    for(int i=0; i<30; i++){
        if(second[i] == '\0'){
            break;
        } else{
            first[i] = second[i];
        }
    }
}



int compare_two_charArray(char first[30],char second[30]){
     int sameCount=0;

     int size1 = size_of_charArray(first);
    int size2 = size_of_charArray(second);

     if(size1 == size2){
         for(int i=0; i<size2; i++){
             if(first[i] == second[i]){
                 sameCount++;
             }
         }
     }

     if(size2 == sameCount){
         return 1;
     } else{
         return 0;
     }
}

int size_of_charArray(char arr[30]){

    int size=0;

    for(int i=0; i<30; i++){
        if(arr[i] == '\0'){
            break;
        } else{
            size++;
        }
    }
    return size;
}