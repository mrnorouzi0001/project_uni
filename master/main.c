#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void Start_Page();
void make_list_user(FILE *user_fp);
struct building_sale
{
    char municipalitys_area[6];
    char address_of_building[100];
    char model[20];
    char age_of_building[6];
    char size_of_the_infrastructure[10];
    char amount_of_floors[6];
    char size_of_the_main_land[10];
    char phone_number_of_owner[15];
    char amount_of_rooms[6];
    char price[15];
    char user[30];
    unsigned long int time;
    char isactive[3];
    char id[7];
    unsigned long int time_delete;
    struct building_sale *link;
}*start_building_sale = NULL, *last_building_sale;
struct building_rent
{
    char municipalitys_area[6];
    char address_of_building[100];
    char model[20];
    char age_of_building[6];
    char size_of_the_infrastructure[10];
    char amount_of_floors[6];
    char size_of_the_main_land[10];
    char phone_number_of_owner[15];
    char amount_of_rooms[6];
    char prepayment[15];
    char rent_per_month[15];
    char user[30];
    unsigned long int time;
    char isactive[3];
    char id[7];
    unsigned long int time_delete;
    struct building_rent *link;
}*start_building_rent, *last_building_rent;
struct user
{
    char user_name[30];
    char password[20];
    char name[25];
    char last_name[45];
    char phone[12];
    char email[35];
    unsigned long int time_login;
    unsigned long int time_logout;
    int registered_builiding;
    struct user *link;
}*start_user, *last_user;

typedef struct building_sale BUILDING_SALE;
typedef struct user USER;
typedef struct building_rent BUILDING_RENT;

