#include<stdio.h>
#include<windows.h>
void sign_up(){
}
void sign_in(){

}
void main_page(){
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
            system("cls");
            main_page();
        }
    }

}
void main(){
    main_page();
}
