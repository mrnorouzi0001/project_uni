#include<stdio.h>
#include<windows.h>
void Start_Page();
void make_list_user(FILE *user_fp);
struct building_sale{
    char municipalitys_area[3];
    char address_of_building[100];
    char model[20];
    char age_of_building[5];
    char size_of_the_infrastructure[10];
    char amount_of_floors[4];
    char size_of_the_main_land[10];
    char phone_number_of_owner[12];
    char amount_of_rooms[3];
    char price[13];
    char user[30];
    char id[7];
    char isactive[2];
    unsigned long int time;
    struct user *link;
}*start_user , *last_user;

struct user{
    char user_name[30];
    char password[20];
    char name[25];
    char last_name[45];
    char phone[12];
    char email[35];
    struct user *link;
}*start_building_sale , *last_building_sale;

typedef struct building_sale BUILDING_SALE;
typedef struct user USER;

USER *current_user;
void sign_up(){
    system("cls");
    FILE *user_fp;
    user_fp = fopen("Files\\users\\user.txt" , "a+");
    if(user_fp == NULL){
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
    if(getchar() == 'Y'){
        fputs(user->user_name , user_fp);
        fputs("\n" , user_fp);
        fputs(user->password , user_fp);
        fputs("\n", user_fp);
        fputs(user->name , user_fp);
        fputs("\n", user_fp);
        fputs(user->last_name , user_fp);
        fputs("\n", user_fp);
        fputs(user->phone , user_fp);
        fputs("\n", user_fp);
        fputs(user->email , user_fp);
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
    else{
        free(user);
        free(user_fp);
        system("cls");
        Start_Page();
    }
}
void sign_in(){
    system("cls");
    FILE *user_fp;
    user_fp = fopen("Files\\users\\user.txt" , "r");
    if(user_fp == NULL){
        printf("There is a problem with user file. the program will restart itself");
        free(user_fp);
        fclose(user_fp);
        exit(0);
    }
    char user_name[30] , password[25];
    printf("Please enter your user name: ");
    gets(user_name);
    strcat(user_name  , "\n");
    make_list_user(user_fp);
    int tries = 0;
    if(search_username_list_user(user_name) == 1){
        while(1){
            printf("Please enter your password: ");
            gets(password);
            strcat(password  , "\n");
            if(search_password_list_user(user_name ,password) == 1){
                break;
            }
            else{
                printf("wrong password! %d tries left!\n" , tries + 1);
                tries++;
            }
        }
        printf("logging in. please wait!");
        Sleep(2000);
        //make_null_list_user();
        system("cls");
        fclose(user_fp);
        main_page();
    }
    else{
        printf("we don't have this user name!");
        Sleep(2000);
        fclose(user_fp);
        //make_null_list_user();
        Start_Page();
    }
}
void main_page(){
    int option = 0;
    system("cls");
    printf("1. Adding new building\n");
    printf("2. Deleting the buildings\n");
    printf("3. Reports\n");
    printf("4. settings\n");
    printf("5. sign out\n");
    printf("Please choice your option: ");
    scanf("%d" , &option);
    getchar();
    switch(option){
        case 1:{
            adding_building();
            break;
        }
        case 2:{
            delete_building();
        }
        case 3:{
            if(strcmp(current_user->user_name , "admin") == 0){
                reports_admin();
                break;
            }
            else{
                reports_normal();
                break;
            }
        }
        case 4:{
            user_edit();
            break;
        }
        case 5:{
            free(current_user);
            printf("Logging out");
            Sleep(2000);
            Start_Page();
        }
        default:{
            printf("Please enter a valid option");
            Sleep(2000);
            system("cls");
            main_page();
        }
    }
}
void Start_Page(){
    system("cls");
    int checker = 0;
    printf("1. sign up\n");
    printf("2. sign in\n");
    printf("3. exit\n");
    scanf("%d" , &checker);
    getchar();
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
            Start_Page();
        }
    }
}
void adding_building(){
    int checker = 0;
    system("cls");
    printf("1. For sale buildings\n");
    printf("2. For rent buildings\n");
    printf("3. back\n");
    printf("Please choice your option: ");
    scanf("%d" , &checker);
    getchar();
    switch(checker){
        case 1 :{
            sale_buildings();
            break;
        }
        case 2 :{
            rent_buildings();
            break;
        }
        case 3 :{
            main_page();
            break;
        }
        default: {
            system("cls");
            printf("Please enter a valid option");
            Sleep(1000);
            adding_building();
        }
    }
}
void sale_buildings(){
    system("cls");
    int checker = 0;
    printf("1. Residential buildings\n");
    printf("2. Commercial\n");
    printf("3. Normal filed\n");
    printf("4. back\n");
    printf("Please choice your option: ");
    scanf("%d" , &checker);
    getchar();
    switch(checker){
        case 1 :{
            adding_sale_buildings_Residential();
            break;
        }
        case 2 :{
            adding_sale_buildings_commercial();
            break;
        }
        case 3 :{
            adding_sale_buildings_filed();
            break;
        }
        case 4:{
            adding_building();
            break;
        }
        default: {
            system("cls");
            printf("Please enter a valid option");
            Sleep(1000);
            sale_buildings();
        }
    }
}
void adding_sale_buildings_Residential(){
    int id = 0;
    char char_id[7] , temp[25];
    system("cls");
    FILE *file_sale_res , *file_ID;
    file_sale_res = fopen("Files\\building\\for_sale\\Residential.txt" , "a+");
    file_ID = fopen("Files\\building\\for_sale\\ID.txt" , "r+");
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
    strcpy(building->user , current_user->user_name);
    building->time = time(NULL);
    strcpy(building->isactive , "1");
    fgets(building->id , 7 , file_ID);
    id = atoi(building->id);
    id++;
    itoa(id ,char_id ,10);
    free(file_ID);
    file_ID = fopen("Files\\building\\for_sale\\ID.txt" , "w+");
    fputs(char_id , file_ID);
    printf("\nAre you sure you want to add this building to your sale list?(Y/N)");
    if(getchar() == 'Y'){
        system("cls");
        printf("processing");
        Sleep(2000);
        fputs(building->municipalitys_area , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->address_of_building , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->model , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->age_of_building , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->size_of_the_infrastructure , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->amount_of_floors , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->size_of_the_main_land , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->phone_number_of_owner , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->amount_of_rooms , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->price , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->user , file_sale_res);
        fputs("\n" , file_sale_res);
        itoa(building->time , temp , 10);
        fputs(temp , file_sale_res);
        fputs("\n" , file_sale_res);
        fputs(building->isactive , file_sale_res);
        fputs("\n" , file_sale_res);
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        system("cls");
        printf("building has added successfully");
        Sleep(2000);
        sale_buildings();
    }
    else{
        free(building);
        fclose(file_ID);
        fclose(file_sale_res);
        sale_buildings();
    }

}
void adding_sale_buildings_commercial(){
    printf("PLease enter the municipality's area: ");
    printf("Please enter the address of building: ");
    printf("PLease enter model of building: ");
    printf("PLease enter age of building: ");
    printf("Please enter The size of the infrastructure: ");
    printf("PLease enter amount of floors: ");
    printf("PLease enter The size of the main land: ");
    printf("Please enter phone number of owner: ");
    printf("PLease enter amount of rooms: ");
    printf("PLease enter price: ");
}
void adding_sale_buildings_filed(){
    printf("PLease enter the municipality's area: ");
    printf("Please enter the address of building: ");
    printf("PLease enter model of building(farm or in-city): ");
    printf("Please enter The size of the infrastructure: ");
    printf("Please enter phone number of owner: ");
    printf("PLease enter price: ");
}
void rent_buildings(){
    printf("1. Residential buildings\n");
    printf("2. Commercial\n");
    printf("3. Normal filed\n");
    printf("4. back\n");
}
void adding_rent_buildings_Residential(){
    printf("PLease enter the municipality's area: ");
    printf("Please enter the address of building: ");
    printf("PLease enter model of building(apartment or Villa): ");
    printf("PLease enter age of building: ");
    printf("Please enter The size of the infrastructure: ");
    printf("PLease enter amount of floors: ");
    printf("PLease enter The size of the main land: ");
    printf("Please enter phone number of owner: ");
    printf("PLease enter amount of rooms: ");
    printf("PLease enter price of prepayment: ");
    printf("PLease enter price of rent(per month(for only mortgage enter 0)): ");
}
void adding_rent_buildings_commercial(){
    printf("PLease enter the municipality's area: ");
    printf("Please enter the address of building: ");
    printf("PLease enter model of building: ");
    printf("PLease enter age of building: ");
    printf("Please enter The size of the infrastructure: ");
    printf("PLease enter amount of floors: ");
    printf("PLease enter The size of the main land: ");
    printf("Please enter phone number of owner: ");
    printf("PLease enter amount of rooms: ");
    printf("PLease enter price of prepayment: ");
    printf("PLease enter price of rent(per month(for only mortgage enter 0)): ");
}
void adding_rent_buildings_filed(){
    printf("PLease enter the municipality's area: ");
    printf("Please enter the address of building: ");
    printf("PLease enter model of building(farm or in-city): ");
    printf("Please enter The size of the infrastructure: ");
    printf("Please enter phone number of owner: ");
    printf("PLease enter price of prepayment: ");
    printf("PLease enter price of rent(per month(for only mortgage enter 0)): ");
}
void reports_admin(){
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
}
void report_model_main(){
    printf("1. Sale\n");
    printf("2. rent\n");
    printf("3. back\n");
}
void report_model_building_model(int mode){
    printf("1. Residential buildings\n");
    printf("2. Commercia\nl");
    printf("3. Normal filed\n");
    printf("4. back\n");
}
void report_sale(int mode_main , int mode_building/*struc Building*/){
    printf("ID: \n");
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
void report_rent(int mode_main , int mode_building/*struc Building*/){
    printf("ID: \n");
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
void reports_normal(){
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
void report_All(/*struc Building*/){
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
void report_time(/*struc Building*/){
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
void report_total_price(){
    printf("The total price of buildings in application is: ");
    printf("Press B for getting back to the report page.");
}
void report_user_financial(/*struc User*/){
    printf("User name: \n");
}
void report_date_main(){
    printf("1. past week");
    printf("2. past month");
    printf("3. past 3 month");
    printf("4. back");
}
void report_user_activity(/*struc User*/){
    printf("User name: \n");
    printf("Last login: \n");
    printf("Last logout: \n");
}
void delete_building(){
    //report All
}
void user_edit(){
    printf("Please enter your new name(if don't want to change leave it alone):");
    printf("Please enter your new last name(if don't want to change leave it alone):");
    printf("Please enter your new ID(if don't want to change leave it alone:");
    printf("Please enter your new Phone(if don't want to change leave it alone:");
    printf("Please enter your new Email(if don't want to change leave it alone:");
    printf("Please enter your new password(if don't want to change leave it alone):");
    printf("Please enter your new password again: ");
}
void make_list_user(FILE *user_fp){
    USER *temp;
    while(1){
        if(feof(user_fp)){
            break;
        }
        temp = malloc(sizeof(USER));
        fgets(temp->user_name , 30 , user_fp);
        fgets(temp->password , 20 , user_fp);
        fgets(temp->name , 25 , user_fp);
        fgets(temp->last_name , 45 , user_fp);
        fgets(temp->phone , 12 , user_fp);
        fgets(temp->email , 35 , user_fp);
        if(start_user == NULL)
        {
            start_user = temp;
            start_user->link = NULL;
            last_user = start_user;
        }else
        {
            last_user->link = temp;
            last_user = temp;
            last_user->link = NULL;
        }
    }
}
int search_username_list_user(char user_name[30]){
    USER *temp;
    temp = start_user;
    while(temp != NULL){
        if(strcmp(temp->user_name , user_name) == 0){
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}
int search_password_list_user(char user_name[30] , char password[20]){
    USER *temp;
    temp = start_user;
    while(temp != NULL){
        if(strcmp(temp->user_name , user_name) == 0 && strcmp(temp->password , password) == 0){
            current_user = temp;
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}
void main(){

    Start_Page();
}
