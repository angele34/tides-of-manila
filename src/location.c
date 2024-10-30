#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

// Import user-defined libraries
#include "../header/location.h"
#include "../header/menu.h"
#include "../header/end_of_game.h"

int Check_Turns(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Manila(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Tondo(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state); 
void Pandakan(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Sapa(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);

int Check_Turns(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    int total_gold = initial_capital + current_profit;
    if (*day >= 30 || total_gold >= target_profit + initial_capital) {
        *game_state = false;
        return 1;
    }
    return 0;
}

void Manila(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    strcpy(current_location, "Manila");

    if (Check_Turns(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state)) {
        return;
    }

    (*day)++;

    #ifdef _WIN32
        system("cls");
    #endif
    
    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, "Navigation", game_state);

    printf("Where would you like to go?\n");
    printf("%*s%s", 3, "", "[1] Tondo\n");
    printf("%*s%s", 3, "", "[2] Pandakan\n");
    printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
    printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

    char key = getch();
    if (key == '1') {
        Tondo(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == '2') {
        Pandakan(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == '3') {
        Sapa(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == 'x' || key == 'X') {
        DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    }
}

void Tondo(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    strcpy(current_location, "Tondo");

    if (Check_Turns(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state)) {
        return; 
    }
    
    (*day)++; 
    
    #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, "Navigation", game_state);
    
    printf("Where would you like to go?\n");
    printf("%*s%s", 3, "", "[1] Manila\n");
    printf("%*s%s", 3, "", "[2] Pandakan\n");
    printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
    printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

    char key = getch();
    if (key == '1') {
        Manila(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == '2') {
        Pandakan(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == '3') {
        Sapa(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == 'x' || key == 'X') {
        DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    }
}

void Pandakan(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    strcpy(current_location, "Pandakan"); 

    if (Check_Turns(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state)) {
        return; 
    }

    (*day)++; 

    #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, "Navigation", game_state);
    
    printf("Where would you like to go?\n");
    printf("%*s%s", 3, "", "[1] Tondo\n");
    printf("%*s%s", 3, "", "[2] Manila\n");
    printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
    printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

    char key = getch();
    if (key == '1') {
        Tondo(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == '2') {
        Manila(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == '3') {
        Sapa(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == 'x' || key == 'X') {
        DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    }
}

void Sapa(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    strcpy(current_location, "Sapa   ");
    
    if (Check_Turns(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state)) {
        return; 
    }
    
    (*day)++;
    
    #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, "Navigation", game_state);

    printf("Where would you like to go?\n");
    printf("%*s%s", 3, "", "[1] Tondo\n");
    printf("%*s%s", 3, "", "[2] Pandakan\n");
    printf("%*s%s", 3, "", "[3] Manila\n\n\n");
    printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

    char key = getch();
    if (key == '1') {
        Tondo(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == '2') {
        Pandakan(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == '3') {
        Manila(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (key == 'x' || key == 'X') {
        DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    }
}
