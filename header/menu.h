#ifndef MENU_H
#define MENU_H

// Input values are passed on to the DisplayMenu function
void DisplayMenu(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);
void DisplayMainScreen(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);
void Display_Details(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);
void BuyScreen(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);
void SellScreen(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);
void DisplayNavigationScreen(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state);

#endif
