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
void DisplayMenu(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state);
// This function displays the Main Screen containing options for the player to choose
void DisplayMainScreen(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state);
// This function displays the details of the Cargo and Market Prices
void Display_Details(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state);
// This function displays the Buy Screen, containing options of what to buy
void BuyScreen(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state);
// This function displays the Sell Screen, containing options of what to sell
void SellScreen(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state);
// This function displays the Navigation Screen, containing port options for the user to travel to
void DisplayNavigationScreen(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state);

#endif
