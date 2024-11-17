#include "../header/common.h"
#include "../header/input.h"

// Takes the player data as input

void GetInput(int *nPlayer_code, int *nInitial_capital, int *nTarget_profit) {
    do {
        printf("Player code: ");
        scanf("%d", nPlayer_code);
    } while (*nPlayer_code > 999);

    do {
        printf("Gold coins: ");
        scanf("%d", nInitial_capital); 
    } while (*nInitial_capital <= 0);

    int profit_percentage = *nInitial_capital * 0.2;
    
    do {
        printf("Target profit percentage: ");
        scanf("%d", nTarget_profit);
    } while (*nTarget_profit < profit_percentage);
}
