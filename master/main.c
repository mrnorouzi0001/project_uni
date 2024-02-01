#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "cryptography\cryptography.h"
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")
struct building_sale
{
    char *municipalitys_area[6];
    char *address_of_building[100];
    char *model[20];
    char *age_of_building[6];
    char *size_of_the_infrastructure[10];
    char *amount_of_floors[6];
    char *size_of_the_main_land[10];
    char *phone_number_of_owner[15];
    char *amount_of_rooms[6];
    char *price[15];
    char *user[30];
    unsigned long int time;
    char *isactive[3];
    char id[7];
    unsigned long int time_delete;
    struct building_sale *link;
}*start_building_sale = NULL, *last_building_sale;
struct building_rent
{
    char *municipalitys_area[6];
    char *address_of_building[100];
    char *model[20];
    char *age_of_building[6];
    char *size_of_the_infrastructure[10];
    char *amount_of_floors[6];
    char *size_of_the_main_land[10];
    char *phone_number_of_owner[15];
    char *amount_of_rooms[6];
    char *prepayment[15];
    char *rent_per_month[15];
    char *user[30];
    unsigned long int time;
    char *isactive[3];
    char *id[7];
    unsigned long int time_delete;
    struct building_rent *link;
}*start_building_rent, *last_building_rent;
struct user
{
    char *user_name[30];
    char *password[20];
    char *name[25];
    char *last_name[45];
    char *phone[15];
    char *email[35];
    unsigned long int time_login;
    unsigned long int time_logout;
    int registered_builiding;
    char *ID[20];
    char *isactive[3];
    unsigned long int time_banish;
    struct user *link;
}*start_user = NULL, *last_user = NULL;

typedef struct building_sale BUILDING_SALE;
typedef struct user USER;
typedef struct building_rent BUILDING_RENT;

USER *current_user;
int inner_flag = 0;

