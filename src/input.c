#include "../header/common.h"
#include "../header/input.h"

// Takes the player data as input
void GetInput(int *nPlayer_code, int *nInitial_capital, int *nTarget_profit) {
    do {
        printf("Enter a valid Player code (1 to 999): ");
        if (scanf("%d", nPlayer_code) != 1) {
            printf("Please enter a number.\n");
            while (getchar() != '\n');
        }
    } while (*nPlayer_code <= 0 || *nPlayer_code > 999);

    do {
        printf("Enter the amount of gold coins to start with: ");
        if (scanf("%d", nInitial_capital) != 1) {
            printf("Please enter a number.\n");
            while (getchar() != '\n');
        }
    } while (*nInitial_capital <= 0);

    // Calculate the profit percentage
    int profit_percentage = *nInitial_capital * 0.2;

    do {
        printf("Enter your profit goal at least 20%% of your initial capital: ");
        if (scanf("%d", nTarget_profit) != 1) {
            printf("Please enter a number.\n");
            while (getchar() != '\n');
        }
    } while (*nTarget_profit < profit_percentage);
}
