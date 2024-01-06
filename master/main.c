#include<stdio.h>
#include<windows.h>
void sign_up(){
    system("cls");
    printf("        you will use this information for using the application\n");
    printf("\nPlease enter a user name: ");
    printf("\nPleas enter a password: ");
    printf("            personal information");
    printf("\nPlease enter your name: ");
    printf("\nPlease enter your last name: ");
    printf("\nPlease enter Your phone number: ");
    printf("\nPlease enter Your email:  ");
    printf("Are you sure you want to add this user to the application?");
    system("cls");
    Sleep(2000);
    printf("the user has added to the application successfully!");
    system("cls");
}
void sign_in(){
    printf("Please enter your user name: ");
    printf("Please enter your password: ");
}
void Start_Page(){
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
void Main_Page(){
    printf("1. Adding new building");
    ptintf("2. Deleting the buildings");
    printf("3. Reports");
    printf("4. settings");
    printf("5. sign out");
}
void adding_page(){
    printf("1. For sale buildings");
    printf("2. For rent buildings");
    printf("3. For mortgage buildings");
    printf("4. back");
}
void sale_buildings(){
    printf("1. Residential buildings");
    printf("2. Commercial");
    printf("3. Normal filed");
    printf("4. back");
}
void adding_sale_buildings_Residential(){
    printf("PLease enter the municipality's area: ");
    printf("Please enter the address of building: ");
    printf("PLease enter model of building(apartment or Villa): ");
    printf("PLease enter age of building: ");
    printf("Please enter The size of the infrastructure: ");
    printf("PLease enter amount of floors: ");
    printf("PLease enter The size of the main land: ");
    printf("Please enter phone number of owner: ");
    printf("PLease enter amount of rooms: ");
    printf("PLease enter price: ");
}
void main(){
    Start_Page();
}
