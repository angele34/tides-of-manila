#ifndef LOCATION_H
#define LOCATION_H

void Manila(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);
void Tondo(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state); 
void Pandakan(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);
void Sapa(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);
void Travel(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);

#endif