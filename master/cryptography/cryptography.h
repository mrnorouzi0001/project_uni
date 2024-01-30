#include<stdio.h>
#include<string.h>


int character_reverser(int character){
    int temp = 0 , digit_1 , digit_2 , digit_3;
    if(100 - character > 0){
        digit_1 = character / 10;
        digit_2 = character % 10;
        temp += (digit_2 * 10) + (digit_1);
        temp %= 128;
        if(32 >= temp){
            temp = character;
        }
    }
    else{
        digit_1 = character / 100;
        digit_3 = character % 10;
        digit_2 = ((character % 100) - digit_3) / 10;
        temp = (digit_3 * 100) + (digit_2 * 10) + (digit_1);
        temp %= 128;
        if(32 >= temp){
            temp = character;
        }

    }
    return temp;
}
void string_reverser(char string[] , int lenght){
    char character;
    int index = 0;
    for(int amount = lenght - 1 ; amount >= lenght / 2 ; amount--){
        character = string[amount];
        string[amount] = string[index];
        string[index] = character;
        index++;
    }
}
int max_finder(char string[] , int size){
    int temp , max;
    max = string[0];
    for(int index = 1 ; index < size ; index++){
        if(string[index] > max){
            max = string[index];
        }
    }
    return max;
}
int min_finder(char string[] , int size){
    int temp , min;
    min = string[0];
    for(int index = 1 ; index < size ; index++){
        if(string[index] < min){
            min = string[index];
        }
    }
    return min;
}
void shifter_to_right(char string[] , int lenght){
    char last_character;
    last_character = string[strlen(string) - 1];
    for(int index = strlen(string) -2 ; index >= 0 ; index--){
        string[index + 1] = string[index];
    }
    string[0] = last_character;
}
void crypto(char string[] , int lenght){
    char character;
    int max , min;
    for(int index = 0 ; index < lenght ; index++){
        string[index] = character_reverser(string[index]);
    }
    max = max_finder(string , strlen(string));
    min = min_finder(string , strlen(string));
for(int index = 0 ; index < lenght ; index++){
        character = string[index];
        character += (max - min);
        character %= 128;
        if(character > 32){
            string[index] = character;
        }
    }
    string_reverser(string , strlen(string));
    for(int amount = lenght / 2 ; amount >= 0 ; amount--){
        shifter_to_right(string , strlen(string));
    }
}

