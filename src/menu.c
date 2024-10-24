#include <stdio.h>
#include "../header/welcome.h"
#include <conio.h>
#include <stdlib.h> 

// Functions
void DisplayMenu(int player_code, int initial_capital, int target_profit);
void DisplayMainScreen(int player_code, int initial_capital, int target_profit);
void Buy(int player_code, int initial_capital, int target_profit);
void Sell(int player_code, int initial_capital, int target_profit);
void DisplayNavigationScreen(int player_code, int initial_capital, int target_profit);

// TODO: Optimize the key press code

// Displays the main menu containing player data and progress
void DisplayMenu(int player_code, int initial_capital, int target_profit) {
    int current_profit = 0, day = 0;
    printf("\n\nMain Screen\n\n\n");

    printf("Player: %03d \t\t\t\t Gold Coins: %d\n", player_code, initial_capital);
    printf("Location: Manila \t\t\t Profit: %5d/%d%%\n", current_profit, target_profit);
    printf("Day %d\n\n\n\n", day);
}

// Displays the main screen containing cargo and market prices
void DisplayMainScreen(int player_code, int initial_capital, int target_profit) {
    int cargo = 0;
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

    while (1) {
        char key = getch();
        if (key == '1') {
            #ifdef _WIN32 
                system("cls");
            #endif
                DisplayMenu(player_code, initial_capital, target_profit);
                Buy(player_code, initial_capital, target_profit);
        } else if (key == '2') {
            #ifdef _WIN32 
                system("cls");
            #endif
                DisplayMenu(player_code, initial_capital, target_profit);
                Sell(player_code, initial_capital, target_profit);
        } else if (key == '3') {
            #ifdef _WIN32 
                system("cls");
            #endif
                DisplayMenu(player_code, initial_capital, target_profit);
                DisplayNavigationScreen(player_code, initial_capital, target_profit);
        } else if (key == 'q' || key == 'Q') {
            exit(0);
        }
    }
}

// Displays the buy screen upon pressing [1] Buy
void Buy(int player_code, int initial_capital, int target_profit) {
    printf("What would you like to buy?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");

    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n\n\n");

    while(1) {
        char key = getch();
        if (key == '1') {
            printf("Buying Coconut\n");
        } else if (key == '2') {
            printf("Buying Rice\n");
        } else if (key == '3') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMainScreen(player_code, initial_capital, target_profit);
        } else if (key == '4') {
            printf("Buying Gun\n");
        } else if (key == 'x' || key == 'X') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMenu(player_code, initial_capital, target_profit);
            DisplayMainScreen(player_code, initial_capital, target_profit);
        }
    }
}

void Sell(int player_code, int initial_capital, int target_profit) {
    printf("What would you like to sell?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");

    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n\n\n");

    while(1) {
        char key = getch();
        if (key == '1') {
            printf("Selling Coconut\n");
        } else if (key == '2') {
            printf("Selling Rice\n");
        } else if (key == '3') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMainScreen(player_code, initial_capital, target_profit);
        } else if (key == '4') {
            printf("Selling Gun\n");
        } else if (key == 'x' || key == 'X') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMenu(player_code, initial_capital, target_profit);
            DisplayMainScreen(player_code, initial_capital, target_profit);
        }
    }
}


// Displays the navigation screen upon pressing [3] Go to Another Port
void DisplayNavigationScreen(int player_code, int initial_capital, int target_profit) {
    printf("Where would you like to go?\n");
    printf("%*s%s", 2, "", "[1] Tondo\n");
    printf("%*s%s", 2, "", "[2] Pandakan\n");
    printf("%*s%s", 2, "", "[3] Sapa\n\n\n");

    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n\n\n");

    while(1) {
        char key = getch();
        if (key == '1') {
            printf("Tondo\n");
        } else if (key == '2') {
            printf("Pandakan\n");
        } else if (key == '3') {
            printf("Sapa\n");
        } else if (key == 'x' || key == 'X') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMenu(player_code, initial_capital, target_profit);
            DisplayMainScreen(player_code, initial_capital, target_profit);
        }
    }
}
