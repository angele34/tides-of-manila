#ifndef MENU_H
#define MENU_H

// Input values are passed on to the DisplayMenu function
void DisplayMenu(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[]);
void DisplayMainScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[]);
void Buy(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[]);
void Sell(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[]);
void DisplayNavigationScreen(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[]);

#endif
