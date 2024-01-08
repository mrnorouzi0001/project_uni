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
void main_page(){
    printf("1. Adding new building\n");
    printf("2. Deleting the buildings\n");
    printf("3. Reports\n");
    printf("4. settings\n");
    printf("5. sign out\n");
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
void adding_page(){
    printf("1. For sale buildings\n");
    printf("2. For rent buildings\n");
    printf("3. back");
}
void sale_buildings(){
    printf("1. Residential buildings\n");
    printf("2. Commercial\n");
    printf("3. Normal filed\n");
    printf("4. back\n");
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
void Delete(){
    //report All
}
void user_Edit(){
    printf("Please enter your new name(if don't want to change leave it alone):");
    printf("Please enter your new last name(if don't want to change leave it alone):");
    printf("Please enter your new ID(if don't want to change leave it alone:");
    printf("Please enter your new Phone(if don't want to change leave it alone:");
    printf("Please enter your new Email(if don't want to change leave it alone:");
    printf("Please enter your new password(if don't want to change leave it alone):");
    printf("Please enter your new password again: ");
}
void main(){
    Start_Page();
}