void Edit_application_background_color();
void Edit_application_text_color();
void Edit_application_name();
void menu_edit_application();
void adding_rent_buildings_commercial();
void adding_rent_buildings_filed();
void adding_rent_buildings_Residential();
void adding_sale_buildings_commercial();
void adding_sale_buildings_Residential();
void adding_sale_buildings_filed();
void delete_menu_rent_buildings();
void delete_menu_sale_buildings();
void delete_rent_buildings_commercial();
void delete_rent_buildings_filed();
void delete_rent_buildings_Residential();
void delete_sale_buildings_commercial();
void delete_sale_buildings_Residential();
void delete_sale_buildings_filed();
const char * getting_app_name();
const char * getting_app_background_color();
const char * getting_app_Text_color();
int isaddress(char string[], int lenght);
int isallalpha(char string[], int lenght);
int isalldigit(char string[], int lenght);
int isemail(char string[], int lenght);
void logout_time();
void main();
void main_page();
void make_ansiescape_work();
void make_list_building_rent();
void make_list_building_rent_filed();
void make_list_building_sale();
void make_list_building_sale_filed();
void make_list_user(FILE *user_fp);
void make_null_list_building_rent();
void make_null_list_building_sale();
void make_null_list_user();
void make_str_null(char string[]);
void menu_adding_building();
void menu_delete_building();
void menu_rent_buildings();
void menu_sale_buildings();
void page_admin_report();
void page_reports_normal();
int password_checker(char password[], int size);
void Pre_Start();
int PreStart_Checker();
void report_date_main_deleted_buildings_month();
void report_date_main_deleted_building_three_month();
void report_date_main_deleted_building_week();
void report_date_main_deleted_buildings();
void report_date_main_registered_building_month();
void report_date_main_registered_building_three_month();
void report_date_main_registered_building_week();
void report_date_main_registered_buildings();
void report_model_building_model_rent();
void report_model_building_model_sale();
void report_model_main();
unsigned long long report_price_total();
void report_rent_commercial();
void report_rent_commercial_age(char start_age[6], char end_age[6]);
void report_rent_commercial_area(char chose[30]);
void report_rent_commercial_floor(char chose[30]);
void report_rent_commercial_rent_mortgage(char start_prepay[20], char end_prepay[20], char start_rent[20], char end_rent[20]);
void report_rent_commercial_room(char start_age[6], char end_age[6]);
void report_rent_commercial_size(char start_age[6], char end_age[6]);
void report_rent_filed();
void report_rent_filed_area(char chose[30]);
void report_rent_filed_rent_mortgage(char start_prepay[20], char end_prepay[20], char start_rent[20], char end_rent[20]);
void report_rent_filed_size(char start_age[6], char end_age[6]);
void report_rent_residential();
void report_rent_residential_age(char start_age[6], char end_age[6]);
void report_rent_residential_area(char chose[30]);
void report_rent_residential_floor(char chose[30]);
void report_rent_residential_rent_mortgage(char start_prepay[20], char end_prepay[20], char start_rent[20], char end_rent[20]);
void report_rent_residential_room(char start_age[6], char end_age[6]);
void report_rent_residential_size(char start_age[6], char end_age[6]);
void report_sale_commercial();
void report_sale_commercial_age(char start_age[6], char end_age[6]);
void report_sale_commercial_area(char chose[30]);
void report_sale_commercial_floor(char chose[30]);
void report_sale_commercial_price(char start_age[20], char end_age[20]);
void report_sale_commercial_room(char start_age[6], char end_age[6]);
void report_sale_commercial_size(char start_age[6], char end_age[6]);
void report_sale_filed();
void report_sale_filed_area(char chose[30]);
void report_sale_filed_price(char start_age[20], char end_age[20]);
void report_sale_filed_size(char start_age[6], char end_age[6]);
void report_sale_residential();
void report_sale_residential_age(char start_age[6], char end_age[6]);
void report_sale_residential_area(char chose[30]);
void report_sale_residential_floor(char chose[30]);
void report_sale_residential_price(char start_age[6], char end_age[6]);
void report_sale_residential_room(char start_age[6], char end_age[6]);
void report_sale_residential_size(char start_age[6], char end_age[6]);
void report_time_user();
void report_user_trunover();
void report_time_user();
void report_user_trunover();
int search_password_list_user(char user_name[30], char password[20]);
int search_username_list_user(char user_name[30]);
void sign_in();
void sign_up();
void sortLinkedList(USER **head);
void sortListHelper(USER **head, USER *newNode);
void Start_Page();
void user_edit();
void sign_up()
{
    PlaySound("Audios\\Sign_up.wav",NULL,SND_ASYNC | SND_FILENAME);
    int index = 0, stars = 0, checker = 0;
    char temp_time[31], option, character, password[30];
    system("cls");
    printf("For getting back press b: ");
    if(tolower(getche()) == 'b')
    {
        return;
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
    while(1)
    {
        while(1)
        {
            printf("\nPlease enter a user name: ");
            gets(user->user_name);
            if(strlen(user->user_name) <= 28)
            {
                break;
            }
            else
            {
                printf("User name can not be more than 28 characters!");
                fflush(stdin);
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            }
        }

        strcat(user->user_name, "\n");
        if(search_username_list_user(user->user_name)== 1)
        {
            printf("This user name has already taken.");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
        }
        else
        {
            user->user_name[strlen(user->user_name) - 1] = '\0';
            break;
        }
    }
    make_null_list_user();
    while(1)
    {
        while(1)
        {
            printf("\nPlease enter your password: ");
            index = 0;
            stars = 0;
            while(1)
            {
                character = getch();
                if(character == 13)
                {
                    printf("\n");
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
            checker = password_checker(user->password, strlen(user->password));

            if(strlen(user->password) > 18)
            {
                printf("your password can have 18 characters at maximum!");
                fflush(stdin);
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                continue;
            }
            if(checker == 4)
            {
                printf("You need to enter at least 8 characters for your password!");
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                continue;
            }
            if(checker == 0)
            {
                printf("You need to enter at least 1 number for your password!");
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                continue;
            }
            if(checker == 1)
            {
                printf("You need to enter at least a lower case alphabet for your password!");
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                continue;
            }
            if(checker == 2)
            {
                printf("You need to enter at least a upper case alphabet for your password!");
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                continue;
            }
            if(checker == 3)
            {
                printf("You need to enter at least a Special character(@,#,%) for your password!");
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                continue;

            }
            if(checker == 5)
            {
                break;
            }
        }
        printf("\n");
        while(1)
        {
            printf("Please enter your password again: ");
            gets(password);
            if(strlen(password) > 18)
            {
                printf("passwords aren't matched!\n");
                fflush(stdin);
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                continue;
            }
            break;
        }
        if(strcmp(password, user->password) ==0)
        {
            break;
        }
        else
        {
            printf("passwords aren't matched!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
    }
    printf("\n");
    crypto(user->password, strlen(user->password));

    printf("\n            personal information\n");
    while(1)
    {
        printf("\nPlease enter your name: ");
        gets(user->name);
        if(23 < strlen(user->name))
        {
            printf("Your name can have 23 character at maximum!");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        if(isallalpha(user->name, strlen(user->name)) == 0)
        {
            printf("Please enter a valid name!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        break;
    }
    while(1)
    {
        printf("\nPlease enter your last name: ");
        gets(user->last_name);
        if(43 < strlen(user->last_name))
        {
            printf("Your last name can have 43 character at maximum!");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        if(isallalpha(user->last_name, strlen(user->last_name)) == 0)
        {
            printf("Please enter a valid last name!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        break;
    }
    while(1)
    {
        printf("\nPlease enter Your phone number: ");
        gets(user->phone);
        if(strlen(user->phone) != 11)
        {
            printf("Your phone number must have 11 digits!");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        if(user->phone[0] != '0')
        {
            printf("Your phone number must starts with 0 digit!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        if(isalldigit(user->phone, strlen(user->phone)) == 0)
        {
            printf("Please enter a valid phone number!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        break;
    }
    while(1)
    {
        printf("\nPlease enter Your email: ");
        gets(user->email);
        if(strlen(user->email) > 33)
        {
            printf("Your email can have 33 characters at maximum!");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        if(isemail(user->email, strlen(user->email)) == -1)
        {
            printf("Please enter a valid email!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        break;
    }
    while(1)
    {
        printf("\nPlease enter Your ID: ");
        gets(user->ID);
        if(strlen(user->ID) != 10)
        {
            printf("your ID must have 10 digits!");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        if(isalldigit(user->ID, strlen(user->ID)) == 0)
        {
            printf("Please enter a valid ID!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        break;
    }
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
            fputs("1", user_fp);
            fputs("\n", user_fp);
            fputs("0", user_fp);
            fputs("\n", user_fp);
            system("cls");
            Sleep(2000);
            PlaySound("Audios\\Sign_up_sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
            printf("the user has added to the application successfully!");
            free(user);
            free(user_fp);
            fclose(user_fp);
            Sleep(3000);
            return;
        }
        if(option == 'N' || option == 'n')
        {
            free(user);
            fclose(user_fp);
            system("cls");
            return;
        }
        else
        {
            printf("Please enter a valid character!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
        }
    }

}
void sign_in()
{
    system("cls");
    printf("For getting back press b: ");
    if(tolower(getche()) == 'b')
    {
        return;
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
    char *user_name[30], *password[25];
    while(1)
    {
        printf("Please enter your user name: ");
        gets(user_name);
        if(strlen(user_name) > 28)
        {
            printf("Please enter user name that is 28 characters at maximum!\n");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        break;
    }

    printf("%s", user_name);
    strcat(user_name, "\n");
    make_list_user(user_fp);
    int tries = 0;
    if(search_username_list_user(user_name) == 1)
    {
        temp = malloc(sizeof(USER));
        temp = start_user;
        while(temp != last_user)
        {
            if(strcmp(user_name, temp->user_name) == 0 && strcmp(temp->isactive, "0\n") == 0 && (time(NULL) - temp->time_banish) < 900)
            {
                PlaySound("Audios\\Banned.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("\nYou are banned from the application for %ld:%ld", 15 - (time(NULL) - temp->time_banish)/ 60, 60 - ((time(NULL) - temp->time_banish) % 60));
                free(temp);
                fclose(user_fp);
                Sleep(2000);
                system("cls");
                make_null_list_user();
                return;
            }
            temp = temp->link;
        }
        free(temp);
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
            crypto(password, strlen(password));
            strcat(password, "\n");
            if(tries == 5)
            {
                PlaySound("Audios\\Failed_attemps.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("Too many failed attempts. You are banned for 15 minutes from application!");
                Sleep(10000);
                system("cls");
                fclose(user_fp);
                user_fp = fopen("Files\\users\\user.txt", "w+");
                temp = malloc(sizeof(USER));
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
                    if(strcmp(user_name, temp->user_name) == 0)
                    {
                        fputs("0", user_fp);
                        fputs("\n", user_fp);
                        itoa(time(NULL), time_tmep, 10);
                        fputs(time_tmep, user_fp);
                        fputs("\n", user_fp);
                    }
                    else
                    {
                        fputs(temp->isactive, user_fp);
                        itoa(temp->time_banish, time_tmep, 10);
                        fputs(time_tmep, user_fp);
                        fputs("\n", user_fp);
                    }
                    temp = temp->link;
                }
                fclose(user_fp);
                make_null_list_user();
                system("cls");
                return;
            }
            if(search_password_list_user(user_name,password) == 1)
            {
                break;
            }
            else
            {
                PlaySound("Audios\\Pass_not_match.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("wrong password! %d tries left!\n", 5 - tries );
                tries++;
                Sleep(5000);
            }
        }
        PlaySound("Audios\\Sucess_login.wav",NULL,SND_ASYNC | SND_FILENAME);
        printf("logging in. please wait!");
        fclose(user_fp);
        user_fp = fopen("Files\\users\\user.txt", "w+");
        temp = malloc(sizeof(USER));
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
            if(strcmp(temp->user_name, user_name) == 0)
            {
                fputs("1", user_fp);
                fputs("\n", user_fp);
                fputs("0", user_fp);
                fputs("\n", user_fp);
            }
            else
            {
                fputs(temp->isactive, user_fp);
                itoa(temp->time_banish, time_tmep, 10);
                fputs(time_tmep, user_fp);
                fputs("\n", user_fp);
            }
            temp = temp->link;
        }
        Sleep(3000);
        fclose(user_fp);
        make_null_list_user();
        system("cls");
        main_page();
    }
    else
    {
        PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
        printf("we don't have this user name!");
        Sleep(3000);
        fclose(user_fp);
        make_null_list_user();
        return;
    }
}
void main_page()
{
    PlaySound("Audios\\Main_menu.wav",NULL,SND_ASYNC | SND_FILENAME);
    int option = 0;
    system("cls");
    printf("Welcome Dear %s", current_user->user_name);
    while(1)
    {
        option = 0;
        system("cls");
        printf("Welcome Dear %s", current_user->user_name);
        printf("1. Adding new building\n");
        printf("2. Deleting the buildings\n");
        printf("3. Reports\n");
        printf("4. settings\n");
        printf("5. sign out\n");
        printf("6. application settings\n");
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
            Sleep(3000);
            return;
        }
        case 6:
        {

            system("cls");
            if(strcmp(current_user->user_name, "admin\n") == 0)
            {
                menu_edit_application();
                break;
            }
            else
            {
                PlaySound("Audios\\Only_admin.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("Only admin can change the program settings!");
                Sleep(3000);
            }
            break;
        }
        default:
        {
            printf("Please enter a valid option");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            system("cls");
            break;
        }
        }

    }
}
const char * getting_app_name()
{
    static char * name[52];
    FILE *fp;
    fp = fopen("Files\\PreStart\\Settings.txt", "r");
    fgets(name, 52, fp);
    name[strlen(name) - 1] = '\0';
    fclose(fp);
    return name;
}
const char * getting_app_background_color()
{
    static char * BG_color[52];
    FILE *fp;
    fp = fopen("Files\\PreStart\\Settings.txt", "r");
    fgets(BG_color, 52, fp);
    fgets(BG_color, 52, fp);
    BG_color[strlen(BG_color) - 1] = '\0';
    fclose(fp);
    return BG_color;
}
const char * getting_app_Text_color()
{
    static char * Text_color[52];
    FILE *fp;
    fp = fopen("Files\\PreStart\\Settings.txt", "r");
    fgets(Text_color, 52, fp);
    fgets(Text_color, 52, fp);
    fgets(Text_color, 52, fp);
    fclose(fp);
    return Text_color;
}
void user_edit()
{
    PlaySound("Audios\\User_edit.wav",NULL,SND_ASYNC | SND_FILENAME);
    int index = 0, stars = 0;
    system("cls");
    char *tempstr[34], *temp_pass_valid[25], *temp_user[25], *temp_time[15], checker, character;
    FILE *user_fp;
    user_fp = fopen("Files\\users\\user.txt", "r");
    make_list_user(user_fp);
    USER *temp, *temp_current = NULL;
    printf("For getting back, press b: ");
    if(tolower(getche()) == 'b')
    {
        return;
    }
    fclose(user_fp);
    printf("\33[2K\r");
    if(temp_current == NULL)
    {
        temp_current = malloc(sizeof(USER));
    }
    printf("User settings\n");
    printf("        if you don't want to change a filed , leave it blank\n\n");

    strcpy(temp_user, current_user->user_name);
    while(1)
    {

        printf("\nPlease enter your new name: ");
        gets(tempstr);
        if(strcmp(tempstr, "") == 0)
        {
            break;
        }
        if(isallalpha(tempstr, strlen(tempstr)) == 0)
        {
            printf("Please enter a valid name!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        if(strlen(tempstr) > 23)
        {
            printf("Your name can have 23 character at maximum!");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        break;
    }
    if(strcmp(tempstr, "") != 0)
    {
        strcat(tempstr, "\n");
        strcpy(temp_current->name,  tempstr);
    }
    else
    {
        strcpy(temp_current->name, current_user->name);
    }
    while(1)
    {
        printf("\nPlease enter your last new name: ");
        gets(tempstr);
        if(strcmp(tempstr, "") == 0)
        {
            break;
        }
        if(isallalpha(tempstr, strlen(tempstr)) == 0)
        {
            printf("Please enter a valid last name!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;

        }
        if(strlen(tempstr) > 43)
        {

            printf("Your last name can have 43 character at maximum!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            fflush(stdin);
            continue;
        }

        break;
    }
    if(strcmp(tempstr, "") != 0)
    {
        strcat(tempstr, "\n");
        strcpy(temp_current->last_name, tempstr);
    }
    else
    {
        strcpy(temp_current->last_name, current_user->last_name);
    }
    while(1)
    {
        printf("\nPlease enter your new ID: ");
        gets(tempstr);
        if(strcmp(tempstr, "") == 0)
        {
            break;
        }
        if(strlen(tempstr) != 10)
        {
            printf("your ID must have 10 digits!");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        if(isallalpha(tempstr, strlen(tempstr)) == 0)
        {
            printf("Please enter a valid ID!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        break;

    }
    if(strcmp(tempstr, "") != 0)
    {
        strcat(tempstr, "\n");
        strcpy(temp_current->ID, tempstr);
    }
    else
    {
        strcpy(temp_current->ID, current_user->ID);
    }
    while(1)
    {
        printf("\nPlease enter your new Phone: ");

        gets(tempstr);
        if(strcmp(tempstr, "") == 0)
        {
            break;
        }
        if(strlen(tempstr) != 10)
        {
            fflush(stdin);
            printf("Your phone number must have 10 digits!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        if(tempstr[0] != '0')
        {
            printf("Your phone number must starts with 0 digit!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        if(isalldigit(tempstr, strlen(tempstr)) == 0)
        {
            printf("Please enter a valid phone number!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }

        break;
    }
    if(strcmp(tempstr, "") != 0)
    {
        strcat(tempstr, "\n");
        strcpy(temp_current->phone, tempstr);
    }
    else
    {
        strcpy(temp_current->phone, current_user->phone);
    }
    while(1)
    {
        printf("\nPlease enter your new Email:");
        gets(tempstr);
        if(strcmp(tempstr, "") == 0)
        {
            break;
        }
        if(strlen(tempstr) > 33)
        {
            printf("Your email can have 33 characters at maximum!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        if(isemail(tempstr, strlen(tempstr)) == -1)
        {
            printf("Please enter a valid email!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            fflush(stdin);
            continue;
        }
        break;
    }
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
        stars = 0;
        index = 0;
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
                printf("\nPlease enter your password: ");
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
        if(strcmp(tempstr, "") == 0)
        {
            break;
        }
        if(strlen(tempstr) > 18)
        {
            printf("your password can have 18 characters at maximum!");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        if(password_checker(tempstr, strlen(tempstr)) == 4)
        {
            printf("You need to enter at least 8 characters for your password!");

            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            continue;
        }
        if(password_checker(tempstr, strlen(tempstr)) == 0)
        {
            printf("You need to enter at least 1 number for your password!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        if(password_checker(tempstr, strlen(tempstr)) == 1)
        {
            printf("You need to enter at least a lower case alphabet for your password!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        if(password_checker(tempstr, strlen(tempstr)) == 2)
        {
            printf("You need to enter at least a upper case alphabet for your password!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        if(password_checker(tempstr, strlen(tempstr)) == 3)
        {
            printf("You need to enter at least a Special character(@,#,%) for your password!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
        if(password_checker(tempstr, strlen(tempstr)) == 5)
        {
            break;
        }

    }
    printf("\n");
    while(1)
    {
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
                printf("\nPlease enter your password again: ");
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
        if(strcmp(tempstr, "") == 0)
        {
            break;
        }
        if(strlen(temp_pass_valid) > 18)
        {
            fflush(stdin);
            printf("your password can have 18 characters at maximum!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

            continue;
        }
    }
    printf("\n");
    if(strcmp(tempstr, "") != 0)
    {
        while(1)
        {
            if(strcmp(tempstr, temp_pass_valid) == 0)
            {
                crypto(tempstr, strlen(tempstr));
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
                        printf("Please enter your new password again: ");
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
                    fputs(temp->isactive, user_fp);

                    itoa(temp->time_banish, temp_time, 10);
                    fputs(temp_time, user_fp);
                    fputs("\n", user_fp);
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
                    fputs(temp_current->isactive, user_fp);
                    itoa(temp_current->time_banish, temp_time, 10);
                    fputs(temp_time, user_fp);
                    fputs("\n", user_fp);
                }
                temp = temp->link;
            }
            current_user = temp_current;
            make_null_list_user();
            fclose(user_fp);
            system("cls");
            PlaySound("Audios\\Sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
            printf("The user was edited Successfully!");
            Sleep(2000);
            return;
        }
        else if(checker == 'N' || checker == 'n')
        {
            make_null_list_user();
            fclose(user_fp);
            system("cls");
            free(temp_current);
            return;
        }
        else
        {
            printf("\nPlease enter a valid character!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
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

        fputs(temp->isactive, user_fp);
        itoa(temp->time_banish, time_tmep, 10);
        fputs(time_tmep, user_fp);
        fputs("\n", user_fp);
        temp = temp->link;
    }
    fclose(user_fp);
    make_null_list_user();
}
void Start_Page()
{
    PlaySound("Audios\\Start_page.wav",NULL,SND_ASYNC | SND_FILENAME);
    int checker = 0;
    int flag = 0;
    while(1)
    {
        flag = 0;
        checker = 0;
        system("cls");
        printf("Welcome to the %s real state agency!\n", getting_app_name());
        printf("%s", getting_app_background_color());
        printf("%s", getting_app_Text_color());
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
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            printf("Please enter a valid option");
            Sleep(3500);
            system("cls");

            break;
        }
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
    PlaySound("Audios\\menu_adding_main.wav",NULL,SND_ASYNC | SND_FILENAME);
    while(1)
    {
        checker = 0;
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
            return;
            break;
        }
        default:
        {
            system("cls");
            printf("Please enter a valid option");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            break;
        }
        }
    }

}
void menu_sale_buildings()
{
    PlaySound("Audios\\menu_adding_main_for_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
    int checker = 0;
    while(1)
    {
        checker = 0;
        system("cls");
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
            return;
            break;
        }
        default:
        {
            system("cls");
            printf("Please enter a valid option");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            break;
        }
        }
    }
}
void adding_sale_buildings_Residential()
{
    PlaySound("Audios\\adding_residental_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
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

    while(1)
    {
        printf("Please enter the municipality's area: ");
        gets(building->municipalitys_area);
        if(strlen(building->municipalitys_area) > 4)
        {
            fflush(stdin);
            printf("You can have 9999 municipality areas at maximum!\n");
            continue;
        }
        if(isalldigit(building->municipalitys_area, strlen(building->municipalitys_area)) == 0)
        {
            printf("Please enter a valid number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter the address of building: ");
        gets(building->address_of_building);
        if(strlen(building->address_of_building) > 98)
        {
            fflush(stdin);
            printf("Your address can have 98 characters at maximum!\n");
            continue;
        }
        if(isaddress(building->address_of_building, strlen(building->address_of_building)) == 0)
        {
            printf("Please enter a valid address!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter model of building: ");
        gets(building->model);
        if(strlen(building->model) > 18)
        {
            fflush(stdin);
            printf("Your model type can have 18 characters at maximum!\n");
            continue;
        }
        if(isallalpha(building->model, strlen(building->model)) == 0)
        {
            printf("Please enter a valid model!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter age of building: ");
        gets(building->age_of_building);
        if(strlen(building->age_of_building) > 4)
        {
            fflush(stdin);
            printf("Your building can be 9999 years old at maximum!\n");
            continue;
        }
        if(isalldigit(building->age_of_building, strlen(building->age_of_building)) == 0)
        {
            printf("Please enter a valid age!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the infrastructure: ");
        gets(building->size_of_the_infrastructure);
        if(strlen(building->size_of_the_infrastructure) > 8)
        {
            fflush(stdin);
            printf("your building can be 99999999 m^2 at maximum!\n");
            continue;
        }
        if(isalldigit(building->size_of_the_infrastructure, strlen(building->size_of_the_infrastructure)) == 0)
        {
            printf("Please enter a valid size!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter amount of floors: ");
        gets(building->amount_of_floors);
        if(strlen(building->amount_of_floors)> 4)
        {
            fflush(stdin);
            printf("Your building can have 9999 floors at maximum!\n");
            continue;
        }
        if(isalldigit(building->amount_of_floors, strlen(building->amount_of_floors)) == 0)
        {
            printf("Please enter a valid number for floors!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the main land: ");
        gets(building->size_of_the_main_land);
        if(strlen(building->size_of_the_main_land)> 8)
        {
            fflush(stdin);
            printf("Your building can have 99999999 m^2 at maximum!\n");
            continue;
        }
        if(isalldigit(building->size_of_the_main_land, strlen(building->size_of_the_main_land)) == 0)
        {
            printf("Please enter a valid number for size of main land!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter phone number of owner: ");
        gets(building->phone_number_of_owner);
        if(strlen(building->phone_number_of_owner) != 11)
        {
            fflush(stdin);
            printf("Your phone number must have 11 digits!\n");
            continue;
        }
        if(building->phone_number_of_owner[0] != '0')
        {
            printf("Your phone number must starts with 0 digit!\n");
            continue;
        }
        if(isalldigit(building->phone_number_of_owner, strlen(building->phone_number_of_owner)) == 0)
        {
            printf("Please enter a valid phone number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter amount of rooms: ");
        gets(building->amount_of_rooms);
        if(strlen(building->amount_of_rooms) > 4)
        {
            fflush(stdin);
            printf("Your building can have 9999 rooms at maximum!\n");
            continue;
        }
        if(isalldigit(building->amount_of_rooms, strlen(building->amount_of_rooms)) == 0)
        {
            printf("Please enter a valid number for amount of rooms!\n");
            continue;
        }
        break;

    }
    while(1)
    {
        printf("Please enter price: ");
        gets(building->price);
        if(strlen(building->price) > 13)
        {
            fflush(stdin);
            printf("Your building price can be 9-999-999-999-999 at maximum!\n");
            continue;
        }
        if(isalldigit(building->price, strlen(building->price)) == 0)
        {
            printf("Please enter a valid price for price!\n");
            continue;
        }
        break;
    }

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
        return;
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        return;
    }

}
void adding_sale_buildings_commercial()
{
    PlaySound("Audios\\adding_comm_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
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
    while(1)
    {
        printf("Please enter the municipality's area: ");
        gets(building->municipalitys_area);
        if(strlen(building->municipalitys_area) > 4)
        {
            fflush(stdin);
            printf("You can have 9999 municipality areas at maximum!\n");
            continue;
        }
        if(isalldigit(building->municipalitys_area, strlen(building->municipalitys_area)) == 0)
        {
            printf("Please enter a valid number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter the address of building: ");
        gets(building->address_of_building);
        if(strlen(building->address_of_building) > 98)
        {
            fflush(stdin);
            printf("Your address can have 98 characters at maximum!\n");
            continue;
        }
        if(isaddress(building->address_of_building, strlen(building->address_of_building)) == 0)
        {
            printf("Please enter a valid address!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter model of building: ");
        gets(building->model);
        if(strlen(building->model) > 18)
        {
            fflush(stdin);
            printf("Your model type can have 18 characters at maximum!\n");
            continue;
        }
        if(isallalpha(building->model, strlen(building->model)) == 0)
        {
            printf("Please enter a valid model!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter age of building: ");
        gets(building->age_of_building);
        if(strlen(building->age_of_building) > 4)
        {
            fflush(stdin);
            printf("Your building can be 9999 years old at maximum!\n");
            continue;
        }
        if(isalldigit(building->age_of_building, strlen(building->age_of_building)) == 0)
        {
            printf("Please enter a valid age!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the infrastructure: ");
        gets(building->size_of_the_infrastructure);
        if(strlen(building->size_of_the_infrastructure) > 8)
        {
            fflush(stdin);
            printf("your building can be 99999999 m^2 at maximum!\n");
            continue;
        }
        if(isalldigit(building->size_of_the_infrastructure, strlen(building->size_of_the_infrastructure)) == 0)
        {
            printf("Please enter a valid size!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter amount of floors: ");
        gets(building->amount_of_floors);
        if(strlen(building->amount_of_floors)> 4)
        {
            fflush(stdin);
            printf("Your building can have 9999 floors at maximum!\n");
            continue;
        }
        if(isalldigit(building->amount_of_floors, strlen(building->amount_of_floors)) == 0)
        {
            printf("Please enter a valid number for floors!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the main land: ");
        gets(building->size_of_the_main_land);
        if(strlen(building->size_of_the_main_land)> 8)
        {
            fflush(stdin);
            printf("Your building can have 99999999 m^2 at maximum!\n");
            continue;
        }
        if(isalldigit(building->size_of_the_main_land, strlen(building->size_of_the_main_land)) == 0)
        {
            printf("Please enter a valid number for size of main land!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter phone number of owner: ");
        gets(building->phone_number_of_owner);
        if(strlen(building->phone_number_of_owner) != 11)
        {
            fflush(stdin);
            printf("Your phone number must have 11 digits!\n");
            continue;
        }
        if(building->phone_number_of_owner[0] != '0')
        {
            printf("Your phone number must starts with 0 digit!\n");
            continue;
        }
        if(isalldigit(building->phone_number_of_owner, strlen(building->phone_number_of_owner)) == 0)
        {
            printf("Please enter a valid phone number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter amount of rooms: ");
        gets(building->amount_of_rooms);
        if(strlen(building->amount_of_rooms) > 4)
        {
            fflush(stdin);
            printf("Your building can have 9999 rooms at maximum!\n");
            continue;
        }
        if(isalldigit(building->amount_of_rooms, strlen(building->amount_of_rooms)) == 0)
        {
            printf("Please enter a valid number for amount of rooms!\n");
            continue;
        }
        break;

    }
    while(1)
    {
        printf("Please enter price: ");
        gets(building->price);
        if(strlen(building->price) > 13)
        {
            fflush(stdin);
            printf("Your building price can be 9-999-999-999-999 at maximum!\n");
            continue;
        }
        if(isalldigit(building->price, strlen(building->price)) == 0)
        {
            printf("Please enter a valid price for price!\n");
            continue;
        }
        break;
    }
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
        PlaySound("Audios\\Sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        return;
    }
}
void adding_sale_buildings_filed()
{
    PlaySound("Audios\\adding_filed_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
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

    while(1)
    {
        printf("Please enter the municipality's area: ");
        gets(building->municipalitys_area);
        if(strlen(building->municipalitys_area) > 4)
        {
            fflush(stdin);
            printf("You can have 9999 municipality areas at maximum!\n");
            continue;
        }
        if(isalldigit(building->municipalitys_area, strlen(building->municipalitys_area)) == 0)
        {
            printf("Please enter a valid number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter the address of building: ");
        gets(building->address_of_building);
        if(strlen(building->address_of_building) > 98)
        {
            fflush(stdin);
            printf("Your address can have 98 characters at maximum!\n");
            continue;
        }
        if(isaddress(building->address_of_building, strlen(building->address_of_building)) == 0)
        {
            printf("Please enter a valid address!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter model of building: ");
        gets(building->model);
        if(strlen(building->model) > 18)
        {
            fflush(stdin);
            printf("Your model type can have 18 characters at maximum!\n");
            continue;
        }
        if(isallalpha(building->model, strlen(building->model)) == 0)
        {
            printf("Please enter a valid model!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the infrastructure: ");
        gets(building->size_of_the_infrastructure);
        if(strlen(building->size_of_the_infrastructure) > 8)
        {
            fflush(stdin);
            printf("your building can be 99999999 m^2 at maximum!\n");
            continue;
        }
        if(isalldigit(building->size_of_the_infrastructure, strlen(building->size_of_the_infrastructure)) == 0)
        {
            printf("Please enter a valid size!\n");
            continue;
        }
        break;
    }


    while(1)
    {
        printf("Please enter phone number of owner: ");
        gets(building->phone_number_of_owner);
        if(strlen(building->phone_number_of_owner) != 11)
        {
            fflush(stdin);
            printf("Your phone number must have 11 digits!\n");
            continue;
        }
        if(building->phone_number_of_owner[0] != '0')
        {
            printf("Your phone number must starts with 0 digit!\n");
            continue;
        }
        if(isalldigit(building->phone_number_of_owner, strlen(building->phone_number_of_owner)) == 0)
        {
            printf("Please enter a valid phone number!\n");
            continue;
        }
        break;
    }

    while(1)
    {
        printf("Please enter price: ");
        gets(building->price);
        if(strlen(building->price) > 13)
        {
            fflush(stdin);
            printf("Your building price can be 9-999-999-999-999 at maximum!\n");
            continue;
        }
        if(isalldigit(building->price, strlen(building->price)) == 0)
        {
            printf("Please enter a valid price for price!\n");
            continue;
        }
        break;
    }

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
        PlaySound("Audios\\Sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        return;
    }
}
void menu_rent_buildings()
{
    PlaySound("Audios\\menu_adding_main_for_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
    int checker = 0;
    while(1)
    {
        checker = 0;
        system("cls");
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
            return;
            break;
        }
        default:
        {
            system("cls");
            printf("Please enter a valid option");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            break;
        }
        }
    }
}
void adding_rent_buildings_Residential()
{
    PlaySound("Audios\\adding_residental_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
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
    while(1)
    {
        printf("Please enter the municipality's area: ");
        gets(building->municipalitys_area);
        if(strlen(building->municipalitys_area) > 4)
        {
            fflush(stdin);
            printf("You can have 9999 municipality areas at maximum!\n");
            continue;
        }
        if(isalldigit(building->municipalitys_area, strlen(building->municipalitys_area)) == 0)
        {
            printf("Please enter a valid number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter the address of building: ");
        gets(building->address_of_building);
        if(strlen(building->address_of_building) > 98)
        {
            fflush(stdin);
            printf("Your address can have 98 characters at maximum!\n");
            continue;
        }
        if(isaddress(building->address_of_building, strlen(building->address_of_building)) == 0)
        {
            printf("Please enter a valid address!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter model of building(apartment or villa): ");
        gets(building->model);
        if(strlen(building->model) > 18)
        {
            fflush(stdin);
            printf("Your model type can have 18 characters at maximum!\n");
            continue;
        }
        if(isallalpha(building->model, strlen(building->model)) == 0)
        {
            printf("Please enter a valid model!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter age of building: ");
        gets(building->age_of_building);
        if(strlen(building->age_of_building) > 4)
        {
            fflush(stdin);
            printf("Your building can be 9999 years old at maximum!\n");
            continue;
        }
        if(isalldigit(building->age_of_building, strlen(building->age_of_building)) == 0)
        {
            printf("Please enter a valid age!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the infrastructure: ");
        gets(building->size_of_the_infrastructure);
        if(strlen(building->size_of_the_infrastructure) > 8)
        {
            fflush(stdin);
            printf("your building can be 99999999 m^2 at maximum!\n");
            continue;
        }
        if(isalldigit(building->size_of_the_infrastructure, strlen(building->size_of_the_infrastructure)) == 0)
        {
            printf("Please enter a valid size!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter amount of floors: ");
        gets(building->amount_of_floors);
        if(strlen(building->amount_of_floors)> 4)
        {
            fflush(stdin);
            printf("Your building can have 9999 floors at maximum!\n");
            continue;
        }
        if(isalldigit(building->amount_of_floors, strlen(building->amount_of_floors)) == 0)
        {
            printf("Please enter a valid number for floors!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the main land: ");
        gets(building->size_of_the_main_land);
        if(strlen(building->size_of_the_main_land)> 8)
        {
            fflush(stdin);
            printf("Your building can have 99999999 m^2 at maximum!\n");
            continue;
        }
        if(isalldigit(building->size_of_the_main_land, strlen(building->size_of_the_main_land)) == 0)
        {
            printf("Please enter a valid number for size of main land!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter phone number of owner: ");
        gets(building->phone_number_of_owner);
        if(strlen(building->phone_number_of_owner) != 11)
        {
            fflush(stdin);
            printf("Your phone number must have 11 digits!\n");
            continue;
        }
        if(building->phone_number_of_owner[0] != '0')
        {
            printf("Your phone number must starts with 0 digit!\n");
            continue;
        }
        if(isalldigit(building->phone_number_of_owner, strlen(building->phone_number_of_owner)) == 0)
        {
            printf("Please enter a valid phone number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter amount of rooms: ");
        gets(building->amount_of_rooms);
        if(strlen(building->amount_of_rooms) > 4)
        {
            fflush(stdin);
            printf("Your building can have 9999 rooms at maximum!\n");
            continue;
        }
        if(isalldigit(building->amount_of_rooms, strlen(building->amount_of_rooms)) == 0)
        {
            printf("Please enter a valid number for amount of rooms!\n");
            continue;
        }
        break;

    }
    while(1)
    {
        printf("Please enter prepayment: ");
        gets(building->prepayment);
        if(strlen(building->prepayment) > 13)
        {
            fflush(stdin);
            printf("Your building prepayment can be 9-999-999-999-999 at maximum!\n");
            continue;
        }
        if(isalldigit(building->prepayment, strlen(building->prepayment)) == 0)
        {
            printf("Please enter a valid price for prepayment!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter pay per month(for mortgage only enter 0): ");
        gets(building->rent_per_month);
        if(strlen(building->rent_per_month) > 13)
        {
            fflush(stdin);
            printf("Your building prepayment can be 9-999-999-999-999 at maximum!\n");
            continue;
        }
        if(isalldigit(building->rent_per_month, strlen(building->rent_per_month)) == 0)
        {
            printf("Please enter a valid price for prepayment!\n");
            continue;
        }
        break;
    }
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
        return;
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_rent_res);
        return;
    }
}
void adding_rent_buildings_commercial()
{
    PlaySound("Audios\\adding_comm_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
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
    while(1)
    {
        printf("Please enter the municipality's area: ");
        gets(building->municipalitys_area);
        if(strlen(building->municipalitys_area) > 4)
        {
            printf("You can have 9999 municipality areas at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isalldigit(building->municipalitys_area, strlen(building->municipalitys_area)) == 0)
        {
            printf("Please enter a valid number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter the address of building: ");
        gets(building->address_of_building);
        if(strlen(building->address_of_building) > 98)
        {
            printf("Your address can have 98 characters at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isaddress(building->address_of_building, strlen(building->address_of_building)) == 0)
        {
            printf("Please enter a valid address!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter model of building: ");
        gets(building->model);
        if(strlen(building->model) > 18)
        {
            printf("Your model type can have 18 characters at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isallalpha(building->model, strlen(building->model)) == 0)
        {
            printf("Please enter a valid model!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter age of building: ");
        gets(building->age_of_building);
        if(strlen(building->age_of_building) > 4)
        {
            printf("Your building can be 9999 years old at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isalldigit(building->age_of_building, strlen(building->age_of_building)) == 0)
        {
            printf("Please enter a valid age!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the infrastructure: ");
        gets(building->size_of_the_infrastructure);
        if(strlen(building->size_of_the_infrastructure) > 8)
        {
            printf("your building can be 99999999 m^2 at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isalldigit(building->size_of_the_infrastructure, strlen(building->size_of_the_infrastructure)) == 0)
        {
            printf("Please enter a valid size!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter amount of floors: ");
        gets(building->amount_of_floors);
        if(strlen(building->amount_of_floors)> 4)
        {
            printf("Your building can have 9999 floors at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isalldigit(building->amount_of_floors, strlen(building->amount_of_floors)) == 0)
        {
            printf("Please enter a valid number for floors!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the main land: ");
        gets(building->size_of_the_main_land);
        if(strlen(building->size_of_the_main_land)> 8)
        {
            printf("Your building can have 99999999 m^2 at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isalldigit(building->size_of_the_main_land, strlen(building->size_of_the_main_land)) == 0)
        {
            printf("Please enter a valid number for size of main land!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter phone number of owner: ");
        gets(building->phone_number_of_owner);
        if(strlen(building->phone_number_of_owner) != 11)
        {
            printf("Your phone number must have 11 digits!\n");
            fflush(stdin);
            continue;
        }
        if(building->phone_number_of_owner[0] != '0')
        {
            printf("Your phone number must starts with 0 digit!\n");
            continue;
        }
        if(isalldigit(building->phone_number_of_owner, strlen(building->phone_number_of_owner)) == 0)
        {
            printf("Please enter a valid phone number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter amount of rooms: ");
        gets(building->amount_of_rooms);
        if(strlen(building->amount_of_rooms) > 4)
        {
            printf("Your building can have 9999 rooms at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isalldigit(building->amount_of_rooms, strlen(building->amount_of_rooms)) == 0)
        {
            printf("Please enter a valid number for amount of rooms!\n");
            continue;
        }
        break;

    }
    while(1)
    {
        printf("Please enter prepayment: ");
        gets(building->prepayment);
        if(strlen(building->prepayment) > 13)
        {
            printf("Your building prepayment can be 9-999-999-999-999 at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isalldigit(building->prepayment, strlen(building->prepayment)) == 0)
        {
            printf("Please enter a valid price for prepayment!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter pay per month(for mortgage only enter 0): ");
        gets(building->rent_per_month);
        if(strlen(building->rent_per_month) > 13)
        {
            printf("Your building prepayment can be 9-999-999-999-999 at maximum!\n");
            fflush(stdin);
            continue;
        }
        if(isalldigit(building->rent_per_month, strlen(building->rent_per_month)) == 0)
        {
            printf("Please enter a valid price for prepayment!\n");
            continue;
        }
        break;
    }
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
        PlaySound("Audios\\Sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_rent_res);
        return;
    }
}
void adding_rent_buildings_filed()
{
    PlaySound("Audios\\adding_filed_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
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
    while(1)
    {
        printf("Please enter the municipality's area: ");
        gets(building->municipalitys_area);
        if(strlen(building->municipalitys_area) > 4)
        {
            fflush(stdin);
            printf("You can have 9999 municipality areas at maximum!\n");
            continue;
        }
        if(isalldigit(building->municipalitys_area, strlen(building->municipalitys_area)) == 0)
        {
            printf("Please enter a valid number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter the address of building: ");
        gets(building->address_of_building);
        if(strlen(building->address_of_building) > 98)
        {
            fflush(stdin);
            printf("Your address can have 98 characters at maximum!\n");
            continue;
        }
        if(isaddress(building->address_of_building, strlen(building->address_of_building)) == 0)
        {
            printf("Please enter a valid address!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter model of building: ");
        gets(building->model);
        if(strlen(building->model) > 18)
        {
            fflush(stdin);
            printf("Your model type can have 18 characters at maximum!\n");
            continue;
        }
        if(isallalpha(building->model, strlen(building->model)) == 0)
        {
            printf("Please enter a valid model!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter The size of the infrastructure: ");
        gets(building->size_of_the_infrastructure);
        if(strlen(building->size_of_the_infrastructure) > 8)
        {
            fflush(stdin);
            printf("your building can be 99999999 m^2 at maximum!\n");
            continue;
        }
        if(isalldigit(building->size_of_the_infrastructure, strlen(building->size_of_the_infrastructure)) == 0)
        {
            printf("Please enter a valid size!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter phone number of owner: ");
        gets(building->phone_number_of_owner);
        if(strlen(building->phone_number_of_owner) != 11)
        {
            fflush(stdin);
            printf("Your phone number must have 11 digits!\n");
            continue;
        }
        if(building->phone_number_of_owner[0] != '0')
        {
            printf("Your phone number must starts with 0 digit!\n");
            continue;
        }
        if(isalldigit(building->phone_number_of_owner, strlen(building->phone_number_of_owner)) == 0)
        {
            printf("Please enter a valid phone number!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter prepayment: ");
        gets(building->prepayment);
        if(strlen(building->prepayment) > 13)
        {
            fflush(stdin);
            printf("Your building prepayment can be 9-999-999-999-999 at maximum!\n");
            continue;
        }
        if(isalldigit(building->prepayment, strlen(building->prepayment)) == 0)
        {
            printf("Please enter a valid price for prepayment!\n");
            continue;
        }
        break;
    }
    while(1)
    {
        printf("Please enter pay per month(for mortgage only enter 0): ");
        gets(building->rent_per_month);
        if(strlen(building->rent_per_month) > 13)
        {
            fflush(stdin);
            printf("Your building prepayment can be 9-999-999-999-999 at maximum!\n");
            continue;
        }
        if(isalldigit(building->rent_per_month, strlen(building->rent_per_month)) == 0)
        {
            printf("Please enter a valid price for prepayment!\n");
            continue;
        }
        break;
    }
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
        PlaySound("Audios\\Sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        free(building);
        fclose(file_ID);
        fclose(file_rent_res);
        return;
    }
}
void page_admin_report()
{
    PlaySound("Audios\\Reports.wav",NULL,SND_ASYNC | SND_FILENAME);
    int option;
    while(1)
    {
        system("cls");
        printf("Reports\n");
        option = 0;
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
            PlaySound("Audios\\Report_main_model.wav",NULL,SND_ASYNC | SND_FILENAME);

            report_model_main();
            break;
        }
        case 2:
        {
            PlaySound("Audios\\Report_MA.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *chose[12];
            while(1)
            {
                printf("Please enter a municipality area: ");
                gets(chose);
                if(strlen(chose) > 4)
                {
                    printf("maximum municipality area is 9999!\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                    fflush(stdin);

                }
                if(isalldigit(chose, strlen(chose)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                }
            }

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
            PlaySound("Audios\\Report_age.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *age_start[6], *age_finish[6];
            while(1)
            {
                printf("Please enter the start of age range(if you wish to only look for a specific age enter 0 for this filed): ");
                gets(age_start);
                if(strlen(age_start) > 4)
                {
                    printf("maximum age is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(age_start, strlen(age_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of age range: ");
                gets(age_finish);
                if(strlen(age_finish) > 4)
                {
                    printf("maximum age is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(age_finish, strlen(age_finish)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }

            system("cls");
            report_sale_residential_age(age_start, age_finish);
            report_sale_commercial_age(age_start, age_finish);
            report_rent_residential_age(age_start, age_finish);
            report_rent_commercial_age(age_start, age_finish);
            break;
        }
        case 4:
        {
            PlaySound("Audios\\Report_Size.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *size_start[6], *size_finish[6];
            while(1)
            {
                printf("Please enter the start of size range(if you wish to only look for a specific size enter 0 for this filed): ");
                gets(size_start);
                if(strlen(size_start) > 8)
                {
                    printf("maximum size is 99999999 m^2!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(size_start, strlen(size_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of size range: ");
                gets(size_finish);
                if(strlen(size_finish) > 8)
                {
                    printf("maximum size is 99999999 m^2!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(size_finish, strlen(size_finish)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            system("cls");
            report_sale_residential_size(size_start, size_finish);
            report_sale_commercial_size(size_start, size_finish);
            report_rent_filed_size(size_start, size_finish);
            report_rent_residential_size(size_start, size_finish);
            report_rent_commercial_size(size_start, size_finish);
            report_sale_filed_size(size_start, size_finish);
            break;
        }
        case 5:
        {
            PlaySound("Audios\\Report_price.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *price_start[20], *price_finish[20];
            while(1)
            {
                printf("Please enter the start of price range(if you wish to only look for a specific price enter 0 for this filed): ");
                gets(price_start);
                if(strlen(price_start) > 13)
                {
                    printf("maximum price is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(price_start, strlen(price_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of price range: ");
                gets(price_finish);
                if(strlen(price_finish) > 13)
                {
                    printf("maximum price is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(price_finish, strlen(price_finish)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            system("cls");
            report_sale_residential_price(price_start, price_finish);
            report_sale_commercial_price(price_start, price_finish);
            report_sale_filed_price(price_start, price_finish);
            break;
        }
        case 6:
        {
            PlaySound("Audios\\Report_room.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *room_start[6], *room_finish[6];
            while(1)
            {
                printf("Please enter the start of room range(if you wish to only look for a specific room enter 0 for this filed): ");
                gets(room_start);
                if(strlen(room_start) > 4)
                {
                    printf("maximum room is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(room_start, strlen(room_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of room range: ");
                gets(room_finish);
                if(strlen(room_finish) > 4)
                {
                    printf("maximum room is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(room_finish, strlen(room_finish)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            system("cls");
            report_rent_residential_room(room_start, room_finish);
            report_rent_commercial_room(room_start, room_finish);
            report_sale_residential_room(room_start, room_finish);
            report_sale_commercial_room(room_start, room_finish);
            break;
        }
        case 7:
        {
            PlaySound("Audios\\Report_price_total.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            if(report_price_total() == 0)
            {
                PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
                Sleep(3000);
                printf("There is no price to show!\n");
                printf("For getting back to report menu , press any key....");
                getchar();
                break;
            }
            else
            {

                printf("The total worth of salable buildings and fileds are equal to: %lld\n", report_price_total());
                printf("For getting back to report menu , press any key....");
                getchar();
                break;
            }
        }
        case 8:
        {
            PlaySound("Audios\\Report_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *prepayment_start[20], *prepayment_end[20], *rent_start[20], *rent_end[20];
            while(1)
            {
                printf("Please enter the start of prepayment range(if you wish to only look for a specific prepayment enter 0 for this filed): ");
                gets(prepayment_start);
                if(strlen(prepayment_start) > 13)
                {
                    printf("maximum prepayment is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(prepayment_start, strlen(prepayment_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of prepayment range: ");
                gets(prepayment_end);
                if(strlen(prepayment_end) > 13)
                {
                    printf("maximum prepayment is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(prepayment_end, strlen(prepayment_end)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the start of rent range(if you wish to only look for a specific rent enter 0 for this filed): ");
                gets(rent_start);
                if(strlen(rent_start) > 13)
                {
                    printf("maximum rent is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(rent_start, strlen(rent_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of rent range: ");
                gets(rent_end);
                if(strlen(rent_end) > 13)
                {
                    printf("maximum rent is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(rent_end, strlen(rent_end)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            system("cls");
            report_rent_residential_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
            report_rent_commercial_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
            report_rent_filed_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
            break;
        }
        case 9:
        {
            PlaySound("Audios\\Report_user_f.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            report_user_trunover();
            printf("\nFor getting back to the report menu , press any key.....");
            getchar();
            break;
        }
        case 10:
        {
            PlaySound("Audios\\Report_restigered.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            report_date_main_registered_buildings();
            break;
        }
        case 11:
        {
            PlaySound("Audios\\Report_floor.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *chose[12];
            while(1)
            {
                printf("Please enter a floor amount: ");
                gets(chose);
                if(strlen(chose) > 4)
                {
                    printf("maximum floor  is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(chose, strlen(chose)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
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
            PlaySound("Audios\\Report_delete.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            report_date_main_deleted_buildings();
            break;
        }
        case 13:
        {
            PlaySound("Audios\\Report_user_a.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            report_time_user();
            printf("Press any key to get back to the menu");
            getchar();
            break;
        }
        case 14:
        {
            system("cls");
            return;
        }
        default:
        {
            system("cls");
            printf("Please enter a valid option!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            break;
        }
        }
    }
}
void report_date_main_deleted_buildings()
{
    int option;
    while(1)
    {
        option = 0;
        system("cls");
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
            report_date_main_deleted_building_month();
            break;
        }
        case 3:
        {
            inner_flag = 0;
            report_date_main_deleted_building_three_month();
            break;
        }
        case 4:
        {
            return;
            break;
        }
        default:
        {
            system("cls");
            printf("Please enter a valid option!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            break;
        }
        }
    }
}
void report_date_main_deleted_building_month()
{
    PlaySound("Audios\\Report_delete_month.wav",NULL,SND_ASYNC | SND_FILENAME);
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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        return;
    }
}
void report_date_main_deleted_building_three_month()
{
    PlaySound("Audios\\Report_delete_3_month.wav",NULL,SND_ASYNC | SND_FILENAME);

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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        return;
    }
}
void report_date_main_deleted_building_week()
{
    PlaySound("Audios\\Report_delete_week.wav",NULL,SND_ASYNC | SND_FILENAME);
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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        return;
    }
}
void report_date_main_registered_buildings()
{
    int option;

    while(1)
    {
        system("cls");
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
            report_date_main_registered_building_three_month();
            break;
        }
        case 4:
        {
            return;
            break;
        }
        default:
        {
            system("cls");
            printf("Please enter a valid option!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            break;

        }
        }
    }
}
void report_date_main_registered_building_month()
{
    PlaySound("Audios\\Report_add_month.wav",NULL,SND_ASYNC | SND_FILENAME);
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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        return;
    }
}
void report_date_main_registered_building_three_month()
{
    PlaySound("Audios\\Report_add_3_month.wav",NULL,SND_ASYNC | SND_FILENAME);

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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        return;
    }
}
void report_date_main_registered_building_week()
{
    PlaySound("Audios\\Report_add_week.wav",NULL,SND_ASYNC | SND_FILENAME);

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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
        return;
    }
    else
    {
        printf("For getting back press any key.....");
        getchar();
        return;
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
    if(rent_start == 0)
    {
        rent_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
    if(rent_start == 0)
    {
        rent_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
    if(rent_start == 0)
    {
        rent_start = age_end;
    }
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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
    }
    printf("For getting back press any key.....");
    getchar();
    return;

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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
    }
    printf("For getting back press any key.....");
    getchar();
    return;
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);

    }
    printf("For getting back press any key.....");
    getchar();
    return;
}
void report_rent_residential_age(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);

    }
    printf("For getting back press any key.....");
    getchar();
    return;

}
void report_rent_residential_size(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
    }
    printf("For getting back press any key.....");
    getchar();
    return;

}
void report_sale_residential_age(char start_age[6], char end_age[6])
{
    int age_start, age_end,  age_file;
    age_start = atoi(start_age);
    age_end = atoi(end_age);
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
    if(age_start == 0)
    {
        age_start = age_end;
    }
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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
    }
    fclose(fp);
    make_null_list_building_sale();
    printf("For getting back press any key.....");
    getchar();
    return;

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
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(3000);
    }
    printf("For getting back press any key.....");
    getchar();
    return;

}
void report_model_main()
{

    int option;
    while(1)
    {
        system("cls");
        option = 0;
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
            return;
            break;
        }
        default:
        {
            printf("Please enter a valid option!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            system("cls");
            break;
        }
        }
    }
}
void report_model_building_model_sale()
{
    PlaySound("Audios\\Report_model_for_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
    int option;
    while(1)
    {
        option =0;
        system("cls");
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
            return;
            break;
        }
        default:
        {
            printf("Please enter a valid option!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            system("cls");
        }
        }
    }
}
void report_model_building_model_rent()
{
    PlaySound("Audios\\Report_model_for_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
    int option;
    while(1)
    {
        system("cls");
        option = 0;
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
            return;
            break;
        }
        default:
        {
            printf("Please enter a valid option!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            system("cls");
        }
        }
    }
}
void report_rent_residential()
{
    PlaySound("Audios\\Report_residental_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
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
            return;
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

        }
    }
}
void report_rent_commercial()
{
    PlaySound("Audios\\Report_comm_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
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

            return;
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

        }
    }
}
void report_rent_filed()
{
    PlaySound("Audios\\Report_filed_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
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

            return;
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

        }
    }
}
void report_sale_residential()
{
    PlaySound("Audios\\Report_residental_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
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
            return;
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

        }
    }
}
void report_sale_commercial()
{
    PlaySound("Audios\\Report_comm_sale.wav",NULL,SND_ASYNC | SND_FILENAME);

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
            return;
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

        }
    }
}
void report_sale_filed()
{
    PlaySound("Audios\\Report_filed_sale.wav",NULL,SND_ASYNC | SND_FILENAME);

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
        return;
    }
    while(1)
    {
        printf("\nPlease enter B for getting back to report menu: ");
        checker = getche();
        if(checker == 'b' || checker == 'B')
        {
            return;
            break;
        }
        else
        {
            printf("\nPlease enter a valid character!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
        }
    }
}
void page_reports_normal()
{
    PlaySound("Audios\\Reports.wav",NULL,SND_ASYNC | SND_FILENAME);
    int option;
    while(1)
    {
        system("cls");
        printf("Reports\n");
        option = 0;
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
        printf("11. Back\n");
        printf("Please choice your report: ");
        scanf("%d", &option);
        getchar();
        switch(option)
        {
        case 1:
        {
            system("cls");
            PlaySound("Audios\\Report_main_model.wav",NULL,SND_ASYNC | SND_FILENAME);

            report_model_main();
            break;
        }
        case 2:
        {
            PlaySound("Audios\\Report_MA.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *chose[12];
            while(1)
            {
                printf("Please enter a municipality area: ");
                gets(chose);
                if(strlen(chose) > 4)
                {
                    printf("maximum municipality area is 9999!\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                    fflush(stdin);

                }
                if(isalldigit(chose, strlen(chose)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                }
            }

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
            PlaySound("Audios\\Report_age.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *age_start[6], *age_finish[6];
            while(1)
            {
                printf("Please enter the start of age range(if you wish to only look for a specific age enter 0 for this filed): ");
                gets(age_start);
                if(strlen(age_start) > 4)
                {
                    printf("maximum age is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(age_start, strlen(age_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of age range: ");
                gets(age_finish);
                if(strlen(age_finish) > 4)
                {
                    printf("maximum age is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(age_finish, strlen(age_finish)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }

            system("cls");
            report_sale_residential_age(age_start, age_finish);
            report_sale_commercial_age(age_start, age_finish);
            report_rent_residential_age(age_start, age_finish);
            report_rent_commercial_age(age_start, age_finish);
            break;
        }
        case 4:
        {
            PlaySound("Audios\\Report_Size.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *size_start[6], *size_finish[6];
            while(1)
            {
                printf("Please enter the start of size range(if you wish to only look for a specific size enter 0 for this filed): ");
                gets(size_start);
                if(strlen(size_start) > 8)
                {
                    printf("maximum size is 99999999 m^2!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(size_start, strlen(size_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of size range: ");
                gets(size_finish);
                if(strlen(size_finish) > 8)
                {
                    printf("maximum size is 99999999 m^2!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(size_finish, strlen(size_finish)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            system("cls");
            report_sale_residential_size(size_start, size_finish);
            report_sale_commercial_size(size_start, size_finish);
            report_rent_filed_size(size_start, size_finish);
            report_rent_residential_size(size_start, size_finish);
            report_rent_commercial_size(size_start, size_finish);
            report_sale_filed_size(size_start, size_finish);
            break;
        }
        case 5:
        {
            PlaySound("Audios\\Report_price.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *price_start[20], *price_finish[20];
            while(1)
            {
                printf("Please enter the start of price range(if you wish to only look for a specific price enter 0 for this filed): ");
                gets(price_start);
                if(strlen(price_start) > 13)
                {
                    printf("maximum price is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(price_start, strlen(price_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of price range: ");
                gets(price_finish);
                if(strlen(price_finish) > 13)
                {
                    printf("maximum price is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(price_finish, strlen(price_finish)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            system("cls");
            report_sale_residential_price(price_start, price_finish);
            report_sale_commercial_price(price_start, price_finish);
            report_sale_filed_price(price_start, price_finish);
            break;
        }
        case 6:
        {
            PlaySound("Audios\\Report_room.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *room_start[6], *room_finish[6];
            while(1)
            {
                printf("Please enter the start of room range(if you wish to only look for a specific room enter 0 for this filed): ");
                gets(room_start);
                if(strlen(room_start) > 4)
                {
                    printf("maximum room is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(room_start, strlen(room_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of room range: ");
                gets(room_finish);
                if(strlen(room_finish) > 4)
                {
                    printf("maximum room is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(room_finish, strlen(room_finish)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            system("cls");
            report_rent_residential_room(room_start, room_finish);
            report_rent_commercial_room(room_start, room_finish);
            report_sale_residential_room(room_start, room_finish);
            report_sale_commercial_room(room_start, room_finish);
            break;
        }
        case 7:
        {
            PlaySound("Audios\\Report_price_total.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            if(report_price_total() == 0)
            {
                PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
                Sleep(3000);
                printf("There is no price to show!\n");
                printf("For getting back to report menu , press any key....");
                getchar();
                break;
            }
            else
            {

                printf("The total worth of salable buildings and fileds are equal to: %lld\n", report_price_total());
                printf("For getting back to report menu , press any key....");
                getchar();
                break;
            }
        }
        case 8:
        {
            PlaySound("Audios\\Report_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *prepayment_start[20], *prepayment_end[20], *rent_start[20], *rent_end[20];
            while(1)
            {
                printf("Please enter the start of prepayment range(if you wish to only look for a specific prepayment enter 0 for this filed): ");
                gets(prepayment_start);
                if(strlen(prepayment_start) > 13)
                {
                    printf("maximum prepayment is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(prepayment_start, strlen(prepayment_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of prepayment range: ");
                gets(prepayment_end);
                if(strlen(prepayment_end) > 13)
                {
                    printf("maximum prepayment is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(prepayment_end, strlen(prepayment_end)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the start of rent range(if you wish to only look for a specific rent enter 0 for this filed): ");
                gets(rent_start);
                if(strlen(rent_start) > 13)
                {
                    printf("maximum rent is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(rent_start, strlen(rent_start)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            while(1)
            {
                printf("Please enter the end of rent range: ");
                gets(rent_end);
                if(strlen(rent_end) > 13)
                {
                    printf("maximum rent is 9-999-999-999-999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(rent_end, strlen(rent_end)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
            system("cls");
            report_rent_residential_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
            report_rent_commercial_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
            report_rent_filed_rent_mortgage(prepayment_start, prepayment_end, rent_start, rent_end);
            break;
        }
        case 9:
        {
            PlaySound("Audios\\Report_restigered.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            report_date_main_registered_buildings();
            break;
        }
        case 10:
        {
            PlaySound("Audios\\Report_floor.wav",NULL,SND_ASYNC | SND_FILENAME);
            system("cls");
            inner_flag = 0;
            char *chose[12];
            while(1)
            {
                printf("Please enter a floor amount: ");
                gets(chose);
                if(strlen(chose) > 4)
                {
                    printf("maximum floor  is 9999!\n");
                    fflush(stdin);
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
                if(isalldigit(chose, strlen(chose)) == 0)
                {
                    printf("Please enter a valid option\n");
                    PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

                }
            }
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
            system("cls");
            return;
        }
        default:
        {
            system("cls");
            printf("Please enter a valid option!");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            break;
        }
        }
    }
}
void menu_delete_building()
{
    PlaySound("Audios\\delete_main_menu.wav",NULL,SND_ASYNC | SND_FILENAME);
    int checker = 0;
    while(1)
    {
        checker = 0;
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
            return;
            break;
        }
        default:
        {
            system("cls");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            printf("Please enter a valid option");
            Sleep(3000);
            break;
        }
        }
    }

}
void delete_menu_sale_buildings()
{
    PlaySound("Audios\\delete_main_menu_for_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
    int checker = 0;
    while(1)
    {
        checker = 0;
        system("cls");
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
            return;
            break;
        }
        default:
        {
            system("cls");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            printf("Please enter a valid option");
            Sleep(3000);
            break;
        }
        }
    }
}
void delete_sale_buildings_Residential()
{
    PlaySound("Audios\\delete_residental_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
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
        while(1)
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
                PlaySound("Audios\\Sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("The building has deleted successfully");
                Sleep(3000);
                return;
            }
            else
            {
                fclose(fp);
                make_null_list_building_sale();
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("Please enter a valid ID\n");
                Sleep(3000);

            }
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_sale();
        system("cls");
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);

        printf("There is no building to delete!");
        Sleep(2000);
        return;
    }
}
void delete_sale_buildings_commercial()
{
    PlaySound("Audios\\delete_comm_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
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
        while(1)
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
                return;
            }
            else
            {
                fclose(fp);
                make_null_list_building_sale();
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("Please enter a valid ID");
                Sleep(3000);

            }
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_sale();
        system("cls");
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        printf("There is no building to delete!");
        Sleep(2500);
        return;
    }
}
void delete_sale_buildings_filed()
{
    PlaySound("Audios\\delete_filed_sale.wav",NULL,SND_ASYNC | SND_FILENAME);
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
        while(1)
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
                return;
            }
            else
            {
                fclose(fp);
                make_null_list_building_sale();
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("Please enter a valid ID");
                Sleep(3000);

            }
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_sale();
        system("cls");
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        printf("There is no building to delete!");
        Sleep(2500);
        return;
    }
}
void delete_menu_rent_buildings()
{
    PlaySound("Audios\\delete_main_menu_for_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
    int checker = 0;
    while(1)
    {
        checker = 0;
        system("cls");
        printf("Deleting buildings\\for rent\n");
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
            return;
            break;
        }
        default:
        {
            system("cls");
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            printf("Please enter a valid option");
            Sleep(3000);
            break;
        }
        }

    }

}
void delete_rent_buildings_Residential()
{
    PlaySound("Audios\\delete_residental_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
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
        while(1)
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
                return;
            }
            else
            {
                fclose(fp);
                make_null_list_building_rent();
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("Please enter a valid ID");
                Sleep(3000);
            }
        }
    }
    else
    {
        fclose(fp);
        make_null_list_building_rent();
        system("cls");
        printf("There is no building to delete!");
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(2500);
        return;
    }
}
void delete_rent_buildings_commercial()
{
    PlaySound("Audios\\delete_comm_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
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
        while(1)
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
                return;
            }
            else
            {
                fclose(fp);
                make_null_list_building_rent();
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("Please enter a valid ID");
                Sleep(3000);

            }
        }

    }
    else
    {
        fclose(fp);
        make_null_list_building_rent();
        system("cls");
        printf("There is no building to delete!");
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(2500);
        return;
    }
}
void delete_rent_buildings_filed()
{
    PlaySound("Audios\\delete_filed_rent.wav",NULL,SND_ASYNC | SND_FILENAME);
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
        while(1)
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
                return;
            }
            else
            {
                fclose(fp);
                make_null_list_building_rent();
                PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
                printf("Please enter a valid ID");
                Sleep(3000);

            }

        }
    }
    else
    {
        fclose(fp);
        make_null_list_building_rent();
        system("cls");
        printf("There is no building to delete!");
        PlaySound("Audios\\No_item.wav",NULL,SND_ASYNC | SND_FILENAME);
        Sleep(2500);
        return;
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
        strftime (time_str,80,"20%y/%m/%d %H:%M:%S",info);
        printf("last time of %s user login is:%s\n",temp->user_name,time_str);
        time = start_user->time_logout;
        info = localtime(&time);
        strftime (time_str,80,"20%y/%m/%d %H:%M:%S",info);
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
        fgets(temp->phone, 15, user_fp);
        fgets(temp->email, 35, user_fp);
        fgets(temp_time, 31, user_fp);
        temp->time_login = atol(temp_time);
        fgets(temp_time, 31, user_fp);
        temp->time_logout = atol(temp_time);
        fgets(temp->ID, 31, user_fp);
        fgets(temp->isactive, 3, user_fp);
        fgets(temp_time, 31, user_fp);
        temp->time_banish = atol(temp_time);
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
        if(strcmp(temp->user_name, user_name) == 0 && strcmp(temp->password, password) == 0 )
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
int isalldigit(char string[], int lenght)
{
    int flag = 0;
    for(int index = 0 ; index < lenght ; index++)
    {
        if(isdigit(string[index]) == 0)
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int password_checker(char password[],int size)
{
    int flag_Digit = 0, flag_Upper_alpha = 0,flag_Lower_alpha = 0, flag_Special_char = 0;
    if(size < 8)
    {
        return 4;
    }
    for(int index = 0 ; index < size ; index++)
    {
        if(isdigit(password[index]))
        {
            flag_Digit = 1;
            continue;
        }
        if(isalpha(password[index]) && islower(password[index]))
        {
            flag_Lower_alpha = 1;
            continue;
        }
        if(isalpha(password[index]) && isupper(password[index]))
        {
            flag_Upper_alpha = 1;
            continue;
        }
        if(isalnum(password[index]) == 0)
        {
            flag_Special_char = 1;
            continue;
        }
    }
    if(flag_Digit == 0)
    {
        return 0;
    }
    if(flag_Lower_alpha == 0)
    {
        return 1;
    }
    if(flag_Upper_alpha == 0)
    {
        return 2;
    }
    if(flag_Special_char == 0)
    {
        return 3;
    }
    return 5;

}
int isaddress(char string[], int lenght)
{
    int flag = 0;
    for(int index = 0 ; index < lenght ; index++)
    {
        if(isalnum(string[index]) == 0 && string[index] != '-')
        {
            flag = 1;
        }
        if(string[index] == '-' && (string[index + 1] == '\0' || string[index + 1] == '-'))
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isallalpha(char string[], int lenght)
{
    int flag = 0;
    for(int index = 0 ; index < lenght ; index++)
    {
        if(isalpha(string[index]) == 0)
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isemail(char email[], int lenght)
{
    int Index_of_atsign = 0;
    int isfalse = 0;
    int Index_of_Dot = 0;
    for(int index = 0 ; index  < lenght ; index++)
    {
        if(isalnum(email[index] == 0) && (email[index] != '@' || email[index] != '_' ||  email[index] != '.'))
        {
            isfalse = 1;
            isfalse = 1;
        }
    }
    for(int index = 0 ; lenght > index ; index++)
    {
        if(email[index] == '@' && email[index - 1] == '.')
        {
            isfalse = 1;
        }
        else if(email[index] == '@' )
        {
            Index_of_atsign = index;
        }
    }
    for(int index = 0 ; index < Index_of_atsign ; index++)
    {
        if(isalpha(email[index]) <= 0 && isdigit(email[index]) == 0)
        {
            if(email[index] != '.')
            {
                isfalse = 1;
                break;
            }
        }
    }
    for(int index = Index_of_atsign + 1 ; index < lenght ; index++)
    {
        if(email[index] == '.' && email[index + 1] == '.')
        {
            isfalse = 1;
            break;
        }
        else if(email[index] == '.' && email[index + 1] == '\0')
        {
            isfalse = 1;
            break;
        }
        else if(email[index] == '.')
        {
            Index_of_Dot = index;
        }
        else if(isalpha(email[index]) <= 0)
        {
            if(email[index] != '.' || isdigit(email[index]) == 1)
            {
                isfalse = 1;
                break;
            }
        }
    }
    if(Index_of_Dot == 0)
    {
        isfalse = 1;
    }

    if(email[Index_of_atsign + 1] == '\0')
    {
        isfalse = 1;
    }
    if(Index_of_atsign == 0)
    {
        isfalse = 1;
    }
    if(isfalse == 1)
    {
        return -1;
    }
    else
    {
        return 1;
    }

}
int PreStart_Checker()
{
    char checker;
    FILE *PreStart_f;
    PreStart_f = fopen("Files\\PreStart\\Settings.txt", "r+");
    fgetc(PreStart_f);
    if(feof(PreStart_f))
    {
        fclose(PreStart_f);
        return 0;
    }
    else
    {
        ungetc(checker, PreStart_f);
        fclose(PreStart_f);
        return 1;
    }
}
void Pre_Start()
{
    PlaySound("Audios\\Prestart.wav",NULL,SND_ASYNC | SND_FILENAME);
    char *name[52];
    FILE *fp;
    printf("Thank You for choosing our program!\n");
    printf("\33[2K\r");
    while(1)
    {

        printf("Please choose a new name for your application(50 characters at maximum): ");
        gets(name);
        if(strlen(name) > 50)
        {
            printf("Please enter a name less than 50 characters!\n");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);

        }
        else
        {
            break;
        }
    }
    fp = fopen("Files\\PreStart\\Settings.txt", "r+");
    fputs(name, fp);
    fclose(fp);
}
void menu_edit_application()
{
    PlaySound("Audios\\App_edit.wav",NULL,SND_ASYNC | SND_FILENAME);
    system("cls");
    int option = 0;
    while(1)
    {
        printf("1. Change application name\n");
        printf("2. Change application background color\n");
        printf("3. Change application text color\n");
        printf("4. back");
        printf("\nPlease chose an option: ");
        scanf("%d", &option);
        getchar();
        switch(option)
        {
        case 1:
        {
            Edit_application_name();
            break;
        }
        case 2:
        {
            Edit_application_background_color();
            break;
        }
        case 3:
        {
            Edit_application_text_color();
        }
        case 4:
        {
            return;
            break;
        }
        default:
        {
            printf("Please enter a valid option!");
            PlaySound("Audios\\Invalid_input.wav", NULL,SND_ASYNC | SND_FILENAME);
            Sleep(3000);
            system("cls");
            break;
        }
        }
    }
}
void Edit_application_background_color()
{
    char *name[52], *BG_color[20], *Text_color[20];
    int option = 0, flag = 0;
    PlaySound("Audios\\App_edit_BG.wav", NULL,SND_ASYNC | SND_FILENAME);
    FILE *fp;
    printf("for getting back , press b: ");
    if(islower(getche()) == 'b')
    {
        return;
    }
    fp = fopen("Files\\PreStart\\Settings.txt", "r+");
    fgets(name, 52, fp);
    fgets(BG_color, 20, fp);
    fgets(Text_color, 20, fp);
    fclose(fp);
    printf("\33[2K\r");
    while(flag == 0)
    {
        printf("1. black\n");
        printf("2. red\n");
        printf("3. Green\n");
        printf("4. Yellow\n");
        printf("5. Blue\n");
        printf("6. Magenta \n");
        printf("7. Cyan \n");
        printf("8. White\n");
        printf("Please choose a option for background color: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            {
                strcpy(BG_color, "\33[40m");
                flag = 1;
                break;

            }
        case 2:
        {
            strcpy(BG_color, "\33[41m");
            flag = 1;
            break;

        }
        case 3:
        {
            strcpy(BG_color, "\33[42m");
            flag = 1;
            break;

        }
        case 4:
        {
            strcpy(BG_color, "\33[43m");
            flag = 1;
            break;

        }
        case 5:
        {
            strcpy(BG_color, "\33[44m");
            flag = 1;
            break;

        }
        case 6:
        {
            strcpy(BG_color, "\33[45m");
            flag = 1;
            break;

        }
        case 7:
        {
            strcpy(BG_color, "\33[46m");
            flag = 1;
            break;

        }
        case 8:
        {
            strcpy(BG_color, "\33[47m");
            flag = 1;
            break;

        }
        case 9:
        {
            strcpy(BG_color, "\33[107m");
            flag = 1;
            break;

        }
        default:
        {
            printf("Please enter a valid option!\n");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(2500);
        }
        }

    }
    fp = fopen("Files\\PreStart\\Settings.txt", "w+");
    fputs(name, fp);
    fputs("\n", fp);
    fputs(BG_color, fp);
    fputs("\n", fp);
    fputs(Text_color, fp);
    fclose(fp);
    printf("the text color of program is changed successfully!");
    PlaySound("Audios\\Sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
    Sleep(2000);
}
void Edit_application_text_color()
{
    char *name[52], *BG_color[20], *Text_color[20];
    int option = 0, flag = 0;
    PlaySound("Audios\\App_edit_text.wav", NULL,SND_ASYNC | SND_FILENAME);
    FILE *fp;
    printf("for getting back , press b: ");
    if(islower(getche()) == 'b')
    {
        return;
    }
    fp = fopen("Files\\PreStart\\Settings.txt", "r+");
    fgets(name, 52, fp);
    fgets(BG_color, 20, fp);
    fgets(Text_color, 20, fp);
    fclose(fp);
    printf("\33[2K\r");
    while(flag == 0)
    {
        printf("1. black\n");
        printf("2. red\n");
        printf("3. Green\n");
        printf("4. Yellow\n");
        printf("5. Blue\n");
        printf("6. Magenta \n");
        printf("7. Cyan \n");
        printf("8. White\n");
        printf("Please choose a option for background color: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
        {
            strcpy(Text_color, "\33[30m");
            flag = 1;
            break;

        }
        case 2:
        {
            strcpy(Text_color, "\33[31m");
            flag = 1;
            break;

        }
        case 3:
        {
            strcpy(Text_color, "\33[32m");
            flag = 1;
            break;

        }
        case 4:
        {
            strcpy(Text_color, "\33[33m");
            flag = 1;
            break;

        }
        case 5:
        {
            strcpy(Text_color, "\33[34m");
            flag = 1;
            break;

        }
        case 6:
        {
            strcpy(Text_color, "\33[35m");
            flag = 1;
            break;

        }
        case 7:
        {
            strcpy(Text_color, "\33[36m");
            flag = 1;
            break;

        }
        case 8:
        {
            strcpy(Text_color, "\33[37m");
            flag = 1;
            break;

        }
        case 9:
        {
            strcpy(Text_color, "\33[97m");
            flag = 1;
            break;

        }
        default:
        {
            printf("Please enter a valid option!\n");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
            Sleep(2500);
        }
        }

    }
    fp = fopen("Files\\PreStart\\Settings.txt", "w+");
    fputs(name, fp);
    fputs("\n", fp);
    fputs(BG_color, fp);
    fputs("\n", fp);
    fputs(Text_color, fp);
    fclose(fp);
    printf("the background color of program is changed successfully!");
    PlaySound("Audios\\Sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
    Sleep(2000);
}
void Edit_application_name()
{
    PlaySound("Audios\\App_edit_name.wav", NULL,SND_ASYNC | SND_FILENAME);
    char *name[52];
    FILE *fp;
    printf("for getting back , press b: ");
    if(islower(getche()) == 'b')
    {
        return;
    }
    printf("\33[2K\r");
    while(1)
    {

        printf("Please choose a new name for your application(50 characters at maximum): ");
        gets(name);
        if(strlen(name) > 50)
        {
            printf("Please enter a name less than 50 characters!\n");
            fflush(stdin);
            PlaySound("Audios\\Invalid_input.wav",NULL,SND_ASYNC | SND_FILENAME);
        }
        else
        {
            break;
        }
    }
    fp = fopen("Files\\PreStart\\Settings.txt", "w+");
    fputs(name, fp);
    fclose(fp);
    printf("the name of program is changed successfully!");
    PlaySound("Audios\\Sucess.wav",NULL,SND_ASYNC | SND_FILENAME);
    Sleep(2000);
}
void main()
{
    make_ansiescape_work();

    if(PreStart_Checker() == 0)
    {
        Pre_Start();
        Start_Page();
    }
    else
    {
        Start_Page();
    }
}
