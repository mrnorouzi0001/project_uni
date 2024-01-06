#include<stdio.h>
#include<windows.h>
void sign_up(){
    system("cls");
    printf("        you will use this information for using the application\n");
    printf("\nPlease enter a user name: ");
    printf("\nPleas enter a password: ");
    printf("            personal information")
    printf("\nPlease enter your name: ");
    printf("\nPlease enter your last name: ");
    printf("\nPlease enter Your phone number: ");
    printf("\nPlease enter Your email:  ");
    printf("Are you sure you want to add this user to the application?")
    system("cls");
    Sleep(2000);
    printf("the user has added to the application successfully");
    System("cls");
}
void sign_in(){

}
void main_page(){
    system("cls");
    int checker = 0;
    printf("1. sign up\n");
    printf("2. sign in\n");
    printf("3. exit\n");
    scanf("%d" , &checker);
    switch(checker){
        case 1 :{
            sign_up();
            break;
        }
        case 2 :{
            sign_in();
            break;
        }
        case 3 :{
            exit(0);
            break;
        }
        default: {
            system("cls");
            printf("Please enter a valid option");
            Sleep(1000);

            main_page();
        }
    }

}
void main(){
    main_page();
}
