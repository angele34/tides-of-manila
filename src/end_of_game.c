#include <stdio.h>
#include "../header/end_of_game.h"

void End_Of_Game(int target_profit, int initial_capital, int current_profit, int day) {
    int total_gold = initial_capital + current_profit;
    if (day >= 30 && total_gold < target_profit + initial_capital) {
        printf("You Lose :( \n\n");
        printf("Total Gold %d\n", total_gold);
        printf("Profit %d\n", current_profit);
        printf("Number of turns %d\n", day);
    } else if (total_gold >= target_profit + initial_capital) {
        printf("You Win!\n\n");
        printf("Total Gold %d\n", total_gold);
        printf("Profit %d\n", current_profit);
        printf("Number of turns %d\n", day);
    }
}

