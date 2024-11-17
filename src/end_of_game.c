#include "../header/common.h"

// Import user-defined libraries
#include "../header/end_of_game.h"

void End_Of_Game(int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit) {
    int total_gold = *nInitial_capital + *nCurrent_profit;
    
    #ifdef _WIN32
        system("cls");
    #endif
    
    if (*nDay >= 30 && total_gold < nTarget_profit + *nInitial_capital) {
        printf("You Lose :( \n\n");
    } else if (total_gold >= nTarget_profit + *nInitial_capital) {
        printf("You Win!\n\n");
    }
    
    printf("Total Gold %d\n", total_gold);
    printf("Profit %d\n", *nCurrent_profit);
    printf("Number of turns %d\n\n\n", *nDay);
}
