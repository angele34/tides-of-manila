#include "../header/common.h"
#include "../header/input.h"

// Takes the player data as input

void GetInput(int player_data[]) {
    do {
        printf("Player code: ");
        scanf("%d", &player_data[0]);
    } while (player_data[0] > 999);

    do {
        printf("Gold coins: ");
        scanf("%d", &player_data[1]); 
    } while (player_data[1] <= 0);

    int profit_percentage = player_data[1] * 0.2;
    
    do {
        printf("Target profit percentage: ");
        scanf("%d", &player_data[2]);
    } while (player_data[2] < profit_percentage);
}
