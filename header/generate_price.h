#ifndef GENERATE_PRICE_H
#define GENERATE_PRICE_H

int Generate_Price(int min, int max);

void Print_Prices(MarketPrices *prices);
void Tondo_Market(MarketPrices *prices);
void Manila_Market(MarketPrices *prices);
void Pandakan_Market(MarketPrices *prices);
void Sapa_Market(MarketPrices *prices);
void Set_Prices(MarketPrices *prices, char current_location[]);
void Buy(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);
void Sell(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);

#endif