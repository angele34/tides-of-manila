#include "../header/common.h"
#include "../header/check_turns.h"

/*
This function checks the turns/days accumulated throughout the game and decides whether the game should proceed
@param nInitial_capital is the amount of gold coins the player initially inputted and starts with
@param nTarget_profit is the amount of profit set by the player and one of the goals to reach to win the game
@param nDay increments once the player travels to another port
@param nCurrent_profit displays the current profit the player has gained through selling goods
@param bGame_state checks if the game has not yet ended
@return 1 if conditions are met, otherwise 0 to proceed with the game
*/

int Check_Turns(int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *bGame_state) {
    if (*nDay >= 30 || *nInitial_capital + *nCurrent_profit >= nTarget_profit + *nInitial_capital) {
        *bGame_state = false;
        return 1;
    }
    return 0;
}

