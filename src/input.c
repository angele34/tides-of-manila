#include <stdio.h>
#include "../header/input.h"

// Takes the player data as input

void GetInput(int *player_code, int *initial_capital, int *target_profit) {
    do {
        printf("Enter a three-digit player code: ");
        scanf("%d", player_code);
    } while (*player_code > 999);

    do {
        printf("Enter initial capital (gold coins): ");
        scanf("%d", initial_capital); 
    } while (*initial_capital <= 0);

    printf("Enter target profit percentage: ");
    scanf("%d", target_profit);
}
