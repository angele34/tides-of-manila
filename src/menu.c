#include <stdio.h>
#include "../header/welcome.h"
#include <conio.h>
#include <stdlib.h> 

// Functions
void DisplayMenu(int player_code, int initial_capital, int target_profit);
void DisplayMainScreen(int player_code, int initial_capital, int target_profit);
void Buy(int player_code, int initial_capital, int target_profit);
void DisplayNavigationScreen(int player_code, int initial_capital, int target_profit);

// TODO: Optimize the key press code

// Displays the main menu containing player data and progress
void DisplayMenu(int player_code, int initial_capital, int target_profit) {
    printf("\n\nMain Screen\n\n\n");

    printf("Player %d \t\t\t\t Gold Coins: %d\n", player_code, initial_capital);
    printf("Location: Manila \t\t\t\t Profit: \n", target_profit);
    printf("Day %d\n\n\n\n", 0);
}

// Displays the main screen containing cargo and market prices
void DisplayMainScreen(int player_code, int initial_capital, int target_profit) {
    printf("   Cargo \t 0 of 75\n");
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
    printf("\t[1] Buy\n");
    printf("\t[2] Sell\n");
    printf("\t[3] Go to Another Port\n\n");

    printf("\t[Q] Quit\n\n\n");

    while (1) {
        char key = getch();
        if (key == '1') {
            #ifdef _WIN32 
                system("cls");
            #endif
            DisplayMenu(player_code, initial_capital, target_profit);
            Buy(player_code, initial_capital, target_profit);
        } else if (key == '2') {
            printf("Selling\n");
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
    printf("\t[1] Coconut\n");
    printf("\t[2] Rice\n");
    printf("\t[2] Silk\n");
    printf("\t[2] Gun\n\n\n");

    printf("\t[X] Return to the Main Screen\n\n\n");

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



// Displays the navigation screen upon pressing [3] Go to Another Port
void DisplayNavigationScreen(int player_code, int initial_capital, int target_profit) {
    printf("Where would you like to go?\n");
    printf("\t[1] Tondo\n");
    printf("\t[2] Pandakan\n");
    printf("\t[3] Sapa\n\n\n");

    printf("\t[X] Return to the Main Screen\n\n\n");

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
