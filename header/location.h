#ifndef LOCATION_H
#define LOCATION_H

int Check_Turns(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Manila(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Tondo(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state); 
void Pandakan(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Sapa(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);
void Travel(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state);

#endif