#include "../header/common.h"

// Import user-defined libraries
#include "../header/end_of_game.h"
#include "../header/clear_screen.h"

/*
This function displays the End of Game based on conditions
*/

void End_Of_Game(int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, int nCash) {
    Clear();
    int total_gold = *nInitial_capital + *nCurrent_profit;
    
    if (*nDay >= 30 && total_gold < nTarget_profit + *nInitial_capital) {
        printf("You Lose :( \n\n");
    } else if (total_gold >= nTarget_profit + *nInitial_capital) {
        printf("You Win!\n\n");
    }
    
    printf("Total Gold %d\n", total_gold);
    printf("Profit %d\n", *nCurrent_profit);
    printf("Number of turns %d\n\n\n", *nDay);
}
