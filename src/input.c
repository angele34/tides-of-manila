#include "../header/common.h"
#include "../header/input.h"

// Takes the player data as input

void GetInput(PlayerData *player) {
    do {
        printf("Player code: ");
        scanf("%d", &player->player_code);
    } while (player->player_code > 999);

    do {
        printf("Gold coins: ");
        scanf("%d", &player->initial_capital); 
    } while (player->initial_capital <= 0);

    int profit_percentage = player->initial_capital * 0.2;
    
    do {
        printf("Target profit percentage: ");
        scanf("%d", &player->target_profit);
    } while (player->target_profit < profit_percentage);
}
