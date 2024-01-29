#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void Start_Page();
void make_list_user(FILE *user_fp);
long long unsigned report_price_total();
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
    char ID[20];

    struct user *link;
}*start_user = NULL, *last_user = NULL;

typedef struct building_sale BUILDING_SALE;
typedef struct user USER;
typedef struct building_rent BUILDING_RENT;

USER *current_user;
int inner_flag = 0;
void sign_up()
{
    int index = 0, stars = 0;
    char temp_time[31], option, character, password[30];
    system("cls");
    printf("For getting back press b: ");
    if(tolower(getche()) == 'b'){
        Start_Page();
    }
    printf("\33[2K\r");
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
    make_list_user(user_fp);
    while(1){
        while(1){
                printf("\nPlease enter a user name: ");
        gets(user->user_name);
        if(strlen(user->user_name) <= 28){
            break;
        }
        else{
            printf("User name can not be more than 28 characters!\n");
        }
        }

        strcat(user->user_name, "\n");
        if(search_username_list_user(user->user_name)== 1)
        {
            printf("This user name has already taken.");
        }
        else
        {
            user->user_name[strlen(user->user_name) - 1] = '\0';
            break;
        }
    }
    make_null_list_user();

    while(1){
     printf("Please enter your password: ");
    index = 0;
    stars = 0;
    while(1)
    {
        character = getch();
        if(character == 13)
        {
            break;
        }
        if(character == 8)
        {

            printf("\33[2K\r");
            printf("Please enter your password: ");
            for(int i = 0 ; i < stars - 1 ; i++)
            {
                printf("%c", '*');
            }
            stars--;
            user->password[index - 1] = '\0';
            index--;
        }
        else
        {

            printf("%c", '*');
            user->password[index] = character;
            user->password[index + 1] = '\0';
            index++;
            stars++;
        }
    }
    if(isp)
    }
    printf("\n");
    printf("\n            personal information\n");
    printf("\nPlease enter your name: ");
    gets(user->name);
    printf("\nPlease enter your last name: ");
    gets(user->last_name);
    printf("\nPlease enter Your phone number: ");
    gets(user->phone);
    printf("\nPlease enter Your email:  ");
    gets(user->email);
    printf("\nPlease enter Your ID:  ");
    gets(user->ID);
    printf("Are you sure you want to add this user to the application?(Y/N)");
    while(1)
    {
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
            itoa(0, temp_time, 10);
            fputs(temp_time, user_fp);
            fputs("\n", user_fp);
            fputs("0", user_fp);
            fputs("\n", user_fp);
            fputs(user->ID, user_fp);
            fputs("\n", user_fp);
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
            fclose(user_fp);
            system("cls");
            Start_Page();
        }
        else
        {
            printf("Please enter a valid character");
        }
    }

}
void sign_in()
{
    system("cls");
    printf("For getting back press b: ");
    if(tolower(getche()) == 'b'){
        Start_Page();
    }
    printf("\33[2K\r");
    int index = 0, stars = 0;
    char character;
    char time_tmep[30];
    FILE *user_fp;
    USER *temp;
    user_fp = fopen("Files\\users\\user.txt", "r+");
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
            index = 0;
            stars = 0;
            while(1)
            {
                character = getch();
                if(character == 13)
                {
                    break;
                }
                if(character == 8)
                {

                    printf("\33[2K\r");
                    printf("Please enter your password: ");
                    for(int i = 0 ; i < stars - 1 ; i++)
                    {
                        printf("%c", '*');
                    }
                    stars--;
                    password[index - 1] = '\0';
                    index--;
                }
                else
                {

                    printf("%c", '*');
                    password[index] = character;
                    password[index + 1] = '\0';
                    index++;
                    stars++;
                }
            }
            printf("\n");
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
        user_fp = fopen("Files\\users\\user.txt", "w+");
        temp = start_user;
        while(temp != last_user)
        {
            fputs(temp->user_name, user_fp);
            fputs(temp->password, user_fp);
            fputs(temp->name, user_fp);
            fputs(temp->last_name, user_fp);
            fputs(temp->phone, user_fp);
            fputs(temp->email, user_fp);
            itoa(temp->time_login, time_tmep, 10);
            fputs(time_tmep, user_fp);
            fputs("\n", user_fp);
            itoa(temp->time_logout, time_tmep, 10);
            fputs(time_tmep, user_fp);
            fputs("\n", user_fp);
            fputs(temp->ID, user_fp);
            temp = temp->link;
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
        make_null_list_user();
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
        if(strcmp(current_user->user_name, "admin\n") == 0)
        {
            page_admin_report();
        }
        else
        {
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
void user_edit()
{
    int index = 0, stars = 0;
    system("cls");
    char tempstr[34], temp_pass_valid[25], temp_user[25], temp_time[15], checker , character;
    FILE *user_fp;
    user_fp = fopen("Files\\users\\user.txt", "r");
    make_list_user(user_fp);
    USER *temp, *temp_current = NULL;
    if(temp_current == NULL){
    temp_current = malloc(sizeof(USER));
    }
    printf("User settings\n");
    printf("        if you don't want to change a filed , leave it blank\n\n");
    printf("For getting back, press b: ");
    if(tolower(getche()) == 'b')
    {
        main_page();
    }
    printf("\33[2K\r");
    strcpy(temp_user, current_user->user_name);
    printf("Please enter your new name: ");
    gets(tempstr);
    if(strcmp(tempstr, "") != 0)
    {
        strcat(tempstr, "\n");
        strcpy(temp_current->name,  tempstr);
    }
    else
    {
        strcpy(temp_current->name, current_user->name);
    }
    printf("Please enter your new last name: ");
    gets(tempstr);
    if(strcmp(tempstr, "") != 0)
    {
        strcat(tempstr, "\n");
        strcpy(temp_current->last_name, tempstr);
    }
    else
    {
        strcpy(temp_current->last_name, current_user->last_name);
    }
    printf("Please enter your new ID: ");
    gets(tempstr);
    if(strcmp(tempstr, "") != 0)
    {
        strcat(tempstr, "\n");
        strcpy(temp_current->ID, tempstr);
    }
    else
    {
        strcpy(temp_current->ID, current_user->ID);
    }
    printf("Please enter your new Phone: ");
    gets(tempstr);
    if(strcmp(tempstr, "") != 0)
    {
        strcat(tempstr, "\n");
        strcpy(temp_current->phone, tempstr);
    }
    else
    {
        strcpy(temp_current->phone, current_user->phone);
    }
    printf("Please enter your new Email:");
    gets(tempstr);
    if(strcmp(tempstr, "") != 0)
    {
        strcat(tempstr, "\n");
        strcpy(temp_current->email, tempstr);
    }
    else
    {
        strcpy(temp_current->email, current_user->email);
    }
    make_str_null(tempstr);
    printf("Please enter your password: ");
    while(1)
    {
        character = getch();
        if(character == 13)
        {
            break;
        }
        if(character == 8)
        {

            printf("\33[2K\r");
            printf("Please enter your password: ");
            for(int i = 0 ; i < stars - 1 ; i++)
            {
                printf("%c", '*');
            }
            stars--;
            tempstr[index - 1] = '\0';
            index--;
        }
        else
        {

            printf("%c", '*');
            tempstr[index] = character;
            tempstr[index + 1] = '\0';
            index++;
            stars++;
        }
    }
    printf("\n");
    printf("Please enter your new password again: ");
    make_str_null(temp_pass_valid);
    index = 0;
    stars = 0;
    while(1)
    {
        character = getch();
        if(character == 13)
        {
            break;
        }
        if(character == 8)
        {

            printf("\33[2K\r");
            printf("Please enter your password again: ");
            for(int i = 0 ; i < stars - 1 ; i++)
            {
                printf("%c", '*');
            }
            stars--;
            temp_pass_valid[index - 1] = '\0';
            index--;
        }
        else
        {

            printf("%c", '*');
            temp_pass_valid[index] = character;
            temp_pass_valid[index + 1] = '\0';
            index++;
            stars++;
        }
    }
    printf("\n");
    if(strcmp(tempstr, "") != 0)
    {
        while(1)
        {
            if(strcmp(tempstr, temp_pass_valid) == 0)
            {
                strcat(tempstr, "\n");
                strcpy(temp_current->password, tempstr);
                break;
            }
            else
            {
                index = 0;
                stars = 0;
                printf("your password isn't matched!\n");
                make_str_null(tempstr);
                printf("Please enter your new password: ");
                while(1)
                {
                    character = getch();
                    if(character == 13)
                    {
                        break;
                    }
                    if(character == 8)
                    {

                        printf("\33[2K\r");
                        printf("Please enter your password: ");
                        for(int i = 0 ; i < stars - 1 ; i++)
                        {
                            printf("%c", '*');
                        }
                        stars--;
                        tempstr[index - 1] = '\0';
                        index--;
                    }
                    else
                    {

                        printf("%c", '*');
                        tempstr[index] = character;
                        tempstr[index + 1] = '\0';
                        index++;
                        stars++;
                    }
                }
                printf("\n");
                printf("Please enter your new password again: ");
                make_str_null(temp_pass_valid);
                index = 0;
                stars = 0;
                while(1)
                {
                    character = getch();
                    if(character == 13)
                    {
                        break;
                    }
                    if(character == 8)
                    {

                        printf("\33[2K\r");
                        printf("Please enter your password again: ");
                        for(int i = 0 ; i < stars - 1 ; i++)
                        {
                            printf("%c", '*');
                        }
                        stars--;
                        temp_pass_valid[index - 1] = '\0';
                        index--;
                    }
                    else
                    {

                        printf("%c", '*');
                        temp_pass_valid[index] = character;
                        temp_pass_valid[index + 1] = '\0';
                        index++;
                        stars++;
                    }
                }
            }
        }
    }
    else
    {
        strcpy(temp_current->password, current_user->password);
    }
    fclose(user_fp);

    temp = start_user;
    while(1)
    {
        char checker;
        printf("\nFor Saving Please press Y. for canceling please press N.....");
        checker = getche();
        if(checker == 'Y' || checker == 'y')
        {
            user_fp = fopen("Files\\users\\user.txt", "w+");
            while(temp != last_user)
            {
                if(strcmp(temp->user_name, temp_user) != 0 )
                {
                    fputs(temp->user_name, user_fp);
                    fputs(temp->password, user_fp);
                    fputs(temp->name, user_fp);
                    fputs(temp->last_name, user_fp);
                    fputs(temp->phone, user_fp);
                    fputs(temp->email, user_fp);
                    itoa(temp->time_login, temp_time, 10);
                    fputs(temp_time, user_fp);
                    fputs("\n", user_fp);
                    itoa(temp->time_logout, temp_time, 10);
                    fputs(temp_time, user_fp);
                    fputs("\n", user_fp);
                    fputs(temp->ID, user_fp);
                }
                else
                {
                    fputs(current_user->user_name, user_fp);
                    fputs(temp_current->password, user_fp);
                    fputs(temp_current->name, user_fp);
                    fputs(temp_current->last_name, user_fp);
                    fputs(temp_current->phone, user_fp);
                    fputs(temp_current->email, user_fp);
                    itoa(current_user->time_login, temp_time, 10);
                    fputs(temp_time, user_fp);
                    fputs("\n", user_fp);
                    itoa(current_user->time_logout, temp_time, 10);
                    fputs(temp_time, user_fp);
                    fputs("\n", user_fp);
                    fputs(temp_current->ID, user_fp);
                }
                temp = temp->link;
            }
            current_user = temp_current;
            make_null_list_user();
            fclose(user_fp);
            system("cls");
            printf("The user was edited Successfully!");
            Sleep(2000);
            main_page();
        }
        else if(checker == 'N' || checker == 'n')
        {
            make_null_list_user();
            fclose(user_fp);
            system("cls");
            free(temp_current);
            main_page();
        }
        else
        {
            printf("\nPlease enter a valid character!");
        }
    }
}
void logout_time()
{
    char time_tmep[30];
    current_user->time_logout = time(NULL);
    FILE *user_fp;
    USER *temp;
    user_fp = fopen("Files\\users\\user.txt", "r+");
    make_list_user(user_fp);
    fclose(user_fp);
    user_fp = fopen("Files\\users\\user.txt", "w+");
    temp = start_user;
    while(temp != last_user)
    {
        fputs(temp->user_name, user_fp);
        fputs(temp->password, user_fp);
        fputs(temp->name, user_fp);
        fputs(temp->last_name, user_fp);
        fputs(temp->phone, user_fp);
        fputs(temp->email, user_fp);
        itoa(temp->time_login, time_tmep, 10);
        fputs(time_tmep, user_fp);
        fputs("\n", user_fp);
        if(strcmp(temp->user_name, current_user->user_name) == 0)
        {
            itoa(time(NULL), time_tmep, 10);
            fputs(time_tmep, user_fp);
            fputs("\n", user_fp);
        }
        else
        {
            itoa(temp->time_logout, time_tmep, 10);
            fputs(time_tmep, user_fp);
            fputs("\n", user_fp);
        }
        fputs(temp->ID, user_fp);
        temp = temp->link;
    }
    fclose(user_fp);
    make_null_list_user();
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
void make_str_null(char string[])
{
    for(int index = 0; index < strlen(string) ; index++)
    {
        string[index] = '\0';
    }
}
void menu_adding_building()
{
    int checker = 0;
    system("cls");
    printf("Adding building\n");
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
    printf("Adding building\\for sale\n");
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
    printf("Adding building\\for sale\\residential\n");
    printf("For getting back, press b: ");
    if(tolower(getche()) == 'b')
    {
        menu_sale_buildings();
    }
    system("cls");
    printf("Adding building\\for sale\\residential\n");
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
    printf("Adding building\\for sale\\commercial\n");
    printf("For getting back, press b: ");
    if(tolower(getche()) == 'b')
    {
        menu_sale_buildings();
    }
    system("cls");
    printf("Adding building\\for sale\\commercial\n");
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
    printf("Adding building\\for sale\\filed\n");
    printf("For getting back, press b: ");
    if(tolower(getche()) == 'b')
    {
        menu_sale_buildings();
    }
    system("cls");
    printf("Adding building\\for sale\\filed\n");
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
    printf("Adding building\\for rent\n");
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
    printf("Adding building\\for rent\\residential\n");
    printf("For getting back, press b: ");
    if(tolower(getche()) == 'b')
    {
        menu_rent_buildings();
    }
    system("cls");
    printf("Adding building\\for rent\\residential\n");
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
    printf("Adding building\\for rent\\commercial\n");
    printf("For getting back, press b: ");
    if(tolower(getche()) == 'b')
    {
        menu_rent_buildings();
    }
    system("cls");
    printf("Adding building\\for rent\\commercial\n");
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
    printf("Adding building\\for rent\\filed\n");
    FILE *file_rent_res, *file_ID;
    printf("For getting back, press b: ");
    if(tolower(getche()) == 'b')
    {
        menu_rent_buildings();
    }
    system("cls");
    printf("Adding building\\for rent\\filed\n");
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
    system("cls");
    printf("Reports\n");
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
    printf("12. Date of deleted buildings\n");
    printf("13. Users activity\n");
    printf("14. Back\n");
    printf("Please choice your report: ");
    scanf("%d", &option);
    getchar();
    switch(option)
    {
    case 1:
    {
        system("cls");
        report_model_main();
        break;
    }
    case 2:
    {
        system("cls");
        inner_flag = 0;
        char chose[12];
        printf("Please enter a municipalitys area: ");
        gets(chose);
        strcat(chose, "\n");
        system("cls");
        report_sale_residential_area(chose);
        report_sale_commercial_area(chose);
        report_rent_residential_area(chose);
        report_rent_commercial_area(chose);
        report_rent_filed_area(chose);
        report_sale_filed_area(chose);
        break;
    }
    case 3:
    {
        system("cls");
        inner_flag = 0;
        char age_start[6], age_finish[6];
        printf("Please enter the start of age range(if you wish to only look for a specific age enter 0 for this filed): ");
        gets(age_start);
        printf("Please enter the end of age range: ");
        gets(age_finish);
        system("cls");
        report_sale_residential_age(age_start, age_finish);
        report_sale_commercial_age(age_start, age_finish);
        report_rent_residential_age(age_start, age_finish);
        report_rent_commercial_age(age_start, age_finish);
    }
    case 4:
    {
        system("cls");
        inner_flag = 0;
        char size_start[6], size_finish[6];
        printf("Please enter the start of size range(if you wish to only look for a specific age enter 0 for this filed): ");
        gets(size_start);
        printf("Please enter the end of size range: ");
        gets(size_finish);
        system("cls");
        report_sale_residential_size(size_start, size_finish);
        report_sale_commercial_size(size_start, size_finish);
        report_rent_filed_size(size_start, size_finish);
        report_rent_residential_size(size_start, size_finish);
        report_rent_commercial_size(size_start, size_finish);
        report_sale_filed_size(size_start, size_finish);
    }
    case 5:
    {
        system("cls");
        inner_flag = 0;
        char price_start[20], price_finish[20];
        printf("Please enter the start of price range(if you wish to only look for a specific age enter 0 for this filed): ");
        gets(price_start);
        printf("Please enter the end of price range: ");
        gets(price_finish);
        system("cls");
        report_sale_residential_price(price_start, price_finish);
        report_sale_commercial_price(price_start, price_finish);
        report_sale_filed_price(price_start, price_finish);
    }
    case 6:
    {
        system("cls");
        inner_flag = 0;
        char floor_start[6], floor_finish[6];
        printf("Please enter the start of room range(if you wish to only look for a specific age enter 0 for this filed): ");
        gets(floor_start);
        printf("Please enter the end of room range: ");
        gets(floor_finish);
        system("cls");
        report_rent_residential_room(floor_start, floor_finish);
        report_rent_commercial_room(floor_start, floor_finish);
        report_sale_residential_room(floor_start, floor_finish);
        report_sale_commercial_room(floor_start, floor_finish);
    }
    case 7:
    {
        system("cls");
        if(report_price_total() == 0)
        {
            printf("There is no price to show!\n");
            printf("For getting back to report menu , press any key....");
            getchar();
            if(strcmp(current_user->user_name, "admin\n")== 0)
            {
                page_admin_report();
            }
            else
            {
                page_reports_normal();
            }
        }
        else
        {
            printf("The total worth of salable buildings and fileds are equal to: %lld\n", report_price_total());
            printf("For getting back to report menu , press any key....");
            getchar();
            if(strcmp(current_user->user_name, "admin\n")== 0)
            {
                page_admin_report();
            }
            else
            {
                page_reports_normal();
            }
        }
    }
    case 8:
    {
        system("cls");
        inner_flag = 0;
        char prepayment_start[20], prepayment_end[20], rent_start[20], rent_end[20];
        printf("Please enter the start of prepayment range(if you wish to only look for a specific age enter 0 for this filed): ");
        gets(prepayment_start);
        printf("Please enter the end of room range: ");
        gets(prepayment_end);
        printf("Please enter the start of rent range: ");
        gets(rent_start);
        printf("Please enter the end of rent range:(if you wish to only look for a specific age enter 0 for this filed)");
        gets(rent_end);
        system("cls");
        report_rent_residential_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
        report_rent_commercial_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
        report_rent_filed_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
    }
    case 9:
    {
        system("cls");
        report_user_trunover();
        printf("\nFor getting back to the report menu , press any key.....");
        getchar();
        page_admin_report();
    }
    case 10:
    {
        system("cls");
        report_date_main_registered_buildings();
        break;
    }
    case 11:
    {
        system("cls");
        inner_flag = 0;
        char chose[12];
        printf("Please enter an amount for floor: ");
        gets(chose);
        strcat(chose, "\n");
        system("cls");
        report_sale_residential_floor(chose);
        report_rent_residential_floor(chose);
        report_rent_commercial_floor(chose);
        report_sale_commercial_floor(chose);
        break;
    }
    case 12:
    {
        system("cls");
        report_date_main_deleted_buildings();
    }
    case 13:
    {
        system("cls");
        report_time_user();
        printf("Press any key to get back to the menu");
        getchar();
    }
    case 14:
    {
        system("cls");
        main_page();
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option!");
        Sleep(2500);
        page_admin_report();
    }
    }
}
void report_date_main_deleted_buildings()
{
    system("cls");
    int option;
    printf("Reports\\deleted buildings\n");
    printf("1. past week\n");
    printf("2. past month\n");
    printf("3. past 3 month\n");
    printf("4. back\n");
    printf("Please enter a option: ");
    scanf("%d", &option);
    getchar();
    switch(option)
    {
    case 1:
    {
        inner_flag = 0;
        report_date_main_deleted_building_week();
        break;
    }
    case 2:
    {
        inner_flag = 0;
        report_date_main_deleted_building_three_month();
        break;
    }
    case 3:
    {
        inner_flag = 0;
        report_date_main_deleted_building_month();
        break;
    }
    case 4:
    {
        if(strcmp(current_user->user_name, "admin\n") == 0)
        {
            page_admin_report();
        }
        else
        {
            page_reports_normal();
        }
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option!");
        Sleep(1500);
        report_date_main_registered_buildings();
    }
    }
}
void report_date_main_deleted_building_month()
{
    system("cls");
    FILE *fp;
    BUILDING_RENT *rent;
    BUILDING_SALE *sale;
    unsigned long current_time, file_time;
    printf("Reports\\deleted buildings\\in a month\n");
    current_time = time(NULL);
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time_delete;
        if((file_time -current_time ) <= (31 * 24 * 60 * 60))
        {
            if(strcmp(sale->isactive, "0\n" == 0))
            {
                printf("ID: %s", sale->id);
                printf("Municipality's area: %s", sale->municipalitys_area);
                printf("Address of building: %s", sale->address_of_building);
                printf("Model of building: %s", sale->model);
                printf("Age of building: %s", sale->age_of_building);
                printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
                printf("Amount of floors: %s", sale->amount_of_floors);
                printf("The size of the main land: %s", sale->size_of_the_main_land);
                printf("Phone number of owner: %s", sale->phone_number_of_owner);
                printf("Amount of rooms: %s", sale->amount_of_floors);
                printf("Price: %s", sale->price);
                printf("\n");
                inner_flag++;
            }
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time_delete;
        if((file_time -current_time ) <= (31 * 24 * 60 * 60))
        {
            if(strcmp(sale->isactive, "0\n") == 0)
            {
                printf("ID: %s", sale->id);
                printf("Municipality's area: %s", sale->municipalitys_area);
                printf("Address of building: %s", sale->address_of_building);
                printf("Model of building: %s", sale->model);
                printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
                printf("Phone number of owner: %s", sale->phone_number_of_owner);
                printf("Price: %s", sale->price);
                printf("\n");
                inner_flag++;
            }
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time_delete;
        if((current_time - file_time) <= (31 * 24 * 60 * 60))
        {
            if(strcmp(rent->isactive, "0\n") == 0)
            {
                printf("ID: %s", rent->id);
                printf("Municipality's area: %s", rent->municipalitys_area);
                printf("Address of building: %s", rent->address_of_building);
                printf("Model of building: %s", rent->model);
                printf("Age of building: %s", rent->age_of_building);
                printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
                printf("Amount of floors: %s", rent->amount_of_floors);
                printf("The size of the main land: %s", rent->size_of_the_main_land);
                printf("Phone number of owner: %s", rent->phone_number_of_owner);
                printf("Amount of rooms: %s", rent->amount_of_floors);
                printf("Prepayment: %s", rent->prepayment);
                printf("Rent per month: %s", rent->rent_per_month);
                printf("\n");
                inner_flag++;
            }
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time_delete;
        if(((current_time - file_time) <= (31 * 24 * 60 * 60)) && (strcmp(rent->isactive, "0\n") == 0))
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time_delete;
        if(((current_time - file_time) <= (31 * 24 * 60 * 60)) && strcmp(rent->isactive, "0\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time_delete;
        if(((current_time - file_time) <= (31 * 24 * 60 * 60)) && strcmp(sale->isactive, "0\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    if(inner_flag == 0)
    {
        printf("There is no item to show!");
        Sleep(1500);
        report_date_main_registered_buildings();
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        report_date_main_registered_buildings();
    }
}
void report_date_main_deleted_building_three_month()
{
    system("cls");
    FILE *fp;
    BUILDING_RENT *rent;
    BUILDING_SALE *sale;
    unsigned long current_time, file_time;
    printf("Reports\\deleted buildings\\in a 3 month\n");
    current_time = time(NULL);
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time_delete;
        if(strcmp(sale->isactive, "0\n" == 0))
        {
            if(file_time -current_time  <= (3* 31 * 24 * 60 * 60))

            {
                printf("ID: %s", sale->id);
                printf("Municipality's area: %s", sale->municipalitys_area);
                printf("Address of building: %s", sale->address_of_building);
                printf("Model of building: %s", sale->model);
                printf("Age of building: %s", sale->age_of_building);
                printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
                printf("Amount of floors: %s", sale->amount_of_floors);
                printf("The size of the main land: %s", sale->size_of_the_main_land);
                printf("Phone number of owner: %s", sale->phone_number_of_owner);
                printf("Amount of rooms: %s", sale->amount_of_floors);
                printf("Price: %s", sale->price);
                printf("\n");
                inner_flag++;
            }
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time_delete;
        if(((file_time -current_time ) <= ( 3* 31 * 24 * 60 * 60)) && strcmp(sale->isactive, "0\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time_delete;
        if(((current_time - file_time) <= (3* 31 * 24 * 60 * 60)) && strcmp(rent->isactive, "0\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time_delete;
        if(((current_time - file_time) <= (3* 31 * 24 * 60 * 60)) && strcmp(rent->isactive, "0\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time_delete;
        if(((current_time - file_time) <= (3* 31 * 24 * 60 * 60)) && strcmp(rent->isactive, "0\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time_delete;
        if(((current_time - file_time) <= (3* 31 * 24 * 60 * 60)) && strcmp(sale->isactive, "0\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    if(inner_flag == 0)
    {
        printf("There is no item to show!");
        Sleep(1500);
        report_date_main_registered_buildings();
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        report_date_main_registered_buildings();
    }
}
void report_date_main_deleted_building_week()
{
    system("cls");
    FILE *fp;
    BUILDING_RENT *rent;
    BUILDING_SALE *sale;
    unsigned long current_time, file_time;
    printf("Reports\\deleted buildings\\in a week\n");
    current_time = time(NULL);
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time_delete;
        if((file_time -current_time ) <= (7 * 24 * 60 * 60))
        {
            if(strcmp(sale->isactive, "0\n" == 0))
            {
                printf("ID: %s", sale->id);
                printf("Municipality's area: %s", sale->municipalitys_area);
                printf("Address of building: %s", sale->address_of_building);
                printf("Model of building: %s", sale->model);
                printf("Age of building: %s", sale->age_of_building);
                printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
                printf("Amount of floors: %s", sale->amount_of_floors);
                printf("The size of the main land: %s", sale->size_of_the_main_land);
                printf("Phone number of owner: %s", sale->phone_number_of_owner);
                printf("Amount of rooms: %s", sale->amount_of_floors);
                printf("Price: %s", sale->price);
                printf("\n");
                inner_flag++;
            }
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time_delete;
        if(((file_time -current_time ) <= (7 * 24 * 60 * 60)) && strcmp(sale->isactive, "0\n" == 0))
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time_delete;
        if(((current_time - file_time) <= (7 * 24 * 60 * 60)) && strcmp(rent->isactive, "0\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time_delete;
        if(((current_time - file_time) <= (7 * 24 * 60 * 60)) && strcmp(rent->isactive, "0\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time_delete;
        if(((current_time - file_time) <= (7 * 24 * 60 * 60)) && strcmp(rent->isactive, "0\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time_delete;
        if(((current_time - file_time) <= (7 * 24 * 60 * 60)) && strcmp(sale->isactive, "0\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    if(inner_flag == 0)
    {
        printf("There is no item to show!");
        Sleep(1500);
        report_date_main_registered_buildings();
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        report_date_main_registered_buildings();
    }
}
void report_date_main_registered_buildings()
{
    system("cls");
    int option;
    printf("Reports\\registered buildings\n");
    printf("1. past week\n");
    printf("2. past month\n");
    printf("3. past 3 month\n");
    printf("4. back\n");
    printf("Please enter a option: ");
    scanf("%d", &option);
    getchar();
    switch(option)
    {
    case 1:
    {
        inner_flag = 0;
        report_date_main_registered_building_week();
        break;
    }
    case 2:
    {
        inner_flag = 0;
        report_date_main_registered_building_month();
        break;
    }
    case 3:
    {
        inner_flag = 0;
        report_date_main_registered_building_month();
        break;
    }
    case 4:
    {
        if(strcmp(current_user->user_name, "admin\n") == 0)
        {
            page_admin_report();
        }
        else
        {
            page_reports_normal();
        }
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option!");
        Sleep(1500);
        report_date_main_registered_buildings();
    }
    }
}
void report_date_main_registered_building_month()
{
    system("cls");
    FILE *fp;
    BUILDING_RENT *rent;
    BUILDING_SALE *sale;
    unsigned long current_time, file_time;
    printf("Reports\\registered buildings\\in a month\n");
    current_time = time(NULL);
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time;
        if(((file_time -current_time ) <= (31 * 24 * 60 * 60)) && strcmp(sale->isactive, "1\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("Age of building: %s", sale->age_of_building);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Amount of floors: %s", sale->amount_of_floors);
            printf("The size of the main land: %s", sale->size_of_the_main_land);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Amount of rooms: %s", sale->amount_of_floors);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time;
        if(((file_time -current_time ) <= (31 * 24 * 60 * 60)) && strcmp(sale->isactive, "1\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time;
        if(((current_time - file_time) <= (31 * 24 * 60 * 60)) && strcmp(rent->isactive, "1\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time;
        if(((current_time - file_time) <= (31 * 24 * 60 * 60)) && strcmp(rent->isactive, "1\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time;
        if(((current_time - file_time) <= (31 * 24 * 60 * 60)) && strcmp(rent->isactive, "1\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time;
        if(((current_time - file_time) <= (31 * 24 * 60 * 60)) && strcmp(sale->isactive, "1\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    if(inner_flag == 0)
    {
        printf("There is no item to show!");
        Sleep(1500);
        report_date_main_registered_buildings();
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        report_date_main_registered_buildings();
    }
}
void report_date_main_registered_building_three_month()
{
    FILE *fp;
    BUILDING_RENT *rent;
    BUILDING_SALE *sale;
    unsigned long current_time, file_time;
    current_time = time(NULL);
    printf("Reports\\registered buildings\\in 3 month\n");
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time;
        if(((file_time -current_time ) <= (3* 31 * 24 * 60 * 60)) && strcmp(sale->isactive, "1\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("Age of building: %s", sale->age_of_building);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Amount of floors: %s", sale->amount_of_floors);
            printf("The size of the main land: %s", sale->size_of_the_main_land);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Amount of rooms: %s", sale->amount_of_floors);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time;
        if(((file_time -current_time ) <= (3* 31 * 24 * 60 * 60)) && strcmp(sale->isactive, "1\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time;
        if(((current_time - file_time) <= (3* 31 * 24 * 60 * 60)) && strcmp(rent->isactive, "1\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time;
        if(((current_time - file_time) <= (3* 31 * 24 * 60 * 60)) && strcmp(rent->isactive, "1\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time;
        if(((current_time - file_time) <= (3* 31 * 24 * 60 * 60)) && strcmp(rent->isactive, "1\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time;
        if(((current_time - file_time) <= (3* 31 * 24 * 60 * 60)) && strcmp(sale->isactive, "1\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    if(inner_flag == 0)
    {
        printf("There is no item to show!");
        Sleep(1500);
        report_date_main_registered_buildings();
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        report_date_main_registered_buildings();
    }
}
void report_date_main_registered_building_week()
{
    system("cls");
    FILE *fp;
    BUILDING_RENT *rent;
    BUILDING_SALE *sale;
    unsigned long int current_time, file_time;
    printf("Reports\\registered buildings\\in a week\n");
    current_time = time(NULL);
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    sale = start_building_sale;

    while(sale->link != NULL)
    {
        file_time = sale->time;
        if(strcmp(sale->isactive, "1\n") == 0)
        {
            if((current_time -  file_time) <= (7 * 24 * 60 * 60))
            {
                printf("ID: %s", sale->id);
                printf("Municipality's area: %s", sale->municipalitys_area);
                printf("Address of building: %s", sale->address_of_building);
                printf("Model of building: %s", sale->model);
                printf("Age of building: %s", sale->age_of_building);
                printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
                printf("Amount of floors: %s", sale->amount_of_floors);
                printf("The size of the main land: %s", sale->size_of_the_main_land);
                printf("Phone number of owner: %s", sale->phone_number_of_owner);
                printf("Amount of rooms: %s", sale->amount_of_floors);
                printf("Price: %s", sale->price);
                printf("\n");
                inner_flag++;
            }
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);

    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time;
        if(((file_time -current_time ) <= (7 * 24 * 60 * 60)) && strcmp(sale->isactive, "1\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time;
        if(((current_time - file_time) <= (7 * 24 * 60 * 60)) && strcmp(rent->isactive, "1\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time;
        if(((current_time - file_time) <= (7 * 24 * 60 * 60)) && strcmp(rent->isactive, "1\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("Age of building: %s", rent->age_of_building);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Amount of floors: %s", rent->amount_of_floors);
            printf("The size of the main land: %s", rent->size_of_the_main_land);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Amount of rooms: %s", rent->amount_of_floors);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    rent = start_building_rent;
    while(rent->link != NULL)
    {
        file_time = rent->time;
        if(((current_time - file_time) <= (7 * 24 * 60 * 60)) && strcmp(rent->isactive, "1\n") == 0)
        {
            printf("ID: %s", rent->id);
            printf("Municipality's area: %s", rent->municipalitys_area);
            printf("Address of building: %s", rent->address_of_building);
            printf("Model of building: %s", rent->model);
            printf("The size of the infrastructure: %s", rent->size_of_the_infrastructure);
            printf("Phone number of owner: %s", rent->phone_number_of_owner);
            printf("Prepayment: %s", rent->prepayment);
            printf("Rent per month: %s", rent->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        rent = rent->link;
    }
    fclose(fp);
    make_null_list_building_rent();
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    sale = start_building_sale;
    while(sale->link != NULL)
    {
        file_time = sale->time;
        if(((current_time - file_time) <= (7 * 24 * 60 * 60)) && strcmp(sale->isactive, "1\n") == 0)
        {
            printf("ID: %s", sale->id);
            printf("Municipality's area: %s", sale->municipalitys_area);
            printf("Address of building: %s", sale->address_of_building);
            printf("Model of building: %s", sale->model);
            printf("The size of the infrastructure: %s", sale->size_of_the_infrastructure);
            printf("Phone number of owner: %s", sale->phone_number_of_owner);
            printf("Price: %s", sale->price);
            printf("\n");
            inner_flag++;
        }
        sale = sale->link;
    }
    fclose(fp);
    make_null_list_building_sale();

    if(inner_flag == 0)
    {
        printf("There is no item to show!");
        Sleep(1500);
        report_date_main_registered_buildings();
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        report_date_main_registered_buildings();
    }
}
void report_user_trunover()
{
    FILE *fp_user, *fp_building;
    USER *temp;
    BUILDING_RENT *build_rent;
    BUILDING_SALE *build_sale;
    fp_user = fopen("Files\\users\\user.txt", "r");
    make_list_user(fp_user);
    temp = start_user;
    while(temp != NULL)
    {
        temp->registered_builiding = 0;
        fp_building = fopen("Files\\building\\for_sale\\Residential.txt", "r");
        make_list_building_sale(fp_building);
        build_sale = start_building_sale;
        while(build_sale != NULL)
        {
            if(strcmp(build_sale->user, temp->user_name) == 0)
            {
                temp->registered_builiding++;
            }
            build_sale = build_sale->link;
        }
        make_null_list_building_sale();
        fclose(fp_building);
        fp_building = fopen("Files\\building\\for_sale\\Commercial.txt", "r");

        make_list_building_sale(fp_building);
        build_sale = start_building_sale;
        while(build_sale != NULL)
        {
            if(strcmp(build_sale->user, temp->user_name) == 0)
            {
                \
                temp->registered_builiding++;
            }
            build_sale = build_sale->link;
        }
        make_null_list_building_sale();
        fclose(fp_building);
        fp_building = fopen("Files\\building\\for_sale\\Filed.txt", "r");
        make_list_building_sale_filed(fp_building);
        build_sale = start_building_sale;
        while(build_sale != NULL)
        {
            if(strcmp(build_sale->user, temp->user_name) == 0)
            {
                temp->registered_builiding++;
            }
            build_sale = build_sale->link;
        }
        make_null_list_building_sale();
        fclose(fp_building);
        fp_building = fopen("Files\\building\\for_rent\\Residential.txt", "r");
        make_list_building_rent(fp_building);
        build_rent = start_building_rent;
        while(build_rent != NULL)
        {
            if(strcmp(build_rent->user, temp->user_name) == 0)
            {
                temp->registered_builiding++;
            }
            build_rent = build_rent->link;
        }
        make_null_list_building_rent();
        fclose(fp_building);
        fp_building = fopen("Files\\building\\for_rent\\Commercial.txt", "r");
        make_list_building_rent(fp_building);
        build_rent = start_building_rent;
        while(build_rent != NULL)
        {
            if(strcmp(build_rent->user, temp->user_name) == 0)
            {
                temp->registered_builiding++;
            }
            build_rent = build_rent->link;
        }
        make_null_list_building_rent();
        fclose(fp_building);
        fp_building = fopen("Files\\building\\for_rent\\Filed.txt", "r");
        make_list_building_rent_filed(fp_building);
        build_rent = start_building_rent;
        while(build_rent != NULL)
        {
            if(strcmp(build_rent->user, temp->user_name) == 0)
            {
                temp->registered_builiding++;
            }
            build_rent = build_rent->link;
        }
        make_null_list_building_rent();
        fclose(fp_building);
        temp = temp->link;
    }
    sortLinkedList(&start_user);
    temp = start_user;
    while(temp != NULL)
    {
        temp->user_name[strlen(temp->user_name) - 1] = '\0';
        if(strcmp(temp->user_name, "") != 0)
        {
            printf("the user: %s\n", temp->user_name);
            printf("The amount of buildings that registered by %s: %d\n\n",temp->user_name, temp->registered_builiding);

        }
        temp = temp->link;
    }
    make_null_list_user();
    fclose(fp_user);
}
void report_rent_residential_rent_mortgage(char start_perpay[20], char end_prepay[20], char start_rent[20], char end_rent[20])
{
    long int age_start, age_end, rent_start,rent_end, rent_file, pre_file;
    age_start = atol(start_perpay);
    age_end = atol(end_prepay);
    rent_start = atol(start_rent);
    rent_end = atol(end_rent);
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        pre_file = atol(temp->prepayment);
        rent_file= atol(temp->rent_per_month);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(pre_file >= age_start && pre_file <= age_end)
            {
                if(rent_file >= rent_start && rent_file <= rent_end)
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
                    printf("Rent per month: %s", temp->rent_per_month);
                    printf("\n");
                    inner_flag++;

                }
            }
        }
        temp = temp->link;
    }
    fclose(fp);
    make_null_list_building_rent();
}
void report_rent_commercial_rent_mortgage(char start_perpay[20], char end_prepay[20], char start_rent[20], char end_rent[20])
{
    long int age_start, age_end, rent_start,rent_end, rent_file, pre_file;
    age_start = atol(start_perpay);
    age_end = atol(end_prepay);
    rent_start = atol(start_rent);
    rent_end = atol(end_rent);
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        pre_file = atol(temp->prepayment);
        rent_file= atol(temp->rent_per_month);

        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(pre_file >= age_start && pre_file <= age_end)
            {
                if(rent_file >= rent_start && rent_file <= rent_end)
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
                    printf("Rent per month: %s", temp->rent_per_month);
                    printf("\n");
                    inner_flag++;
                }

            }

        }
        temp = temp->link;
    }

    make_null_list_building_rent();
    fclose(fp);
}
void report_rent_filed_rent_mortgage(char start_perpay[20], char end_prepay[20], char start_rent[20], char end_rent[20])
{
    long int age_start, age_end, rent_start,rent_end, rent_file, pre_file;
    age_start = atol(start_perpay);
    age_end = atol(end_prepay);
    rent_start = atol(start_rent);
    rent_end = atol(end_rent);

    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        pre_file = atol(temp->prepayment);
        rent_file= atol(temp->rent_per_month);

        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(pre_file >= age_start && pre_file <= age_end)
            {
                if(rent_file >= rent_start && rent_file <= rent_end)
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
                    printf("Rent per month: %s", temp->rent_per_month);
                    printf("\n");
                    inner_flag++;
                }
            }

        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);
    if(inner_flag == 0)
    {
        printf("There is no item to show!\n");
    }
    printf("For getting back press any key.....");
    getchar();
    if(strcmp("admin\n", current_user->user_name) == 0)
    {
        page_admin_report();
    }
    else
    {
        page_reports_normal();
    }

}
void report_rent_residential_floor(char chose[30])
{
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->amount_of_floors, chose) == 0)
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
            printf("Rent per month: %s", temp->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
    fclose(fp);
    make_null_list_building_rent();
}
void report_rent_commercial_floor(char chose[30])
{
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {

        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->amount_of_floors, chose) == 0)
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
            printf("Rent per month: %s", temp->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
    fclose(fp);
    make_null_list_building_rent();

}
void report_sale_residential_floor(char chose[30])
{
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->amount_of_floors, chose) == 0)
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
    fclose(fp);
    make_null_list_building_sale();
}
void report_sale_commercial_floor(char chose[30])
{
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->amount_of_floors, chose) == 0)
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
    fclose(fp);
    make_null_list_building_sale();
    if(inner_flag == 0)
    {
        printf("There is no item to show!\n");
    }
    printf("For getting back press any key.....");
    getchar();
    if(strcmp("admin\n", current_user->user_name) == 0)
    {
        page_admin_report();
    }
    else
    {
        page_reports_normal();
    }
}
long long unsigned report_price_total()
{
    BUILDING_SALE *temp;
    unsigned long long Total_worth = 0;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            Total_worth += atoll(temp->price);
        }
        temp = temp->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            Total_worth += atoll(temp->price);
        }
        temp = temp->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            Total_worth += atoll(temp->price);
        }
        temp = temp->link;
    }
    fclose(fp);
    make_null_list_building_sale();
    return Total_worth;
}
void report_rent_residential_room(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
        age_file = atoi(temp->amount_of_rooms);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end)
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
                printf("Rent per month: %s", temp->rent_per_month);
                printf("\n");
                inner_flag++;
            }

        }
        temp = temp->link;
    }
    fclose(fp);
    make_null_list_building_rent();
}
void report_rent_commercial_room(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
        age_file = atoi(temp->amount_of_rooms);

        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end)
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
                printf("Rent per month: %s", temp->rent_per_month);
                printf("\n");
                inner_flag++;
            }

        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);
}
void report_sale_residential_room(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
        age_file = atoi(temp->amount_of_rooms);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end)
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

        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    fclose(fp);
}
void report_sale_commercial_room(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
        age_file = atoi(temp->amount_of_rooms);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end)
            {
                printf("ID: %s", temp->id);
                printf("Municipality's area: %s", temp->municipalitys_area);
                printf("Address of building: %s", temp->address_of_building);
                printf("Model of building: %s", temp->model);
                printf("Age of building: %s", temp->age_of_building);
                printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
                printf("Amo, price_finishunt of floors: %s", temp->amount_of_floors);
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
    fclose(fp);
    if(inner_flag == 0)
    {
        printf("There is no item to show!\n");

    }
    printf("For getting back press any key.....");
    getchar();
    if(strcmp(current_user->user_name, "admin\n")==0)
    {
        page_admin_report();
    }
    else
    {
        page_reports_normal();
    }
}
void report_rent_residential_age(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
            if(age_file >= age_start && age_file <= age_end)
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
                printf("Rent per month: %s", temp->rent_per_month);
                printf("\n");
                inner_flag++;
            }

        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);
}
void report_rent_commercial_age(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
            if(age_file >= age_start && age_file <= age_end)
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
                printf("Rent per month: %s", temp->rent_per_month);
                printf("\n");
                inner_flag++;
            }

        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);
    if(inner_flag == 0)
    {
        printf("There is no item to show!\n");

    }
    printf("For getting back press any key.....");
    getchar();
    if(strcmp("admin\n", current_user->user_name) == 0)
    {
        page_admin_report();
    }
    else
    {
        page_reports_normal();
    }

}
void report_rent_residential_size(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
            if(age_file >= age_start && age_file <= age_end)
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
                printf("Rent per month: %s", temp->rent_per_month);
                printf("\n");
                inner_flag++;
            }

        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);
}
void report_rent_commercial_size(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
            if(age_file >= age_start && age_file <= age_end)
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
                printf("Rent per month: %s", temp->rent_per_month);
                printf("\n");
                inner_flag++;
            }

        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);
}
void report_rent_filed_size(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        age_file = atoi(temp->size_of_the_infrastructure);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end)
            {
                printf("ID: %s", temp->id);
                printf("Municipality's area: %s", temp->municipalitys_area);
                printf("Address of building: %s", temp->address_of_building);
                printf("Model of building: %s", temp->model);
                printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
                printf("Phone number of owner: %s", temp->phone_number_of_owner);
                printf("Prepayment: %s", temp->prepayment);
                printf("Rent per month: %s", temp->rent_per_month);
                printf("\n");
                inner_flag++;
            }
        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);

}
void report_sale_residential_size(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
            if(age_file >= age_start && age_file <= age_end)
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
        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    fclose(fp);
}
void report_sale_commercial_size(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
            if(age_file >= age_start && age_file <= age_end)
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
        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    fclose(fp);
}
void report_sale_filed_size(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
            if(age_file >= age_start && age_file <= age_end)
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
        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    fclose(fp);
    if(inner_flag == 0)
    {
        printf("There is no item to show!\n");
    }
    printf("For getting back press any key.....");
    getchar();
    if(strcmp(current_user->user_name, "admin\n")==0)
    {
        page_admin_report();
    }
    else
    {
        page_reports_normal();
    }

}
void report_sale_residential_age(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
            if(age_file >= age_start && age_file <= age_end)
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

        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    fclose(fp);
}
void report_sale_residential_price(char start_age[20], char end_age[20])
{
    long int age_start, age_end,  age_file;
    age_start = atol(start_age);
    age_end = atol(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atol(temp->price);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end)
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

        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    fclose(fp);
}
void report_sale_commercial_price(char start_age[20], char end_age[20])
{
    long int age_start, age_end,  age_file;
    age_start = atol(start_age);
    age_end = atol(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atol(temp->price);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end)
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
        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    fclose(fp);
}
void report_sale_filed_price(char start_age[20], char end_age[20])
{
    long int age_start, age_end,  age_file;
    age_start = atol(start_age);
    age_end = atol(end_age);
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        age_file = atol(temp->price);
        if(strcmp(temp->isactive, "1\n") == 0)
        {
            if(age_file >= age_start && age_file <= age_end)
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
        }
        temp = temp->link;
    }
    if(inner_flag == 0)
    {
        printf("There is no item to show!\n");
    }
    fclose(fp);
    make_null_list_building_sale();
    printf("For getting back press any key.....");
    getchar();
    if(strcmp(current_user->user_name, "admin\n")== 0)
    {
        page_admin_report();
    }
    else
    {
        page_reports_normal();
    }

}
void report_sale_commercial_age(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
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
            if(age_file >= age_start && age_file <= age_end)
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
        }
        temp = temp->link;
    }
    make_null_list_building_sale();
    fclose(fp);
}
void report_rent_residential_area(char chose[30])
{
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Residential.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area, chose) == 0)
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
            printf("Rent per month: %s", temp->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);
}
void report_rent_commercial_area(char chose[30])
{
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Commercial.txt", "r+");
    make_list_building_rent(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {

        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area, chose) == 0)
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
            printf("Rent per month: %s", temp->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);

}
void report_rent_filed_area(char chose [30])
{
    char id[7], TEMP[21];
    BUILDING_RENT *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_rent\\Filed.txt", "r+");
    make_list_building_rent_filed(fp);
    temp = start_building_rent;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area, chose) == 0)
        {
            printf("ID: %s", temp->id);
            printf("Municipality's area: %s", temp->municipalitys_area);
            printf("Address of building: %s", temp->address_of_building);
            printf("Model of building: %s", temp->model);
            printf("The size of the infrastructure: %s", temp->size_of_the_infrastructure);
            printf("Phone number of owner: %s", temp->phone_number_of_owner);
            printf("Prepayment: %s", temp->prepayment);
            printf("Rent per month: %s", temp->rent_per_month);
            printf("\n");
            inner_flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);

}
void report_sale_residential_area(char chose[30])
{
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Residential.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area, chose) == 0)
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
    fclose(fp);
}
void report_sale_commercial_area(char chose[30])
{
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Commercial.txt", "r+");
    make_list_building_sale(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area, chose) == 0)
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
    fclose(fp);
}
void report_sale_filed_area(char chose[30])
{
    char id[7], TEMP[21];
    BUILDING_SALE *temp;
    FILE *fp;
    fp = fopen("Files\\building\\for_sale\\Filed.txt", "r+");
    make_list_building_sale_filed(fp);
    temp = start_building_sale;
    while(temp != NULL)
    {
        if(strcmp(temp->isactive, "1\n") == 0 && strcmp(temp->municipalitys_area, chose) == 0)
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
    fclose(fp);
    if(inner_flag == 0)
    {
        printf("There is no item to show!\n");
    }
    printf("For getting back press any key.....");
    getchar();
    if(strcmp("admin\n", current_user->user_name) == 0)
    {
        page_admin_report();
    }
    else
    {
        page_reports_normal();
    }

}
void report_model_main()
{

    system("cls");
    int option;
    printf("Reports\\specific model of buildings\n");
    printf("1. For sale\n");
    printf("2. For rent\n");
    printf("3. Back\n");
    printf("Please chose an option: ");
    scanf("%d", &option);
    getchar();
    switch(option)
    {
    case 1:
    {
        report_model_building_model_sale();
        break;
    }
    case 2:
    {
        report_model_building_model_rent();
        break;
    }
    case 3:
    {
        if(strcmp("admin\n", current_user->user_name) == 0)
        {
            page_admin_report();
        }
        else
        {
            page_reports_normal();
        }
        break;
    }
    default:
    {
        printf("Please enter a valid option!");
        Sleep(1000);
        system("cls");
        report_model_main();
    }
    }
}
void report_model_building_model_sale()
{
    system("cls");
    int option;
    printf("Reports\\specific model of buildings\\for sale\n");
    printf("1. Residential buildings\n");
    printf("2. Commercial\n");
    printf("3. Normal filed\n");
    printf("4. back\n");
    printf("Please chose an option: ");
    scanf("%d", &option);
    getchar();
    switch(option)
    {
    case 1:
    {
        report_sale_residential();
        break;
    }
    case 2:
    {
        report_sale_commercial();
        break;
    }
    case 3:
    {
        report_sale_filed();
        break;
    }
    case 4:
    {
        report_model_main();
        break;
    }
    default:
    {
        printf("Please enter a valid option!");
        Sleep(1000);
        system("cls");
        report_model_building_model_sale();
    }
    }
}
void report_model_building_model_rent()
{
    system("cls");
    int option;
    printf("Reports\\specific model of buildings\\for rent\n");
    printf("1. Residential buildings\n");
    printf("2. Commercial\n");
    printf("3. Normal filed\n");
    printf("4. back\n");
    printf("Please chose an option: ");
    scanf("%d", &option);
    getchar();
    switch(option)
    {
    case 1:
    {
        report_rent_residential();
        break;
    }
    case 2:
    {
        report_rent_commercial();
        break;
    }
    case 3:
    {
        report_rent_filed();
        break;
    }
    case 4:
    {
        report_model_main();
        break;
    }
    default:
    {
        printf("Please enter a valid option!");
        Sleep(1000);
        system("cls");
        report_model_building_model_rent();
    }
    }
}
void report_rent_residential()
{
    system("cls");
    printf("Reports\\specific model of buildings\\for rent\\report_rent_residential\n");
    char id[7], TEMP[21], checker;
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
            printf("Rent per month: %s", temp->rent_per_month);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);

    if(flag == 0)
    {
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_rent();
    }
    while(1)
    {
        printf("\nPlease enter B for getting back to report menu: ");
        checker = getche();
        if(checker == 'b' || checker == 'B')
        {
            report_model_building_model_rent();
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
        }
    }
}
void report_rent_commercial()
{
    system("cls");
    printf("Reports\\specific model of buildings\\for rent\\commercial\n");
    char id[7], TEMP[21], checker;
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
            printf("Rent per month: %s", temp->rent_per_month);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);
    if(flag == 0)
    {
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_rent();
    }
    while(1)
    {
        printf("\nPlease enter B for getting back to report menu: ");
        checker = getche();
        if(checker == 'b' || checker == 'B')
        {

            report_model_building_model_rent();
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
        }
    }
}
void report_rent_filed()
{
    system("cls");
    printf("Reports\\specific model of buildings\\for rent\\filed\n");
    char id[7], TEMP[21], checker;
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
            printf("Rent per month: %s", temp->rent_per_month);
            printf("\n");
            flag++;
        }
        temp = temp->link;
    }
    make_null_list_building_rent();
    fclose(fp);
    if(flag == 0)
    {
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_rent();
    }
    while(1)
    {
        printf("\nPlease enter B for getting back to report menu: ");
        checker = getche();
        if(checker == 'b' || checker == 'B')
        {

            report_model_building_model_rent();
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
        }
    }
}
void report_sale_residential()
{
    system("cls");
    printf("Reports\\specific model of buildings\\for sale\\residential\n");
    char id[7], TEMP[21], checker;
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
    fclose(fp);
    if(flag == 0)
    {
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_sale();
    }
    while(1)
    {
        printf("\nPlease enter B for getting back to report menu: ");
        checker = getche();
        if(checker == 'b' || checker == 'B')
        {
            report_model_building_model_sale();
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
        }
    }
}
void report_sale_commercial()
{
    system("cls");
    printf("Reports\\specific model of buildings\\for sale\\commercial\n");
    char id[7], TEMP[21], checker;
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
    fclose(fp);
    make_null_list_building_sale();
    if(flag == 0)
    {
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_sale();
    }
    while(1)
    {
        printf("\nPlease enter B for getting back to report menu: ");
        checker = getche();
        if(checker == 'b' || checker == 'B')
        {
            report_model_building_model_sale();
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
        }
    }
}
void report_sale_filed()
{
    system("cls");
    printf("Reports\\specific model of buildings\\for sale\\field\n");
    char id[7], TEMP[21], checker;
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
    fclose(fp);
    if(flag == 0)
    {
        printf("There is no item to show!");
        Sleep(2500);
        report_model_building_model_sale();
    }
    while(1)
    {
        printf("\nPlease enter B for getting back to report menu: ");
        checker = getche();
        if(checker == 'b' || checker == 'B')
        {
            report_model_building_model_sale();
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
        }
    }
}
void page_reports_normal()
{
    system("cls");
    int option;
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
    printf("\nPlease choice your report: ");
    scanf("%d", &option);
    getchar();
    switch(option)
    {
    case 1:
    {
        report_model_main();
        break;
    }
    case 2:
    {
        inner_flag = 0;
        char chose[12];
        printf("Please enter a municipalitys area: ");
        gets(chose);
        strcat(chose, "\n");
        system("cls");
        report_sale_residential_area(chose);
        report_sale_commercial_area(chose);
        report_rent_residential_area(chose);
        report_rent_commercial_area(chose);
        report_rent_filed_area(chose);
        report_sale_filed_area(chose);
        break;
    }
    case 3:
    {
        inner_flag = 0;
        char age_start[6], age_finish[6];
        printf("Please enter the start of age range: ");
        gets(age_start);
        printf("Please enter the end of age range:(if you wish to only look for a specific age enter 0 for this filed): ");
        gets(age_finish);
        system("cls");
        report_sale_residential_age(age_start, age_finish);
        report_sale_commercial_age(age_start, age_finish);
        report_rent_residential_age(age_start, age_finish);
        report_rent_commercial_age(age_start, age_finish);
    }
    case 4:
    {
        inner_flag = 0;
        char size_start[6], size_finish[6];
        printf("Please enter the start of size range: ");
        gets(size_start);
        printf("Please enter the end of size range:(if you wish to only look for a specific age enter 0 for this filed)");
        gets(size_finish);
        system("cls");
        report_sale_residential_size(size_start, size_finish);
        report_sale_commercial_size(size_start, size_finish);
        report_rent_filed_size(size_start, size_finish);
        report_rent_residential_size(size_start, size_finish);
        report_rent_commercial_size(size_start, size_finish);
        report_sale_filed_size(size_start, size_finish);
    }
    case 5:
    {
        inner_flag = 0;
        char price_start[20], price_finish[20];
        printf("Please enter the start of price range: ");
        gets(price_start);
        printf("Please enter the end of price range:(if you wish to only look for a specific age enter 0 for this filed)");
        gets(price_finish);
        system("cls");
        report_sale_residential_price(price_start, price_finish);
        report_sale_commercial_price(price_start, price_finish);
        report_sale_filed_price(price_start, price_finish);
    }
    case 6:
    {
        inner_flag = 0;
        char floor_start[6], floor_finish[6];
        printf("Please enter the start of room range: ");
        gets(floor_start);
        printf("Please enter the end of room range:(if you wish to only look for a specific age enter 0 for this filed)");
        gets(floor_finish);
        system("cls");
        report_rent_residential_room(floor_start, floor_finish);
        report_rent_commercial_room(floor_start, floor_finish);
        report_sale_residential_room(floor_start, floor_finish);
        report_sale_commercial_room(floor_start, floor_finish);
    }
    case 7:
    {
        system("cls");
        if(report_price_total() == 0)
        {
            printf("There is no price to show!\n");
            printf("For getting back to report menu , press any key....");
            getchar();
            if(strcmp(current_user->user_name, "admin\n")== 0)
            {
                page_admin_report();
            }
            else
            {
                page_reports_normal();
            }
        }
        else
        {
            printf("The total worth of salable buildings and fileds are equal to: %lld\n", report_price_total());
            printf("For getting back to report menu , press any key....");
            getchar();
            if(strcmp(current_user->user_name, "admin\n")== 0)
            {
                page_admin_report();
            }
            else
            {
                page_reports_normal();
            }
        }
    }
    case 8:
    {
        inner_flag = 0;
        char prepayment_start[20], prepayment_end[20], rent_start[20], rent_end[20];
        printf("Please enter the start of prepayment range: ");
        gets(prepayment_start);
        printf("Please enter the end of room range:(if you wish to only look for a specific age enter 0 for this filed)");
        gets(prepayment_end);
        printf("Please enter the start of rent range: ");
        gets(rent_start);
        printf("Please enter the end of rent range:(if you wish to only look for a specific age enter 0 for this filed)");
        gets(rent_end);
        system("cls");
        report_rent_residential_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
        report_rent_commercial_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
        report_rent_filed_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
    }

    case 9:
    {
        report_date_main_registered_buildings();
        break;
    }
    case 10:
    {
        inner_flag = 0;
        char chose[12];
        printf("Please enter an amount for floor: ");
        gets(chose);
        strcat(chose, "\n");
        system("cls");
        report_sale_residential_floor(chose);
        report_rent_residential_floor(chose);
        report_rent_commercial_floor(chose);
        report_sale_commercial_floor(chose);
        break;
    }
    case 11:
    {
        page_reports_normal();
    }
    default:
    {
        system("cls");
        printf("Please enter a valid option!");
        Sleep(2500);
        page_admin_report();
    }
    }
}

void menu_delete_building()
{
    int checker = 0;
    system("cls");
    printf("Deleting buildings\n");
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
    printf("Deleting buildings\\for sale\n");
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
    printf("Deleting buildings\\for sale\\residential\n");
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
        if(flag != 0)
        {
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
        else
        {
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
    printf("Deleting buildings\\for sale\\commercial\n");
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
        if(flag != 0)
        {
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
        else
        {
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
    printf("Deleting buildings\\for sale\\field\n");
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
        if(flag != 0)
        {
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
        else
        {
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
    printf("Deleting buildings\\for rent\n");
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
void delete_rent_buildings_Residential()
{
    system("cls");
    printf("Deleting buildings\\for rent\\residential\n");
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
        if(flag != 0)
        {
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
                    fputs(temp->rent_per_month, fp);
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
        else
        {
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
void delete_rent_buildings_commercial()
{
    system("cls");
    printf("Deleting buildings\\for rent\\commercial\n");
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
        if(flag != 0)
        {
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
                    fputs(temp->rent_per_month, fp);
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
        else
        {
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
void delete_rent_buildings_filed()
{
    system("cls");
    printf("Deleting buildings\\for rent\\filed\n");
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
        if(flag != 0)
        {
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
                    fputs(temp->rent_per_month, fp);
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
        else
        {
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

void report_time_user()
{
    unsigned long int time;
    FILE *fp;
    char time_str[80];
    struct tm *info;
    USER *temp;
    fp = fopen("Files\\users\\user.txt", "r");
    if(fp == NULL)
    {
        printf("as");
    }
    make_list_user(fp);
    temp = start_user;
    while(temp != last_user)
    {
        temp->user_name[strlen(temp->user_name) - 1] = '\0';
        time = start_user->time_login;
        info = localtime(&time);
        strftime (time_str,80,"20%y/%m/%d",info);
        printf("last time of %s user login is:%s\n",temp->user_name,time_str);
        time = start_user->time_logout;
        info = localtime(&time);
        strftime (time_str,80,"20%y/%m/%d",info);
        printf("last time of %s user logout is:%s\n",temp->user_name, time_str);
        printf("\n");
        temp = temp->link;
    }
    make_null_list_user();
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
        fgets(temp_time, 31, user_fp);
        temp->time_login = atol(temp_time);
        fgets(temp_time, 31, user_fp);
        temp->time_logout = atol(temp_time);
        fgets(temp->ID, 31, user_fp);
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
        if(current_user != NULL)
        {
            if(strcmp(temp->user_name, current_user->user_name)== 0)
            {
                start_user = start_user->link;
                continue;
            }
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
        fgets(temp->age_of_building, 6, building_sale_fp);
        fgets(temp->size_of_the_infrastructure, 10, building_sale_fp);
        fgets(temp->amount_of_floors, 4, building_sale_fp);
        fgets(temp->size_of_the_main_land, 10, building_sale_fp);
        fgets(temp->phone_number_of_owner, 15, building_sale_fp);
        fgets(temp->amount_of_rooms, 13, building_sale_fp);
        fgets(temp->price, 15, building_sale_fp);
        fgets(temp->user, 30, building_sale_fp);
        fgets(TEMP, 20, building_sale_fp);
        temp->time = atol(TEMP);
        fgets(temp->isactive, 3, building_sale_fp);
        fgets(temp->id, 7, building_sale_fp);
        fgets(TEMP, 20, building_sale_fp);
        temp->time_delete = atol(TEMP);
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
        temp->time = atol(TEMP);
        fgets(temp->isactive, 3, building_sale_fp);
        fgets(temp->id, 7, building_sale_fp);
        fgets(TEMP, 20, building_sale_fp);
        temp->time_delete = atol(TEMP);
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
        fgets(temp->age_of_building, 6, building_rent_fp);
        fgets(temp->size_of_the_infrastructure, 10, building_rent_fp);
        fgets(temp->amount_of_floors, 6, building_rent_fp);
        fgets(temp->size_of_the_main_land, 10, building_rent_fp);
        fgets(temp->phone_number_of_owner, 15, building_rent_fp);
        fgets(temp->amount_of_rooms, 6, building_rent_fp);
        fgets(temp->prepayment, 15, building_rent_fp);
        fgets(temp->rent_per_month, 15, building_rent_fp);
        fgets(temp->user, 30, building_rent_fp);
        fgets(TEMP, 25, building_rent_fp);
        temp->time = atol(TEMP);
        fgets(temp->isactive, 3, building_rent_fp);
        fgets(temp->id, 7, building_rent_fp);
        fgets(TEMP, 20, building_rent_fp);
        temp->time_delete = atol(TEMP);
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
        temp->time = atol(TEMP);
        fgets(temp->isactive, 3, building_rent_fp);
        fgets(temp->id, 7, building_rent_fp);
        fgets(TEMP, 20, building_rent_fp);
        temp->time_delete = atol(TEMP);
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
void sortListHelper(USER **head, USER *newNode)
{
    USER temp;
    USER *current = &temp;
    temp.link = *head;
    while (current->link != NULL && current->link->registered_builiding > newNode->registered_builiding)
    {
        current = current->link;
    }

    newNode->link = current->link;
    current->link = newNode;
    *head = temp.link;
}
void sortLinkedList(USER **head)
{
    USER *answerList = NULL;


    USER *current = *head;
    USER *nextNode;

    while (current != NULL)
    {

        nextNode = current->link;
        sortListHelper(&answerList, current);
        current = nextNode;
    }
    *head = answerList;
}
void make_ansiescape_work(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hConsole != INVALID_HANDLE_VALUE)
    {
        DWORD mode = 0;
        if(GetConsoleMode(hConsole, &mode))
        {
            mode |=0x0004;
            SetConsoleMode(hConsole, mode);
        }
    }
}
int isalldigit(char string[] , int lenght){
    int flag = 0;
    for(int index = 0 ; index < lenght ; index++){
        if(isdigit(string[index]) == 0){
            flag = 1;
        }
    }
    if(flag == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int password_checker(char password[],int size){
    int flag_Digit = 0 , flag_Upper_alpha = 0,flag_Lower_alpha = 0, flag_Special_char = 0;
    if(size < 8){
        return 4;
    }
    for(int index = 0 ; index < size ; size++){
        if(isdigit(password[index])){
            flag_Digit = 1;
        }
        if(isalpha(password[index]) && islower(password[index])){
            flag_Lower_alpha = 1;
        }
        if(isalpha(password[index]) && isupper(password[index])){
            flag_Lower_alpha = 1;
        }
        if(isalnum(password[index]) == 0){
            flag_Special_char = 1;
        }
    }
    if(flag_Digit == 0){
        return 0;
    }
    if(flag_Lower_alpha == 0){
        return 1;
    }
    if(flag_Upper_alpha == 0){
        return 2;
    }
    if(flag_Special_char == 0){
        return 3;
    }
    return 5;

}
int isaddress(char string[] , int lenght){
    int flag = 0;
    for(int index = 0 ; index < lenght ; index++){
        if(isalnum(string[index]) == 0 && string[index] != '-'){
            flag = 1;
        }
        if(string[index] == '-' && (string[index + 1] == '\0' || string[index + 1] == '-')){
            flag = 1;
        }
    }
    if(flag == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int isallalpha(char string[] , int lenght){
    int flag = 0;
    for(int index = 0 ; index < lenght ; index++){
        if(isalpha(string[index]) == 0){
            flag = 1;
        }
    }
    if(flag == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int isemail(char email[] , int lenght){
    int Index_of_atsign = 0;
    int isfalse = 0;
    int Index_of_Dot = 0;
    for(int index = 0 ; index  < lenght ; index++){
        if(isalnum(email[index] == 0) && (email[index] != '@' || email[index] != '_' ||  email[index] != '.')){                     isfalse = 1;
        isfalse = 1;
        }
    }
    for(int index = 0 ; lenght > index ; index++){
        if(email[index] == '@' && email[index - 1] == '.'){
            isfalse = 1;
        }
        else if(email[index] == '@' ){
            Index_of_atsign = index;
        }
    }
    for(int index = 0 ; index < Index_of_atsign ; index++){
        if(isalpha(email[index]) <= 0 && isdigit(email[index]) == 0){
            if(email[index] != '.'){
                isfalse = 1;
                break;
            }
        }
    }
    for(int index = Index_of_atsign + 1 ; index < lenght ; index++){
        if(email[index] == '.' && email[index + 1] == '.'){
            isfalse = 1;
            break;
        }
        else if(email[index] == '.' && email[index + 1] == '\0'){
            isfalse = 1;
            break;
        }
        else if(email[index] == '.'){
            Index_of_Dot = index;
        }
        else if(isalpha(email[index]) <= 0){
            if(email[index] != '.' || isdigit(email[index]) == 1){
                isfalse = 1;
                break;
            }
        }
    }
    if(Index_of_Dot == 0){
            isfalse = 1;
        }

    if(email[Index_of_atsign + 1] == '\0'){
        isfalse = 1;
    }
    if(Index_of_atsign == 0){
        isfalse = 1;
    }
    if(isfalse == 1){
        return -1;
    }
    else{
        return 1;
    }

}
void main()
{
    make_ansiescape_work();
    /*USER *user;
    user = malloc(sizeof(USER));
    strcpy(user->email, "amir@fgm.com");
    strcpy(user->ID, "2");
    strcpy(user->last_name, "sca");
    strcpy(user->name, "ewsa");
    strcpy(user->password, "1324");
    strcpy(user->phone, "4587");
    strcpy(user->user_name, "admin\n");
    current_user = user;*/
    Start_Page();

}
