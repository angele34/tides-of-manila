#include "../header/common.h"
#include "../header/input.h"

// Takes the player data as input

void GetInput(int *player_code, int *initial_capital, int *target_profit) {
    do {
        printf("Player code: ");
        scanf("%d", player_code);
    } while (*player_code > 999);

    do {
        printf("Gold coins: ");
        scanf("%d", initial_capital); 
    } while (*initial_capital <= 0);

    int profit_percentage = *initial_capital * 0.2;
    do {
        printf("Target profit percentage: ");
        scanf("%d", target_profit);
    } while (*target_profit < profit_percentage);
}
