#ifndef GENERATE_PRICE_H
#define GENERATE_PRICE_H

int Generate_Price(int min, int max);
void Tondo_Market(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Manila_Market(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Pandakan_Market(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Sapa_Market(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);

#endif