#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

// Import user-defined libraries
#include "../header/generate_price.h" 
#include "../header/location.h"
#include "../header/menu.h"

void DisplayMenu(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void DisplayMainScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Buy(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Sell(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void DisplayNavigationScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);

// Displays the main menu containing player data and progress
void DisplayMenu(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    if (strcmp(screen_type, "Main") == 0) {
        printf("\n\nMain Screen\n\n\n");
    } else if (strcmp(screen_type, "Purchase") == 0) {
        printf("Purchase Screen\n\n\n");
    } else if (strcmp(screen_type, "Sell") == 0) {
        printf("Sell Screen\n\n\n");
    } else if (strcmp(screen_type, "Navigation") == 0) {
        printf("Navigation Screen\n\n\n");
    }

    printf("Player: %03d \t\t\t\t Gold Coins: %d\n", player_code, initial_capital);
    printf("Location: ");
    printf("\033[1;38;5;214m");
    printf("%s", current_location);
    printf("\033[0m");
    printf(" \t\t\t Profit: %5d/%d%%\n", current_profit, target_profit);

    printf("Day %d\n\n\n\n", *day);
}

// Displays the main screen containing cargo and market prices
void DisplayMainScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, "Main", game_state);
    
    printf("   Cargo \t%3d of 75\n", cargo);
    printf("   =======================\n");
    printf("   Coconut - 0   Silk - 0\n");
    printf("   Rice    - 0   Gun  - 0\n\n\n");

    // Placeholder values
    // TODO: Implement random price generator
    printf("   Market Prices\n");
    printf("   =======================\n");
    printf("   Coconut - 0   Silk - 0\n");
    printf("   Rice    - 0   Gun  - 0\n\n\n  ");

    printf("What would you like to do?\n");
    printf("%*s%s", 4, "", "[1] Buy\n");
    printf("%*s%s", 4, "", "[2] Sell\n");
    printf("%*s%s", 4, "", "[3] Go to Another Port\n\n");

    printf("%*s%s", 4, "", "[Q] Quit\n\n\n");
    
    while (*game_state) {
        char key = getch();
        if (key == '1') {
            Buy(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
        } else if (key == '2') {
            Sell(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
        } else if (key == '3') {
            DisplayNavigationScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
        } else if (key == 'q' || key == 'Q') {
            *game_state = false;
        }
    }
}

// Displays the buy screen upon pressing [1] Buy
void Buy(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, "Purchase", game_state);

    printf("What would you like to buy?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");

    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n\n\n");

    while(*game_state) {
        char key = getch();
        if (key == '1') {
            printf("Buying Coconut\n");
        } else if (key == '2') {
            printf("Buying Rice\n");
        } else if (key == '3') {
            printf("Buying Silk\n");
        } else if (key == '4') {
            printf("Buying Gun\n");
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
        }
    }
}

void Sell(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, "Sell", game_state);

    printf("What would you like to sell?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");

    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n\n\n");

    while(*game_state) {
        char key = getch();
        if (key == '1') {
            printf("Selling Coconut\n");
        } else if (key == '2') {
            printf("Selling Rice\n");
        } else if (key == '3') {
            printf("Selling Silk\n");
        } else if (key == '4') {
            printf("Selling Gun\n");
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
        }
    }
}

// Displays the navigation screen upon pressing [3] Go to Another Port
void DisplayNavigationScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
     #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, "Navigation", game_state);

    if (strcmp(current_location, "Manila") == 0) {
        Manila(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (strcmp(current_location, "Tondo") == 0) {
        Tondo(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (strcmp(current_location, "Pandakan") == 0) {
        Pandakan(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    } else if (strcmp(current_location, "Sapa   ") == 0) {
        Sapa(player_code, initial_capital, target_profit, current_profit, day, cargo, current_location, screen_type, game_state);
    }
}
