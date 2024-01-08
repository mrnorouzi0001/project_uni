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
    printf("3. back");
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
    printf("1. Residential buildings");
    printf("2. Commercial");
    printf("3. Normal filed");
    printf("4. back");
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
    printf("1. Specific model of buildings ");
    printf("2. Buildings with Specific area");
    printf("3. Buildings with Specific age");
    printf("4. Buildings with Specific infrastructure size");
    printf("5. Buildings with Specific prices");
    printf("6. Buildings with Specific Room's amount");
    printf("7. Total price of building");
    printf("8. Buildings with Specific rent and mortgage price");
    printf("9. Users Financial turnover");
    printf("10. Date of registered buildings");
    printf("11. Buildings with Specific floors");
    printf("12. Deleted buildings");
    printf("13. Users activity");

}
void report_model_main(){
    printf("1. Sale");
    printf("2. rent");
    printf("3. back");
}
void report_model_building_model(int mode){
    printf("1. Residential buildings");
    printf("2. Commercial");
    printf("3. Normal filed");
    printf("4. back");
}
void report_sale(int mode_main , int mode_building){
    printf("Municipality's area: ");
    printf("Address of building: ");
    printf("Model of building: ");
    printf("Age of building: ");
    printf("The size of the infrastructure: ");
    printf("Amount of floors: ");
    printf("The size of the main land: ");
    printf("Phone number of owner: ");
    printf("Amount of rooms: ");
    printf("Price: ");
}
void report_rent(int mode_main , int mode_building){
    printf("Municipality's area: ");
    printf("Address of building: ");
    printf("Model of building: ");
    printf("Age of building: ");
    printf("The size of the infrastructure: ");
    printf("Amount of floors: ");
    printf("The size of the main land: ");
    printf("Phone number of owner: ");
    printf("Amount of rooms: ");
    printf("prepayment Price: ")
    printf("Rent Price: ");
}
void reports_user(){
    printf("1. Specific model of buildings ");
    printf("2. Buildings with Specific area");
    printf("3. Buildings with Specific age");
    printf("4. Buildings with Specific infrastructure size");
    printf("5. Buildings with Specific prices");
    printf("6. Buildings with Specific Room's amount");
    printf("7. Total price of building");
    printf("8. Buildings with Specific rent and mortgage price");
    printf("9. Date of registered buildings");
    printf("10. Buildings with Specific floors");
}
void main(){
    Start_Page();
}
