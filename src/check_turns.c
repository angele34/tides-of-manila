#include "../header/common.h"
#include "../header/check_turns.h"

int Check_Turns(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state) {
    int total_gold = player->initial_capital + progress->current_profit;
    if (progress->day >= 30 || total_gold >= player->target_profit + player->initial_capital) {
        *game_state = false;
        return 1;
    }
    return 0;
}
