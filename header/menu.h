#ifndef MENU_H
#define MENU_H

// Input values are passed on to the DisplayMenu function
void DisplayMenu(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void DisplayMainScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void BuyScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void SellScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void DisplayNavigationScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);

#endif
