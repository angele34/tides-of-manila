#include <stdio.h>
#include "../header/welcome.h"

// Displays the main menu

void DisplayMenu(int player_code, int initial_capital, int target_profit) {
    printf("Main Screen\n\n\n");

    printf("Player %d \t\t\t\t Gold Coins: %d\n", player_code, initial_capital);
    printf("Location: Manila \t\t\t Profit: \n", target_profit);
    printf("Day %d\n\n\n\n", 0);

    printf("Where would you like to go?\n");
    printf("[1] Tondo\n");
    printf("[2] Pandakan\n");
    printf("[3] Sapa\n\n\n");

    printf("[X] Return to the Main Screen\n\n");
}