#ifndef GENERATE_PRICE_H
#define GENERATE_PRICE_H

int Generate_Price(int min, int max);

void Print_Prices(int market_prices[]);
void Tondo_Market(int market_prices[]);
void Manila_Market(int market_prices[]);
void Pandakan_Market(int market_prices[]);
void Sapa_Market(int market_prices[]);
void Set_Prices(int market_prices[], char current_location[]);
void Buy(int player_data[],int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state);
void Sell(int player_data[],int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state);

#endif