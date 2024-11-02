#include "../header/common.h"

// Import user-defined libraries
#include "../header/end_of_game.h"

void End_Of_Game(PlayerData *player, PlayerProgress *progress) {
    int total_gold = player->initial_capital + progress->current_profit;
    
    #ifdef _WIN32
    system("cls");
    #endif
    
    if (progress->day >= 30 && total_gold < player->target_profit + player->initial_capital) {
        printf("You Lose :( \n\n");
    } else if (total_gold >= player->target_profit + player->initial_capital) {
        printf("You Win!\n\n");
    }
    
    printf("Total Gold %d\n", total_gold);
    printf("Profit %d\n", progress->current_profit);
    printf("Number of turns %d\n\n\n", progress->day);
}