USER *current_user;
int inner_flag = 0;
void sign_up()
{
    char temp_time[31] , option;
    system("cls");
    FILE *user_fp;
    user_fp = fopen("Files\\users\\user.txt", "a+");
    if(user_fp == NULL)
    {
        printf("There is a problem with user file. the program will restart itself");
        free(user_fp);
        exit(0);
    }
    USER *user;
    user = malloc(sizeof(USER));
    printf("        you will use this information for using the application\n");
    printf("\nPlease enter a user name: ");
    gets(user->user_name);
    printf("\nPleas enter a password: ");
    gets(user->password);
    printf("\n            personal information\n");
    printf("\nPlease enter your name: ");
    gets(user->name);
    printf("\nPlease enter your last name: ");
    gets(user->last_name);
    printf("\nPlease enter Your phone number: ");
    gets(user->phone);
    printf("\nPlease enter Your email:  ");
    gets(user->email);
    printf("Are you sure you want to add this user to the application?(Y/N)");
    while(1){
         option = getchar();
        if(option == 'Y' || option == 'y')
        {
        fputs(user->user_name, user_fp);
        fputs("\n", user_fp);
        fputs(user->password, user_fp);
        fputs("\n", user_fp);
        fputs(user->name, user_fp);
        fputs("\n", user_fp);
        fputs(user->last_name, user_fp);
        fputs("\n", user_fp);
        fputs(user->phone, user_fp);
        fputs("\n", user_fp);
        fputs(user->email, user_fp);
        fputs("\n", user_fp);
        itoa(time(NULL) , temp_time , 10);
        fputs(temp_time , user_fp);
        fputs("\n" , user_fp);
        fputs("0" , user_fp);
        fputs("\n" , user_fp);
        system("cls");
        Sleep(2000);
        printf("the user has added to the application successfully!");
        free(user);
        free(user_fp);
        fclose(user_fp);
        Sleep(2000);
        Start_Page();
    }
    if(option == 'N' || option == 'n')
    {
        free(user);
        free(user_fp);
        system("cls");
        Start_Page();
    }
    else{
        printf("Please enter a valid character");
    }
    }

}
void sign_in()
{
    system("cls");
    char time_tmep[30];
    FILE *user_fp;
    USER *temp;
    user_fp = fopen("Files\\users\\user.txt", "r");
    if(user_fp == NULL)
    {
        printf("There is a problem with user file. the program will restart itself");
        free(user_fp);
        fclose(user_fp);
        exit(0);
    }
    char user_name[30], password[25];
    printf("Please enter your user name: ");
    gets(user_name);
    strcat(user_name, "\n");
    make_list_user(user_fp);
    int tries = 0;
    if(search_username_list_user(user_name) == 1)
    {
        while(1)
        {
            printf("Please enter your password: ");
            gets(password);
            strcat(password, "\n");
            if(search_password_list_user(user_name,password) == 1)
            {
                break;
            }
            else
            {
                printf("wrong password! %d tries left!\n", tries + 1);
                tries++;
            }
        }
        printf("logging in. please wait!");
        fclose(user_fp);
        user_fp = fopen("Files\\users\\user.txt" , "w+");
        temp = start_user;
        while(temp != NULL){
        fputs(temp->user_name, user_fp);
        fputs("\n", user_fp);
        fputs(temp->password, user_fp);
        fputs("\n", user_fp);
        fputs(temp->name, user_fp);
        fputs("\n", user_fp);
        fputs(temp->last_name, user_fp);
        fputs("\n", user_fp);
        fputs(temp->phone, user_fp);
        fputs("\n", user_fp);
        fputs(temp->email, user_fp);
        fputs("\n", user_fp);
        itoa(temp->time_login , time_tmep , 10);
        fputs(time_tmep , user_fp);
        fputs("\n" , user_fp);
        itoa(temp->time_login , time_tmep , 10);
        fputs(time_tmep , user_fp);
        fputs("\n" , user_fp);
        }
        Sleep(2000);
        fclose(user_fp);
        make_null_list_user();
        system("cls");
        main_page();
    }
    else
    {
        printf("we don't have this user name!");
        Sleep(2000);
        fclose(user_fp);
        Start_Page();
    }
}
void main_page()
{
    int option = 0;
    system("cls");
    printf("1. Adding new building\n");
    printf("2. Deleting the buildings\n");
    printf("3. Reports\n");
    printf("4. settings\n");
    printf("5. sign out\n");
    printf("Please choice your option: ");
    scanf("%d", &option);
    getchar();
    switch(option)
    {
    case 1:
    {
        menu_adding_building();
        break;
    }
    case 2:
    {
        menu_delete_building();
    }
    case 3:
    {
            if(strcmp(current_user->user_name , "admin\n") == 0){
                page_admin_report();
            }
            else{
                page_reports_normal();
            }
            break;
    }
    case 4:
    {
        user_edit();
        break;
    }
    case 5:
    {
        logout_time();
        free(current_user);
        printf("Logging out");
        Sleep(2000);
        Start_Page();
    }
    default:
    {
        printf("Please enter a valid option");
        Sleep(2000);
        system("cls");
        main_page();
    }
    }
}
void logout_time(){
    char time_tmep[30];
    current_user->time_logout = time(NULL);
    FILE *user_fp;
    USER *temp;
    user_fp = fopen("Files\\user\\user.txt" , "r+");
    make_list_user(user_fp);
    fclose(user_fp);
    user_fp = fopen("Files\\user\\user.txt" , "w+");
    temp = start_user;
    while(temp != NULL){
        fputs(temp->user_name, user_fp);
        fputs("\n", user_fp);
        fputs(temp->password, user_fp);
        fputs("\n", user_fp);
        fputs(temp->name, user_fp);
        fputs("\n", user_fp);
        fputs(temp->last_name, user_fp);
        fputs("\n", user_fp);
        fputs(temp->phone, user_fp);
        fputs("\n", user_fp);
        fputs(temp->email, user_fp);
        fputs("\n", user_fp);
        itoa(temp->time_login , time_tmep , 10);
        fputs(time_tmep , user_fp);
        fputs("\n" , user_fp);
        itoa(temp->time_login , time_tmep , 10);
        fputs(time_tmep , user_fp);
        fputs("\n" , user_fp);
        itoa(time(NULL) , time_tmep , 10);
        fputs(time_tmep , user_fp);
        fputs("\n" , user_fp);
    }
    fclose(user_fp);
}
void Start_Page()
{
    system("cls");
    int checker = 0;
    printf("1. sign up\n");
    printf("2. sign in\n");
    printf("3. exit\n");
    scanf("%d", &checker);
    getchar();
    switch(checker)
    {
    case 1 :
    {
        sign_up();
        break;
    }
    case 2 :
    {
        sign_in();
        break;
    }
    case 3 :
    {
        exit(0);
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option");
        Sleep(1000);
        Start_Page();
    }
    }
}
void menu_adding_building()
{
    int checker = 0;
    system("cls");
    printf("1. For sale buildings\n");
    printf("2. For rent buildings\n");
    printf("3. back\n");
    printf("Please choice your option: ");
    scanf("%d", &checker);
    getchar();
    switch(checker)
    {
    case 1 :
    {
        menu_sale_buildings();
        break;
    }
    case 2 :
    {
        menu_rent_buildings();
        break;
    }
    case 3 :
    {
        main_page();
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option");
        Sleep(1000);
        menu_adding_building();
    }
    }
}
void menu_sale_buildings()
{
    system("cls");
    int checker = 0;
    printf("1. Residential buildings\n");
    printf("2. Commercial\n");
    printf("3. Normal filed\n");
    printf("4. back\n");
    printf("Please choice your option: ");
    scanf("%d", &checker);
    getchar();
    switch(checker)
    {
    case 1 :
    {
        adding_sale_buildings_Residential();
        break;
    }
    case 2 :
    {
        adding_sale_buildings_commercial();
        break;
    }
    case 3 :
    {
        adding_sale_buildings_filed();
        break;
    }
    case 4:
    {
        menu_adding_building();
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option");
        Sleep(1000);
        menu_sale_buildings();
    }
    }
}
void adding_sale_buildings_Residential()
{
    int id = 0;
    char char_id[7], temp[25];
    system("cls");
    FILE *file_sale_res, *file_ID;
    file_sale_res = fopen("Files\\building\\for_sale\\Residential.txt", "a+");
    file_ID = fopen("Files\\building\\ID.txt", "r+");
    BUILDING_SALE *building;
    building = malloc(sizeof(BUILDING_SALE));
    printf("Please enter the municipality's area: ");
    gets(building->municipalitys_area);
    printf("Please enter the address of building: ");
    gets(building->address_of_building);
    printf("Please enter model of building(apartment or villa): ");
    gets(building->model);
    printf("Please enter age of building: ");
    gets(building->age_of_building);
    printf("Please enter The size of the infrastructure: ");
    gets(building->size_of_the_infrastructure);
    printf("Please enter amount of floors: ");
    gets(building->amount_of_floors);
    printf("Please enter The size of the main land: ");
    gets(building->size_of_the_main_land);
    printf("Please enter phone number of owner: ");
    gets(building->phone_number_of_owner);
    printf("Please enter amount of rooms: ");
    gets(building->amount_of_rooms);
    printf("Please enter price: ");
    gets(building->price);
    strcpy(building->user, current_user->user_name);
    building->time = time(NULL);
    strcpy(building->isactive, "1");
    fgets(building->id, 7, file_ID);
    id = atoi(building->id);
    id++;
    itoa(id,char_id,10);
    fclose(file_ID);
    file_ID = fopen("Files\\building\\ID.txt", "w+");
    fputs(char_id, file_ID);
    printf("\nAre you sure you want to add this building to your sale list?(Y/N)");
    if(getchar() == 'Y')
    {
        system("cls");
        printf("processing");
        Sleep(2000);
        fputs(building->municipalitys_area, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->address_of_building, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->model, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->age_of_building, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->size_of_the_infrastructure, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->amount_of_floors, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->size_of_the_main_land, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->phone_number_of_owner, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->amount_of_rooms, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->price, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->user, file_sale_res);
        itoa(building->time, temp, 10);
        fputs(temp, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->isactive, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->id, file_sale_res);
        fputs("\n", file_sale_res);
        fputs("0", file_sale_res);
        fputs("\n", file_sale_res);
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        system("cls");
        printf("building has added successfully");
        Sleep(2000);
        menu_sale_buildings();
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        menu_sale_buildings();
    }

}
void adding_sale_buildings_commercial()
{
    int id = 0;
    char char_id[7], temp[25];
    system("cls");
    FILE *file_sale_res, *file_ID;
    file_sale_res = fopen("Files\\building\\for_sale\\Commercial.txt", "a+");
    file_ID = fopen("Files\\building\\ID.txt", "r+");
    BUILDING_SALE *building;
    building = malloc(sizeof(BUILDING_SALE));
    printf("Please enter the municipality's area: ");
    gets(building->municipalitys_area);
    printf("Please enter the address of building: ");
    gets(building->address_of_building);
    printf("Please enter model of building: ");
    gets(building->model);
    printf("Please enter age of building: ");
    gets(building->age_of_building);
    printf("Please enter The size of the infrastructure: ");
    gets(building->size_of_the_infrastructure);
    printf("Please enter amount of floors: ");
    gets(building->amount_of_floors);
    printf("Please enter The size of the main land: ");
    gets(building->size_of_the_main_land);
    printf("Please enter phone number of owner: ");
    gets(building->phone_number_of_owner);
    printf("Please enter amount of rooms: ");
    gets(building->amount_of_rooms);
    printf("Please enter price: ");
    gets(building->price);
    strcpy(building->user, current_user->user_name);
    building->time = time(NULL);
    strcpy(building->isactive, "1");
    fgets(building->id, 7, file_ID);
    id = atoi(building->id);
    id++;
    itoa(id,char_id,10);
    fclose(file_ID);
    file_ID = fopen("Files\\building\\ID.txt", "w+");
    fputs(char_id, file_ID);
    printf("\nAre you sure you want to add this building to your sale list?(Y/N)");
    if(getchar() == 'Y')
    {
        system("cls");
        printf("processing");
        Sleep(2000);
        fputs(building->municipalitys_area, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->address_of_building, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->model, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->age_of_building, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->size_of_the_infrastructure, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->amount_of_floors, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->size_of_the_main_land, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->phone_number_of_owner, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->amount_of_rooms, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->price, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->user, file_sale_res);
        itoa(building->time, temp, 10);
        fputs(temp, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->isactive, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->id, file_sale_res);
        fputs("\n", file_sale_res);
        fputs("0", file_sale_res);
        fputs("\n", file_sale_res);
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        system("cls");
        printf("building has added successfully");
        Sleep(2000);
        menu_sale_buildings();
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        menu_sale_buildings();
    }
}
void adding_sale_buildings_filed()
{
    int id = 0;
    char char_id[7], temp[25];
    system("cls");
    FILE *file_sale_res, *file_ID;
    file_sale_res = fopen("Files\\building\\for_sale\\Filed.txt", "a+");
    file_ID = fopen("Files\\building\\ID.txt", "r+");
    BUILDING_SALE *building;
    building = malloc(sizeof(BUILDING_SALE));
    printf("Please enter the municipality's area: ");
    gets(building->municipalitys_area);
    printf("Please enter the address of filed: ");
    gets(building->address_of_building);
    printf("Please enter model of filed(farm or in-city): ");
    gets(building->model);
    printf("Please enter The size of the infrastructure: ");
    gets(building->size_of_the_infrastructure);
    printf("Please enter phone number of owner: ");
    gets(building->phone_number_of_owner);
    printf("Please enter price: ");
    gets(building->price);
    strcpy(building->user, current_user->user_name);
    building->time = time(NULL);
    strcpy(building->isactive, "1");
    fgets(building->id, 7, file_ID);
    id = atoi(building->id);
    id++;
    itoa(id,char_id,10);
    fclose(file_ID);
    file_ID = fopen("Files\\building\\ID.txt", "w+");
    fputs(char_id, file_ID);
    printf("\nAre you sure you want to add this building to your sale list?(Y/N)");
    if(getchar() == 'Y')
    {
        system("cls");
        printf("processing");
        Sleep(2000);
        fputs(building->municipalitys_area, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->address_of_building, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->model, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->size_of_the_infrastructure, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->phone_number_of_owner, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->price, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->user, file_sale_res);
        itoa(building->time, temp, 10);
        fputs(temp, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->isactive, file_sale_res);
        fputs("\n", file_sale_res);
        fputs(building->id, file_sale_res);
        fputs("\n", file_sale_res);
        fputs("0", file_sale_res);
        fputs("\n", file_sale_res);
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        system("cls");
        printf("building has added successfully");
        Sleep(2000);
        menu_sale_buildings();
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        menu_sale_buildings();
    }
}
void menu_rent_buildings()
{
    system("cls");
    int checker = 0;
    printf("1. Residential buildings\n");
    printf("2. Commercial\n");
    printf("3. Normal filed\n");
    printf("4. back\n");
    printf("Please choice your option: ");
    scanf("%d", &checker);
    getchar();
    switch(checker)
    {
    case 1 :
    {
        adding_rent_buildings_Residential();
        break;
    }
    case 2 :
    {
        adding_rent_buildings_commercial();
        break;
    }
    case 3 :
    {
        adding_rent_buildings_filed();
        break;
    }
    case 4:
    {
        menu_adding_building();
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option");
        Sleep(1000);
        menu_rent_buildings();
    }
    }
}
void adding_rent_buildings_Residential()
{
    int id = 0;
    char char_id[7], temp[25];
    system("cls");
    FILE *file_rent_res, *file_ID;
    file_rent_res = fopen("Files\\building\\for_rent\\Residential.txt", "a+");
    file_ID = fopen("Files\\building\\ID.txt", "r+");
    BUILDING_RENT *building;
    building = malloc(sizeof(BUILDING_RENT));
    printf("Please enter the municipality's area: ");
    gets(building->municipalitys_area);
    printf("Please enter the address of building: ");
    gets(building->address_of_building);
    printf("Please enter model of building(apartment or villa): ");
    gets(building->model);
    printf("Please enter age of building: ");
    gets(building->age_of_building);
    printf("Please enter The size of the infrastructure: ");
    gets(building->size_of_the_infrastructure);
    printf("Please enter amount of floors: ");
    gets(building->amount_of_floors);
    printf("Please enter The size of the main land: ");
    gets(building->size_of_the_main_land);
    printf("Please enter phone number of owner: ");
    gets(building->phone_number_of_owner);
    printf("Please enter amount of rooms: ");
    gets(building->amount_of_rooms);
    printf("Please enter prepayment: ");
    gets(building->prepayment);
    printf("Please enter pay per month(for mortgage only enter 0): ");
    gets(building->rent_per_month);
    strcpy(building->user, current_user->user_name);
    building->time = time(NULL);
    strcpy(building->isactive, "1");
    fgets(building->id, 7, file_ID);
    id = atoi(building->id);
    id++;
    itoa(id,char_id,10);
    fclose(file_ID);
    file_ID = fopen("Files\\building\\ID.txt", "w+");
    fputs(char_id, file_ID);
    printf("\nAre you sure you want to add this building to your sale list?(Y/N)");
    if(getchar() == 'Y')
    {
        system("cls");
        printf("processing");
        Sleep(2000);
        fputs(building->municipalitys_area, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->address_of_building, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->model, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->age_of_building, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->size_of_the_infrastructure, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->amount_of_floors, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->size_of_the_main_land, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->phone_number_of_owner, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->amount_of_rooms, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->prepayment, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->rent_per_month, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->user, file_rent_res);
        itoa(building->time, temp, 10);
        fputs(temp, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->isactive, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->id, file_rent_res);
        fputs("\n", file_rent_res);
        fputs("0", file_rent_res);
        fputs("\n", file_rent_res);
        free(building);
        fclose(file_ID);
        fclose(file_rent_res);
        system("cls");
        printf("building has added successfully");
        Sleep(2000);
        menu_rent_buildings();
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_rent_res);
        menu_rent_buildings();
    }
}
void adding_rent_buildings_commercial()
{
    int id = 0;
    char char_id[7], temp[25];
    system("cls");
    FILE *file_rent_res, *file_ID;
    file_rent_res = fopen("Files\\building\\for_rent\\Commercial.txt", "a+");
    file_ID = fopen("Files\\building\\ID.txt", "r+");
    BUILDING_RENT *building;
    building = malloc(sizeof(BUILDING_RENT));
    printf("Please enter the municipality's area: ");
    gets(building->municipalitys_area);
    printf("Please enter the address of building: ");
    gets(building->address_of_building);
    printf("Please enter model of building: ");
    gets(building->model);
    printf("Please enter age of building: ");
    gets(building->age_of_building);
    printf("Please enter The size of the infrastructure: ");
    gets(building->size_of_the_infrastructure);
    printf("Please enter amount of floors: ");
    gets(building->amount_of_floors);
    printf("Please enter The size of the main land: ");
    gets(building->size_of_the_main_land);
    printf("Please enter phone number of owner: ");
    gets(building->phone_number_of_owner);
    printf("Please enter amount of rooms: ");
    gets(building->amount_of_rooms);
    printf("Please enter prepayment: ");
    gets(building->prepayment);
    printf("Please enter pay per month(for mortgage only enter 0): ");
    gets(building->rent_per_month);
    strcpy(building->user, current_user->user_name);
    building->time = time(NULL);
    strcpy(building->isactive, "1");
    fgets(building->id, 7, file_ID);
    id = atoi(building->id);
    id++;
    itoa(id,char_id,10);
    fclose(file_ID);
    file_ID = fopen("Files\\building\\ID.txt", "w+");
    fputs(char_id, file_ID);
    printf("\nAre you sure you want to add this building to your sale list?(Y/N)");
    if(getchar() == 'Y')
    {
        system("cls");
        printf("processing");
        Sleep(2000);
        fputs(building->municipalitys_area, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->address_of_building, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->model, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->age_of_building, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->size_of_the_infrastructure, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->amount_of_floors, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->size_of_the_main_land, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->phone_number_of_owner, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->amount_of_rooms, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->prepayment, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->rent_per_month, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->user, file_rent_res);
        itoa(building->time, temp, 10);
        fputs(temp, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->isactive, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->id, file_rent_res);
        fputs("\n", file_rent_res);
        fputs("0", file_rent_res);
        fputs("\n", file_rent_res);
        free(building);
        fclose(file_ID);
        fclose(file_rent_res);
        system("cls");
        printf("building has added successfully");
        Sleep(2000);
        menu_rent_buildings();
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_rent_res);
        menu_rent_buildings();
    }
}
void adding_rent_buildings_filed()
{
    int id = 0;
    char char_id[7], temp[25];
    system("cls");
    FILE *file_rent_res, *file_ID;
    file_rent_res = fopen("Files\\building\\for_rent\\Filed.txt", "a+");
    file_ID = fopen("Files\\building\\ID.txt", "r+");
    BUILDING_RENT *building;
    building = malloc(sizeof(BUILDING_RENT));
    printf("Please enter the municipality's area: ");
    gets(building->municipalitys_area);
    printf("Please enter the address of building: ");
    gets(building->address_of_building);
    printf("Please enter model of building(farm or in-city): ");
    gets(building->model);
    printf("Please enter The size of the infrastructure: ");
    gets(building->size_of_the_infrastructure);
    printf("Please enter phone number of owner: ");
    gets(building->phone_number_of_owner);
    printf("Please enter prepayment: ");
    gets(building->prepayment);
    printf("Please enter pay per month(for mortgage only enter 0): ");
    gets(building->rent_per_month);
    strcpy(building->user, current_user->user_name);
    building->time = time(NULL);
    strcpy(building->isactive, "1");
    fgets(building->id, 7, file_ID);
    id = atoi(building->id);
    id++;
    itoa(id,char_id,10);
    fclose(file_ID);
    file_ID = fopen("Files\\building\\ID.txt", "w+");
    fputs(char_id, file_ID);
    printf("\nAre you sure you want to add this building to your sale list?(Y/N)");
    if(getchar() == 'Y')
    {
        system("cls");
        printf("processing");
        Sleep(2000);
        fputs(building->municipalitys_area, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->address_of_building, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->model, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->size_of_the_infrastructure, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->phone_number_of_owner, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->prepayment, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->rent_per_month, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->user, file_rent_res);
        itoa(building->time, temp, 10);
        fputs(temp, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->isactive, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->id, file_rent_res);
        fputs("\n", file_rent_res);
        fputs(building->id, file_rent_res);
        fputs("\n", file_rent_res);
        fputs("0", file_rent_res);
        fputs("\n", file_rent_res);
        free(building);
        fclose(file_ID);
        fclose(file_rent_res);
        system("cls");
        printf("building has added successfully");
        Sleep(2000);
        menu_rent_buildings();
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_rent_res);
        menu_rent_buildings();
    }
}
void page_admin_report()
{
    int option;

    printf("1. Specific model of buildings\n");
    printf("2. Buildings with Specific area\n");
    printf("3. Buildings with Specific age\n");
    printf("4. Buildings with Specific infrastructure size\n");
    printf("5. Buildings with Specific prices\n");
    printf("6. Buildings with Specific Room's amount\n");
    printf("7. Total price of building\n");
    printf("8. Buildings with Specific rent and mortgage price\n");
    printf("9. Users Financial turnover\n");
    printf("10. Date of registered buildings\n");
    printf("11. Buildings with Specific floors\n");
    printf("12. Deleted buildings\n");
    printf("13. Users activity\n");
    printf("Please choice your report: ");
    scanf("%d" , &option);
    switch(option){
        case 1:{
            report_model_main();
            break;
        }
        case 2:{
        inner_flag = 0;
        char chose[12];
        printf("Please enter a municipalitys area: ");
        gets(chose);
        strcat(chose , "\n");
        system("cls");
        report_sale_residential_area(chose);
        report_sale_commercial_area(chose);
        report_rent_residential_area(chose);
        report_rent_commercial_area(chose);
        report_rent_filed_area(chose);
        report_sale_filed_area(chose);
        break;
        }
        case 3:{
            inner_flag = 0;
            char age_start[6] , age_finish[6];
            printf("Please the start of age range: ");
            gets(age_start);
            printf("Please the end of age range:(if you wish to only look for a specific age enter 0 for this filed)");
            gets(age_finish);
            system("cls");
            report_sale_residential_age(age_start , age_finish);
            report_sale_commercial_age(age_start , age_finish);
            report_rent_residential_age(age_start , age_finish);
            report_rent_commercial_age(age_start , age_finish);
        }
        case 4:{
            inner_flag = 0;
            char size_start[6] , size_finish[6];
            printf("Please the start of size range: ");
            gets(size_start);
            printf("Please the end of size range:(if you wish to only look for a specific age enter 0 for this filed)");
            gets(size_finish);
            system("cls");
            report_sale_residential_size(size_start , size_finish);
            report_sale_commercial_size(size_start , size_finish);
            report_rent_filed_size(size_start , size_finish);
            report_rent_residential_size(size_start , size_finish);
            report_rent_commercial_size(size_start , size_finish);
            report_sale_filed_size(size_start , size_finish);
        }
        case 5:{
            inner_flag = 0;
            char price_start[6] , price_finish[6];
            printf("Please the start of price range: ");
            gets(price_start);
            printf("Please the end of price range:(if you wish to only look for a specific age enter 0 for this filed)");
            gets(price_finish);
            system("cls");
            report_sale_residential_price(price_start , price_finish);
            report_sale_commercial_price(price_start , price_finish);
            report_sale_filed_price(price_start , price_finish);
        }
    }
}
void report_rent_residential_age(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        age_file = atoi(temp->age_of_building);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            inner_flag++;
            }

        }
        temp = temp->link;
    }
    make_null_list_building_rent();
}
void report_rent_commercial_age(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        age_file = atoi(temp->age_of_building);

        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            inner_flag++;
            }

        }
        temp = temp->link;


    }
    make_null_list_building_rent();
    if(inner_flag == 0){
        printf("There is no item to show!\n");

    }
        printf("For getting back press any key.....");
        getchar();
        if(strcmp("admin\n" , current_user->user_name) == 0){
            page_admin_report();
        }
        else{
            page_reports_normal();
        }

}
void report_rent_residential_size(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        age_file = atoi(temp->size_of_the_infrastructure);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            inner_flag++;
            }

        }
        temp = temp->link;
    }
    make_null_list_building_rent();
}
void report_rent_commercial_size(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        age_file = atoi(temp->size_of_the_infrastructure);

        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            inner_flag++;
            }

        }
        temp = temp->link;
    }
    make_null_list_building_rent();
}
void report_rent_filed_size(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        age_file = atoi(temp->size_of_the_infrastructure);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            inner_flag++;
            }
       }
        temp = temp->link;
    }
        make_null_list_building_rent();

}
void report_sale_residential_size(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atoi(temp->size_of_the_infrastructure);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
            }
        }
        temp = temp->link;
    }
        make_null_list_building_sale();
}
void report_sale_commercial_size(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atoi(temp->size_of_the_infrastructure);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
            }
        }
        temp = temp->link;
    }
        make_null_list_building_sale();
}
void report_sale_filed_size(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atoi(temp->size_of_the_infrastructure);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
            }
        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    if(inner_flag == 0){
        printf("There is no item to show!\n");
    }
        printf("For getting back press any key.....");
        getchar();
        if(strcmp(current_user->user_name , "admin\n")==0){
            page_admin_report();
        }
        else{
            page_reports_normal();
        }

}
void report_sale_residential_age(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atoi(temp->age_of_building);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
            }

        }
        temp = temp->link;
    }
        make_null_list_building_sale();
}
void report_sale_residential_price(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atoi(temp->price);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
            }

        }
        temp = temp->link;
    }
        make_null_list_building_sale();
}
void report_sale_commercial_price(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atoi(temp->price);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
            }
        }
        temp = temp->link;
    }
        make_null_list_building_sale();
}
void report_sale_filed_price(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atoi(temp->price);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
            }
        }
        temp = temp->link;
    }
    if(inner_flag == 0){
        printf("There is no item to show!\n");
    }
        make_null_list_building_sale();
        printf("For getting back press any key.....");
        getchar();
        if(strcmp(current_user->user_name , "admin\n")== 0){
                page_admin_report();
        }
        else{
            page_reports_normal();
        }

}
void report_sale_commercial_age(char start_age[6] , char end_age[6]){
    int age_start , age_end ,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atoi(temp->age_of_building);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end){
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
            }
        }
        temp = temp->link;
    }
        make_null_list_building_sale();
}
void report_rent_residential_area(char chose[30]){
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area , chose) == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_rent();
}
void report_rent_commercial_area(char chose[30]){
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {

        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area , chose) == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
        make_null_list_building_rent();

}
void report_rent_filed_area(char chose [30]){
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area , chose) == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
        make_null_list_building_rent();

}
void report_sale_residential_area(char chose[30]){
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area , chose) == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
        make_null_list_building_sale();
}
void report_sale_commercial_area(char chose[30]){
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area , chose) == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
        make_null_list_building_sale();
}
void report_sale_filed_area(char chose[30]){
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area , chose) == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Price: %s", temp->price);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
     make_null_list_building_sale();
    if(inner_flag == 0){
        printf("There is no item to show!\n");
    }
        printf("For getting back press any key.....");
        getchar();
        if(strcmp("admin\n" , current_user->user_name) == 0){
            page_admin_report();
        }
        else{
            page_reports_normal();
        }

}
void report_model_main(){
    int option;
    printf("1. For sale\n");
    printf("2. For rent\nl");
    printf("3. Back\n");
    printf("Please chose an option: ");
    scanf("%d" , &option);
    getchar();
    switch(option){
    case 1:{
        report_model_building_model_sale();
        break;
    }
    case 2:{
        report_model_building_model_rent();
        break;
    }
    case 3:{
        if(strcmp("admin\n" , current_user->user_name) == 0){
            page_admin_report();
        }
        else{
            page_reports_normal();
        }
        break;
    }
    default:{
        printf("Please enter a valid option!");
        Sleep(1000);
        system("cls");
        report_model_main();
    }
    }
}
void report_model_building_model_sale()
{
    int option;
    printf("1. Residential buildings\n");
    printf("2. Commercial\nl");
    printf("3. Normal filed\n");
    printf("4. back\n");
    printf("Please chose an option: ");
    scanf("%d" , &option);
    getchar();
    switch(option){
    case 1:{
        report_sale_residential();
        break;
    }
    case 2:{
        report_sale_commercial();
        break;
    }
    case 3:{
        report_sale_filed();
        break;
    }
    case 4:{
        report_model_main();
        break;
    }
    default:{
        printf("Please enter a valid option!");
        Sleep(1000);
        system("cls");
        report_model_building_model_sale();
    }
    }
}
void report_model_building_model_rent()
{
    int option;
    printf("1. Residential buildings\n");
    printf("2. Commercia\nl");
    printf("3. Normal filed\n");
    printf("4. back\n");
    printf("Please chose an option: ");
    scanf("%d" , &option);
    getchar();
    switch(option){
    case 1:{
        report_rent_residential();
        break;
    }
    case 2:{
        report_rent_commercial();
        break;
    }
    case 3:{
        report_rent_filed();
        break;
    }
    case 4:{
        report_model_main();
        break;
    }
    default:{
        printf("Please enter a valid option!");
        Sleep(1000);
        system("cls");
        report_model_building_model_rent();
    }
    }
}
void report_rent_residential(){
        system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
        make_null_list_building_rent();

    if(flag == 0){
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_rent();
    }
    while(1){
    printf("Please enter B for getting back to report menu: ");
    if(getchar() == 'b' || getchar() == 'B'){
        break;
        report_model_building_model_rent();
    }
    else{
        printf("Please enter a valid character!");
    }
    }
}
void report_rent_commercial(){
        system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
            make_null_list_building_rent();
    if(flag == 0){
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_rent();
    }
    while(1){
    printf("Please enter B for getting back to report menu: ");
    if(getchar() == 'b' || getchar() == 'B'){
        break;
        report_model_building_model_rent();
    }
    else{
        printf("Please enter a valid character!");
    }
    }
}
void report_rent_filed(){
    system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s" , temp->rent_per_month);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
        make_null_list_building_rent();

    if(flag == 0){
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_rent();
    }
    while(1){
    printf("Please enter B for getting back to report menu: ");
    if(getchar() == 'b' || getchar() == 'B'){
        break;
        report_model_building_model_rent();
    }
    else{
        printf("Please enter a valid character!");
    }
    }
}
void report_sale_residential(){
    system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    if(flag == 0){
        printf("There is no item to show!");

        Sleep(2500);
        report_model_building_model_sale();
    }
    while(1){
    printf("Please enter B for getting back to report menu: ");
    if(getchar() == 'b' || getchar() == 'B'){
        break;
        report_model_building_model_sale();
    }
    else{
        printf("Please enter a valid character!");
    }
    }
}
void report_sale_commercial(){
    system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    if(flag == 0){
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_sale();
    }
     while(1){
    printf("Please enter B for getting back to report menu: ");
    if(getchar() == 'b' || getchar() == 'B'){
        break;
        report_model_building_model_sale();
    }
    else{
        printf("Please enter a valid character!");
    }
    }
}
void report_sale_filed(){
    system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale_filed(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Price: %s", temp->price);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    if(flag == 0){
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_sale();
    }
     while(1){
    printf("Please enter B for getting back to report menu: ");
    if(getchar() == 'b' || getchar() == 'B'){
        break;
        report_model_building_model_sale();
    }
    else{
        printf("Please enter a valid character!");
    }
    }
}
void page_report_rent( /* BUILDING_RENT */)
{
    if(start_building_rent == NULL)
    {
        printf("There is no building to delete!");

    }
    printf("ID: %s\n");
    printf("Municipality's area: \n");
    printf("Address of building: \n");
    printf("Model of building: \n");
    printf("Age of building: \n");
    printf("The size of the infrastructure: \n");
    printf("Amount of floors: \n");
    printf("The size of the main land: \n");
    printf("Phone number of owner: \n");
    printf("Amount of rooms: \n");
    printf("prepayment Price: \n");
    printf("Rent Price: \n");
    printf("Press B for getting back to the report page.");
}
void page_reports_normal()
{
    printf("1. Specific model of buildings\n");
    printf("2. Buildings with Specific area\n");
    printf("3. Buildings with Specific age\n");
    printf("4. Buildings with Specific infrastructure size\n");
    printf("5. Buildings with Specific prices\n");
    printf("6. Buildings with Specific Room's amount\n");
    printf("7. Total price of building\n");
    printf("8. Buildings with Specific rent and mortgage price\n");
    printf("9. Date of registered buildings\n");
    printf("10. Buildings with Specific floors\n");
    printf("11. Back");
    printf("Please choice your report: ");
}
void report_All(/*struc Building*/)
{
    printf("ID: \n");
    printf("for rent or for sale: \n");
    printf("Model: \n");
    printf("Municipality's area: \n");
    printf("Address of building: \n");
    printf("Model of building: \n");
    printf("Age of building: \n");
    printf("The size of the infrastructure: \n");
    printf("Amount of floors: \n");
    printf("The size of the main land: \n");
    printf("Phone number of owner: \n");
    printf("Amount of rooms: \n");
    printf("Price: \n");
    printf("Press B for getting back to the report page.");
}
void report_time(/*struc Building*/)
{
    printf("for rent or for sale: \n");
    printf("Model: \n");
    printf("Municipality's area: \n");
    printf("Address of building: \n");
    printf("Model of building: \n");
    printf("Age of building: \n");
    printf("The size of the infrastructure: \n");
    printf("Amount of floors: \n");
    printf("The size of the main land: \n");
    printf("Phone number of owner: \n");
    printf("Amount of rooms: \n");
    printf("Price: \n");
    printf("Press B for getting back to the report page.");
}
void report_total_price()
{
    printf("The total price of buildings in application is: ");
    printf("Press B for getting back to the report page.");
}
void report_user_financial(/*struc User*/)
{
    printf("User name: \n");
}
void report_date_main()
{
    printf("1. past week");
    printf("2. past month");
    printf("3. past 3 month");
    printf("4. back");
}
void report_user_activity(/*struc User*/)
{
    printf("User name: \n");
    printf("Last login: \n");
    printf("Last logout: \n");
}
void menu_delete_building()
{
    int checker = 0;
    system("cls");
    printf("1. For sale buildings\n");
    printf("2. For rent buildings\n");
    printf("3. back\n");
    printf("Please choice your option: ");
    scanf("%d", &checker);
    getchar();
    switch(checker)
    {
    case 1 :
    {
        delete_menu_sale_buildings();
        break;
    }
    case 2 :
    {
        delete_menu_rent_buildings();
        break;
    }
    case 3 :
    {
        main_page();
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option");
        Sleep(1000);
        menu_delete_building();
    }
    }
}
void delete_menu_sale_buildings()
{
    system("cls");
    int checker = 0;
    printf("1. Residential buildings\n");
    printf("2. Commercial\n");
    printf("3. Normal filed\n");
    printf("4. back\n");
    printf("Please choice your option: ");
    scanf("%d", &checker);
    getchar();
    switch(checker)
    {
    case 1 :
    {
        delete_sale_buildings_Residential();
        break;
    }
    case 2 :
    {
        delete_sale_buildings_commercial();
        break;
    }
    case 3 :
    {
        delete_sale_buildings_filed();
        break;
    }
    case 4:
    {
        menu_delete_building();
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option");
        Sleep(1000);
        delete_menu_sale_buildings();
    }
    }
}
void delete_sale_buildings_Residential()
{
    system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    if(flag != 0)
    {
        flag = 0;
        printf("For deleting the building please enter its id:");
        gets(id);
        strcat(id, "\n");
        temp = start_building_sale;
        while(temp != NULL)
        {
            if(strcmp(id, temp->id) == 0)
            {
                flag++;
                strcpy(temp->isactive, "0\n");
            }
            temp = temp->link;
        }
        if(flag != 0){
            fclose(fp);
        fp = fopen("Files\\building\\for_sale\\Residential.txt", "w+");
        temp = start_building_sale;
        while(temp != NULL)
        {
            if((strcmp(temp->isactive, "1\n") == 0) || (strcmp(temp->isactive, "0\n") == 0))
            {
                fputs(temp->municipalitys_area, fp);
                fputs(temp->address_of_building, fp);
                fputs(temp->model, fp);
                fputs(temp->age_of_building, fp);
                fputs(temp->size_of_the_infrastructure, fp);
                fputs(temp->amount_of_floors, fp);
                fputs(temp->size_of_the_main_land, fp);
                fputs(temp->phone_number_of_owner, fp);
                fputs(temp->amount_of_rooms, fp);
                fputs(temp->price, fp);
                fputs(temp->user, fp);
                itoa(temp->time, TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
                fputs(temp->isactive, fp);
                fputs(temp->id, fp);
                itoa(time(NULL), TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
            }
            temp = temp->link;
        }
        fclose(fp);
        make_null_list_building_sale();
        printf("The building has deleted successfully");
        Sleep(3000);
        delete_menu_sale_buildings();
        }
        else{
          fclose(fp);
        make_null_list_building_sale();
        printf("Please enter a valid ID");
        Sleep(3000);
        delete_sale_buildings_Residential();
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_sale();
        system("cls");
        printf("There is no building to delete!");
        Sleep(2000);
        delete_menu_sale_buildings();
    }
}
void delete_sale_buildings_commercial()
{
    system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Price: %s", temp->price);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    if(flag != 0)
    {
        flag = 0;
        printf("For deleting the building please enter its id:");
        gets(id);
        strcat(id, "\n");
        temp = start_building_sale;
        while(temp != NULL)
        {
            if(strcmp(id, temp->id) == 0)
            {
                flag++;
                strcpy(temp->isactive, "0\n");
            }
            temp = temp->link;
        }
        if(flag != 0){
            fclose(fp);
        fp = fopen("Files\\building\\for_sale\\Commercial.txt", "w+");
        temp = start_building_sale;
        while(temp != NULL)
        {
            if((strcmp(temp->isactive, "1\n") == 0) || (strcmp(temp->isactive, "0\n") == 0))
            {
                fputs(temp->municipalitys_area, fp);
                fputs(temp->address_of_building, fp);
                fputs(temp->model, fp);
                fputs(temp->age_of_building, fp);
                fputs(temp->size_of_the_infrastructure, fp);
                fputs(temp->amount_of_floors, fp);
                fputs(temp->size_of_the_main_land, fp);
                fputs(temp->phone_number_of_owner, fp);
                fputs(temp->amount_of_rooms, fp);
                fputs(temp->price, fp);
                fputs(temp->user, fp);
                itoa(temp->time, TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
                fputs(temp->isactive, fp);
                fputs(temp->id, fp);
                itoa(time(NULL), TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
            }
            temp = temp->link;
        }
        fclose(fp);
        make_null_list_building_sale();
        printf("The building has deleted successfully");
        Sleep(3000);
        delete_menu_sale_buildings();
        }
        else{
          fclose(fp);
        make_null_list_building_sale();
        printf("Please enter a valid ID");
        Sleep(3000);
        delete_sale_buildings_commercial();
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_sale();
        system("cls");
        printf("There is no building to delete!");
        Sleep(2000);
        delete_menu_sale_buildings();
    }
}
void delete_sale_buildings_filed()
{
    system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Price: %s", temp->price);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    if(flag != 0)
    {
        flag = 0;
        printf("For deleting the building please enter its id:");
        gets(id);
        strcat(id, "\n");
        temp = start_building_sale;
        while(temp != NULL)
        {
            if(strcmp(id, temp->id) == 0)
            {
                flag++;
                strcpy(temp->isactive, "0\n");
            }
            temp = temp->link;
        }
        if(flag != 0){
            fclose(fp);
        fp = fopen("Files\\building\\for_sale\\Filed.txt", "w+");
        temp = start_building_sale;
        while(temp != NULL)
        {
            if((strcmp(temp->isactive, "1\n") == 0) || (strcmp(temp->isactive, "0\n") == 0))
            {
                fputs(temp->municipalitys_area, fp);
                fputs(temp->address_of_building, fp);
                fputs(temp->model, fp);
                fputs(temp->size_of_the_infrastructure, fp);
                fputs(temp->phone_number_of_owner, fp);
                fputs(temp->amount_of_rooms, fp);
                fputs(temp->price, fp);
                fputs(temp->user, fp);
                itoa(temp->time, TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
                fputs(temp->isactive, fp);
                fputs(temp->id, fp);
                itoa(time(NULL), TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
            }
            temp = temp->link;
        }
        fclose(fp);
        make_null_list_building_sale();
        printf("The building has deleted successfully");
        Sleep(3000);
        delete_menu_sale_buildings();
        }
        else{
          fclose(fp);
        make_null_list_building_sale();
        printf("Please enter a valid ID");
        Sleep(3000);
        delete_sale_buildings_filed();
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_sale();
        system("cls");
        printf("There is no building to delete!");
        Sleep(2000);
        delete_menu_sale_buildings();
    }
}
void delete_menu_rent_buildings()
{
    system("cls");
    int checker = 0;
    printf("1. Residential buildings\n");
    printf("2. Commercial\n");
    printf("3. Normal filed\n");
    printf("4. back\n");
    printf("Please choice your option: ");
    scanf("%d", &checker);
    getchar();
    switch(checker)
    {
    case 1 :
    {
        delete_rent_buildings_Residential();
        break;
    }
    case 2 :
    {
        delete_rent_buildings_commercial();
        break;
    }
    case 3 :
    {
         delete_rent_buildings_filed();
        break;
    }
    case 4:
    {
        menu_delete_building();
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option");
        Sleep(1000);
        delete_menu_rent_buildings();
    }
    }
}
void delete_rent_buildings_Residential(){
    system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent_per_month: %s", temp->rent_per_month);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    if(flag != 0)
    {
        flag = 0;
        printf("For deleting the building please enter its id:");
        gets(id);
        strcat(id, "\n");
        temp = start_building_rent;
        while(temp != NULL)
        {
            if(strcmp(id, temp->id) == 0)
            {
                flag++;
                strcpy(temp->isactive, "0\n");
            }
            temp = temp->link;
        }
        if(flag != 0){
        fclose(fp);
        fp = fopen("Files\\building\\for_rent\\Residential.txt", "w+");
        temp = start_building_rent;
        while(temp != NULL)
        {
            if((strcmp(temp->isactive, "1\n") == 0) || (strcmp(temp->isactive, "0\n") == 0))
            {
                fputs(temp->municipalitys_area, fp);
                fputs(temp->address_of_building, fp);
                fputs(temp->model, fp);
                fputs(temp->age_of_building, fp);
                fputs(temp->size_of_the_infrastructure, fp);
                fputs(temp->amount_of_floors, fp);
                fputs(temp->size_of_the_main_land, fp);
                fputs(temp->phone_number_of_owner, fp);
                fputs(temp->amount_of_rooms, fp);
                fputs(temp->prepayment, fp);
                fputs(temp->rent_per_month , fp);
                fputs(temp->user, fp);
                itoa(temp->time, TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
                fputs(temp->isactive, fp);
                fputs(temp->id, fp);
                itoa(time(NULL), TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
            }
            temp = temp->link;
        }
        fclose(fp);
        make_null_list_building_rent();
        printf("The building has deleted successfully");
        Sleep(3000);
        delete_menu_rent_buildings();
        }
        else{
          fclose(fp);
        make_null_list_building_rent();
        printf("Please enter a valid ID");
        Sleep(3000);
        delete_rent_buildings_Residential();
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_rent();
        system("cls");
        printf("There is no building to delete!");
        Sleep(2000);
        delete_menu_rent_buildings();
    }
}
void delete_rent_buildings_commercial(){
    system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("Age of building: %s", temp->age_of_building);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Amount of floors: %s", temp->amount_of_floors);
            printf("The size of the main land: %s", temp->size_of_the_main_land);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Amount of rooms: %s", temp->amount_of_floors);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent_per_month: %s", temp->rent_per_month);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    if(flag != 0)
    {
        flag = 0;
        printf("For deleting the building please enter its id:");
        gets(id);
        strcat(id, "\n");
        temp = start_building_rent;
        while(temp != NULL)
        {
            if(strcmp(id, temp->id) == 0)
            {
                flag++;
                strcpy(temp->isactive, "0\n");
            }
            temp = temp->link;
        }
        if(flag != 0){
            fclose(fp);
        fp = fopen("Files\\building\\for_rent\\Commercial.txt", "w+");
        temp = start_building_rent;
        while(temp != NULL)
        {
            if((strcmp(temp->isactive, "1\n") == 0) || (strcmp(temp->isactive, "0\n") == 0))
            {
                fputs(temp->municipalitys_area, fp);
                fputs(temp->address_of_building, fp);
                fputs(temp->model, fp);
                fputs(temp->age_of_building, fp);
                fputs(temp->size_of_the_infrastructure, fp);
                fputs(temp->amount_of_floors, fp);
                fputs(temp->size_of_the_main_land, fp);
                fputs(temp->phone_number_of_owner, fp);
                fputs(temp->amount_of_rooms, fp);
                fputs(temp->prepayment, fp);
                fputs(temp->rent_per_month , fp);
                fputs(temp->user, fp);
                itoa(temp->time, TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
                fputs(temp->isactive, fp);
                fputs(temp->id, fp);
                itoa(time(NULL), TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
            }
            temp = temp->link;
        }
        fclose(fp);
        make_null_list_building_rent();
        printf("The building has deleted successfully");
        Sleep(3000);
        delete_menu_rent_buildings();
        }
        else{
          fclose(fp);
        make_null_list_building_rent();
        printf("Please enter a valid ID");
        Sleep(3000);
        delete_rent_buildings_Residential();
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_rent();
        system("cls");
        printf("There is no building to delete!");
        Sleep(2000);
        delete_menu_rent_buildings();
    }
}
void delete_rent_buildings_filed(){
        system("cls");
    char id[7], TEMP[21];
    int flag = 0;
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent_per_month: %s", temp->rent_per_month);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    if(flag != 0)
    {
        flag = 0;
        printf("For deleting the building please enter its id:");
        gets(id);
        strcat(id, "\n");
        temp = start_building_rent;
        while(temp != NULL)
        {
            if(strcmp(id, temp->id) == 0)
            {
                flag++;
                strcpy(temp->isactive, "0\n");
            }
            temp = temp->link;
        }
        if(flag != 0){
            fclose(fp);
        fp = fopen("Files\\building\\for_rent\\Filed.txt", "w+");
        temp = start_building_rent;
        while(temp != NULL)
        {
            if((strcmp(temp->isactive, "1\n") == 0) || (strcmp(temp->isactive, "0\n") == 0))
            {
                fputs(temp->municipalitys_area, fp);
                fputs(temp->address_of_building, fp);
                fputs(temp->model, fp);
                fputs(temp->size_of_the_infrastructure, fp);
                fputs(temp->phone_number_of_owner, fp);
                fputs(temp->prepayment, fp);
                fputs(temp->rent_per_month , fp);
                fputs(temp->user, fp);
                itoa(temp->time, TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
                fputs(temp->isactive, fp);
                fputs(temp->id, fp);
                itoa(time(NULL), TEMP, 10);
                fputs(TEMP, fp);
                fputs("\n", fp);
            }
            temp = temp->link;
        }
        fclose(fp);
        make_null_list_building_rent();
        printf("The building has deleted successfully");
        Sleep(3000);
        delete_menu_rent_buildings();
        }
        else{
          fclose(fp);
        make_null_list_building_rent();
        printf("Please enter a valid ID");
        Sleep(3000);
        delete_rent_buildings_Residential();
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_rent();
        system("cls");
        printf("There is no building to delete!");
        Sleep(2000);
        delete_menu_rent_buildings();
    }
}
void user_edit()
{
    printf("Please enter your new name(if don't want to change leave it alone):");
    printf("Please enter delete_rent_buildings_commercialyour new last name(if don't want to change leave it alone):");
    printf("Please enter your new ID(if don't want to change leave it alone:");
    printf("Please enter your new Phone(if don't want to change leave it alone:");
    printf("Please enter your new Email(if don't want to change leave it alone:");
    printf("Please enter your new password(if don't want to change leave it alone):");
    printf("Please enter your new password again: ");
}
void make_list_user(FILE *user_fp)
{
    char temp_time[31];
    USER *temp;
    while(1)
    {
        if(feof(user_fp))
        {
            break;
        }
        temp = malloc(sizeof(USER));
        fgets(temp->user_name, 30, user_fp);
        fgets(temp->password, 20, user_fp);
        fgets(temp->name, 25, user_fp);
        fgets(temp->last_name, 45, user_fp);
        fgets(temp->phone, 12, user_fp);
        fgets(temp->email, 35, user_fp);
        fgets(temp_time , 31 , user_fp);
        temp->time_login = atol(temp_time);
        fgets(temp_time , 31 , user_fp);
        temp->time_logout = atol(temp_time);
        if(start_user == NULL)
        {
            start_user = temp;
            start_user->link = NULL;
            last_user = start_user;
        }
        else
        {
            last_user->link = temp;
            last_user = temp;
            last_user->link = NULL;
        }
    }
}
int search_username_list_user(char user_name[30])
{
    USER *temp;
    temp = start_user;
    while(temp != NULL)
    {
        if(strcmp(temp->user_name, user_name) == 0)
        {
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}
int search_password_list_user(char user_name[30], char password[20])
{
    USER *temp;
    temp = start_user;
    current_user = malloc(sizeof(USER));
    while(temp != NULL)
    {
        if(strcmp(temp->user_name, user_name) == 0 && strcmp(temp->password, password) == 0)
        {
            current_user = temp;
            temp->time_login = time(NULL);
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}
void make_null_list_user()
{
    struct user *temp;
    do
    {
        temp = malloc(sizeof(USER));
        temp = start_user;
        if(strcmp(temp->user_name, current_user->user_name)==0)
        {
            start_user = start_user->link;
            continue;
        }
        start_user = start_user->link;
        free(temp);
    }
    while(start_user != NULL);
}
void make_list_building_sale(FILE *building_sale_fp)
{
    BUILDING_SALE *temp;
    char TEMP[21];
    while(1)
    {
        if(feof(building_sale_fp))
        {
            break;
        }
        temp = malloc(sizeof(BUILDING_SALE));
        fgets(temp->municipalitys_area, 6, building_sale_fp);
        fgets(temp->address_of_building, 100, building_sale_fp);
        fgets(temp->model, 20, building_sale_fp);
        fgets(temp->age_of_building, 5, building_sale_fp);
        fgets(temp->size_of_the_infrastructure, 10, building_sale_fp);
        fgets(temp->amount_of_floors, 4, building_sale_fp);
        fgets(temp->size_of_the_main_land, 10, building_sale_fp);
        fgets(temp->phone_number_of_owner, 15, building_sale_fp);
        fgets(temp->amount_of_rooms, 13, building_sale_fp);
        fgets(temp->price, 15, building_sale_fp);
        fgets(temp->user, 30, building_sale_fp);
        fgets(TEMP, 20, building_sale_fp);
        temp->time = atoi(TEMP);
        fgets(temp->isactive, 3, building_sale_fp);
        fgets(temp->id, 7, building_sale_fp);
        fgets(TEMP, 20, building_sale_fp);
        temp->time_delete = atoi(TEMP);
        if(start_building_sale == NULL)
        {
            start_building_sale = temp;
            start_building_sale->link = NULL;
            last_building_sale = start_building_sale;
        }
        else
        {
            last_building_sale->link = temp;
            last_building_sale = temp;
            last_building_sale->link = NULL;
        }
    }
}
void make_list_building_sale_filed(FILE *building_sale_fp)
{
    BUILDING_SALE *temp;
    char TEMP[21];
    while(1)
    {
        if(feof(building_sale_fp))
        {
            break;
        }
        temp = malloc(sizeof(BUILDING_SALE));
        fgets(temp->municipalitys_area, 6, building_sale_fp);
        fgets(temp->address_of_building, 100, building_sale_fp);
        fgets(temp->model, 20, building_sale_fp);
        fgets(temp->size_of_the_infrastructure, 10, building_sale_fp);
        fgets(temp->phone_number_of_owner, 15, building_sale_fp);
        fgets(temp->price, 15, building_sale_fp);
        fgets(temp->user, 30, building_sale_fp);
        fgets(TEMP, 20, building_sale_fp);
        temp->time = atoi(TEMP);
        fgets(temp->isactive, 3, building_sale_fp);
        fgets(temp->id, 7, building_sale_fp);
        fgets(TEMP, 20, building_sale_fp);
        temp->time_delete = atoi(TEMP);
        if(start_building_sale == NULL)
        {
            start_building_sale = temp;
            start_building_sale->link = NULL;
            last_building_sale = start_building_sale;
        }
        else
        {
            last_building_sale->link = temp;
            last_building_sale = temp;
            last_building_sale->link = NULL;
        }
    }
}
void make_null_list_building_sale()
{
    struct BUILDING_SALE *temp;
    do
    {
        temp = malloc(sizeof(BUILDING_SALE));
        temp = start_building_sale;
        start_building_sale = start_building_sale->link;
        free(temp);
    }
    while(start_building_sale != NULL);
}
void make_list_building_rent(FILE *building_rent_fp)
{
    BUILDING_RENT *temp;
    char TEMP[21];
    while(1)
    {
        if(feof(building_rent_fp))
        {
            break;
        }
        temp = malloc(sizeof(BUILDING_RENT));
        fgets(temp->municipalitys_area, 6, building_rent_fp);
        fgets(temp->address_of_building, 100, building_rent_fp);
        fgets(temp->model, 20, building_rent_fp);
        fgets(temp->age_of_building, 6 , building_rent_fp);
        fgets(temp->size_of_the_infrastructure, 10, building_rent_fp);
        fgets(temp->amount_of_floors, 6, building_rent_fp);
        fgets(temp->size_of_the_main_land, 10, building_rent_fp);
        fgets(temp->phone_number_of_owner, 15, building_rent_fp);
        fgets(temp->amount_of_rooms, 6, building_rent_fp);
        fgets(temp->prepayment, 15, building_rent_fp);
        fgets(temp->rent_per_month, 15, building_rent_fp);
        fgets(temp->user, 30, building_rent_fp);
        fgets(TEMP, 25, building_rent_fp);
        temp->time = atoi(TEMP);
        fgets(temp->isactive, 3, building_rent_fp);
        fgets(temp->id, 7, building_rent_fp);
        fgets(TEMP, 20, building_rent_fp);
        temp->time_delete = atoi(TEMP);
        if(start_building_rent == NULL)
        {
            start_building_rent = temp;
            start_building_rent->link = NULL;
            last_building_rent = start_building_rent;
        }
        else
        {
            last_building_rent->link = temp;
            last_building_rent = temp;
            last_building_rent->link = NULL;
        }
    }
}
void make_list_building_rent_filed(FILE *building_rent_fp)
{
    BUILDING_RENT *temp;
    char TEMP[21];
    while(1)
    {
        if(feof(building_rent_fp))
        {
            break;
        }
        temp = malloc(sizeof(BUILDING_RENT));
        fgets(temp->municipalitys_area, 6, building_rent_fp);
        fgets(temp->address_of_building, 100, building_rent_fp);
        fgets(temp->model, 20, building_rent_fp);
        fgets(temp->size_of_the_infrastructure, 10, building_rent_fp);
        fgets(temp->phone_number_of_owner, 15, building_rent_fp);
        fgets(temp->prepayment, 15, building_rent_fp);
        fgets(temp->rent_per_month, 15, building_rent_fp);
        fgets(temp->user, 30, building_rent_fp);
        fgets(TEMP, 25, building_rent_fp);
        temp->time = atoi(TEMP);
        fgets(temp->isactive, 3, building_rent_fp);
        fgets(temp->id, 7, building_rent_fp);
        fgets(TEMP, 20, building_rent_fp);
        temp->time_delete = atoi(TEMP);
        if(start_building_rent == NULL)
        {
            start_building_rent = temp;
            start_building_rent->link = NULL;
            last_building_rent = start_building_rent;
        }
        else
        {
            last_building_rent->link = temp;
            last_building_rent = temp;
            last_building_rent->link = NULL;
        }
    }
}
void make_null_list_building_rent()
{
    BUILDING_RENT *temp;
    do
    {
        temp = malloc(sizeof(BUILDING_RENT));
        temp = start_building_rent;
        start_building_rent = start_building_rent->link;
        free(temp);
    }
    while(start_building_rent != NULL);
}
void main()
{
    delete_rent_buildings_filed();
    atexit(logout_time);
}
/*
            strcpy(temp->municipalitys_area);
            strcpy(temp->address_of_building);
            strcpy(temp->model);
            strcpy(temp->age_of_building);
            strcpy(temp->size_of_the_infrastructure);
            strcpy(temp->amount_of_floors);
            strcpy(temp->size_of_the_main_land);
            strcpy(temp->phone_number_of_owner);
            strcpy(temp->temp->amount_of_floors);
            strcpy(temp->price)
*/
