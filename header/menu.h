#ifndef MENU_H
#define MENU_H

/*
@param player is a struct containing the user's numerical input values variables
@param progress is a struct containing the user's progress throughout the game
@param inventory is a struct containing the user's cargo of every item bought
@param prices is a struct containing the market prices of goods each time Set_Prices function is called
@param items is a struct containing variables quantity and item to keep track of what the user buys/sells
@param current_location is initially set to Manila, dynamically updates once the user navigates to a different port
@param screen_type is initially set to Main, dynamically updates once the user navigates to a different screen
@param game_state is initially set to true, used to keep track if the game has ended once it's set to false

@return <description of returned result>
*/

// This function displays the Menu containing Player stats
// This function displays the Buy Screen, containing options of what to buy
void DisplayMenu(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, int *nCargo, int *nCurrent_Loc, int *nScreen_type);
void BuyScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity);
 // This function displays the Sell Screen, containing options of what to sell
void SellScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity);
// // This function displays the Navigation Screen, containing port options for the user to travel to
void DisplayNavigationScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity);


#endif
