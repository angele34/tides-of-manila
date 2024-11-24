#include "../header/common.h"

// Import user-defined libraries
#include "../header/end_of_game.h"
#include "../header/clear_screen.h"

/*
This function displays the End of Game and decides whether the player has won or lost
@param nInitial_capital is the amount of gold coins the player initially inputted and starts with
@param nTarget_profit is the amount of profit set by the player and one of the goals to reach to win the game
@param nDay increments once the player travels to another port
@param nCash is the value of the initial capital entered by the player used to calculate the profit 
@return None
*/

void End_Of_Game(int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, int nCash) {
    Clear();
    if (*nDay >= 30 && *nInitial_capital < nTarget_profit + *nInitial_capital) {
        printf("You Lose :( \n\n");
    } else if (*nInitial_capital + *nCurrent_profit >= nTarget_profit + *nInitial_capital) {
        printf("You Win!\n\n");
    }
    printf("Total Gold %d\n", *nInitial_capital);
    printf("Profit %d\n", *nCurrent_profit);
    printf("Number of turns %d\n\n\n", *nDay);
}
