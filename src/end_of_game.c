#include <stdio.h>
#include <stdlib.h>

// Import user-defined libraries
#include "../header/end_of_game.h"

void End_Of_Game(int target_profit, int initial_capital, int current_profit, int day) {
    int total_gold = initial_capital + current_profit;
    if (day >= 30 || day >= 30 && total_gold < target_profit + initial_capital) {
        system("cls");
        printf("You Lose :( \n\n");
        printf("Total Gold %d\n", total_gold);
        printf("Profit %d\n", current_profit);
        printf("Number of turns %d\n\n\n", day);
        return;
    } else if (total_gold >= target_profit + initial_capital) {
        system("cls");
        printf("You Win!\n\n");
        printf("Total Gold %d\n", total_gold);
        printf("Profit %d\n", current_profit);
        printf("Number of turns %d\n\n\n", day);
        return;
    }
}

