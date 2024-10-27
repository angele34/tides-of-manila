#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>

#include "../header/location.h"
#include "../header/menu.h"

void Manila(int player_code, int initial_capital, int target_profit, int current_profit, int day, int cargo, char current_location[], char screen_type[]);
void Tondo(int player_code, int initial_capital, int target_profit, int current_profit, int day, int cargo, char current_location[], char screen_type[]); 
void Pandakan(int player_code, int initial_capital, int target_profit, int current_profit, int day, int cargo, char current_location[], char screen_type[]);
void Sapa(int player_code, int initial_capital, int target_profit, int current_profit, int day, int cargo, char current_location[], char screen_type[]);

void Manila(int player_code, int initial_capital, int target_profit, int current_profit, int day, int cargo, char current_location[], char screen_type[]) {
    strcpy(current_location, "Manila");

    day++;
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
    
    printf("Where would you like to go?\n");
    printf("%*s%s", 3, "", "[1] Tondo\n");
    printf("%*s%s", 3, "", "[2] Pandakan\n");
    printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
    printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

    while(1) {
         char key = getch();
        if (key == '1') {
            Tondo(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == '2') {
            Pandakan(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == '3') {
            Sapa(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == 'x' || key == 'X') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        }
    }
}

void Tondo(int player_code, int initial_capital, int target_profit, int current_profit, int day, int cargo, char current_location[], char screen_type[]) {
    strcpy(current_location, "Tondo");
    day++;
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
    
    printf("Where would you like to go?\n");
    printf("%*s%s", 3, "", "[1] Manila\n");
    printf("%*s%s", 3, "", "[2] Pandakan\n");
    printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
    printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

    while(1) {
         char key = getch();
        if (key == '1') {
            Manila(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == '2') {
            Pandakan(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == '3') {
            Sapa(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == 'x' || key == 'X') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        }
    }
}

void Pandakan(int player_code, int initial_capital, int target_profit, int current_profit, int day, int cargo, char current_location[], char screen_type[]) {
    strcpy(current_location, "Pandakan"); 
    day++;
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
    
    printf("Where would you like to go?\n");
    printf("%*s%s", 3, "", "[1] Tondo\n");
    printf("%*s%s", 3, "", "[2] Manila\n");
    printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
    printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

    while(1) {
         char key = getch();
        if (key == '1') {
            Tondo(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == '2') {
            Manila(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == '3') {
            Sapa(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == 'x' || key == 'X') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        }
    }
}

void Sapa(int player_code, int initial_capital, int target_profit, int current_profit, int day, int cargo, char current_location[], char screen_type[]) {
    strcpy(current_location, "Sapa   ");

    day++;
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
    
    printf("Where would you like to go?\n");
    printf("%*s%s", 3, "", "[1] Tondo\n");
    printf("%*s%s", 3, "", "[2] Pandakan\n");
    printf("%*s%s", 3, "", "[3] Manila\n\n\n");
    printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

    while(1) {
         char key = getch();
        if (key == '1') {
            Tondo(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == '2') {
            Pandakan(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == '3') {
            Manila(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        } else if (key == 'x' || key == 'X') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type);
        }
    }
}
