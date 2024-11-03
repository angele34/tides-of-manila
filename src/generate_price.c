#include "../header/common.h"

#include "../header/menu.h"
#include "../header/generate_price.h"

int Generate_Price(int min, int max) {
    return min + rand() % (max - min + 1);
}

void Print_Prices(int market_prices[]) {
    printf("   Coconut - %2d  Silk - %2d\n", market_prices[0], market_prices[1]);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", market_prices[2], market_prices[3]);
}

void Tondo_Market(int market_prices[]) {
    market_prices[0] = Generate_Price(4, 24);
    market_prices[1] = Generate_Price(1, 20);
    market_prices[2] = Generate_Price(48, 68);
    market_prices[3] = Generate_Price(70, 95);
}

void Manila_Market(int market_prices[]) {
    market_prices[0] = Generate_Price(3, 18);
    market_prices[1] = Generate_Price(5, 20);
    market_prices[2] = Generate_Price(24, 39);
    market_prices[3] = Generate_Price(65, 84);
}

void Pandakan_Market(int market_prices[]) {
    market_prices[0] = Generate_Price(2, 12);
    market_prices[1] = Generate_Price(4, 14);
    market_prices[2] = Generate_Price(22, 32);
    market_prices[3] = Generate_Price(90, 103);
}

void Sapa_Market(int market_prices[]) {
    market_prices[0] = Generate_Price(9, 14);
    market_prices[1] = Generate_Price(1, 6);
    market_prices[2] = Generate_Price(17, 22);
    market_prices[3] = Generate_Price(204, 301);
}


void Set_Prices(int market_prices[], char current_location[]) {
    if (strcmp(current_location, "Manila") == 0) {
        Manila_Market(market_prices);
    } else if (strcmp(current_location, "Tondo") == 0) {
        Tondo_Market(market_prices);
    } else if (strcmp(current_location, "Pandakan") == 0) {
        Pandakan_Market(market_prices);
    } else if (strcmp(current_location, "Sapa   ") == 0) {
        Sapa_Market(market_prices);
    }
}

void Buy(int player_data[],int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    int total_cost = 0;
    if (strcmp(item_name, "coconut") == 0) {
        total_cost = *quantity * market_prices[0];
    } else if (strcmp(item_name, "silk") == 0) {
        total_cost = *quantity * market_prices[1];
    } else if (strcmp(item_name, "rice") == 0) {
        total_cost = *quantity * market_prices[2];
    }  else if (strcmp(item_name, "gun") == 0) {
        total_cost = *quantity * market_prices[3];
    } 

    if (player_data[1] >= total_cost && player_progress[2] <= 75) {
        player_progress[2] += *quantity;
        player_data[1] -= total_cost;
        printf("Purchase successful! Returning to Main Screen...\n");

        // Update quantity of the items in Player inventory
        if (strcmp(item_name, "coconut") == 0) {
            inventory[0] += *quantity;
        } else if (strcmp(item_name, "silk") == 0) {
            inventory[1] += *quantity;
        } else if (strcmp(item_name, "rice") == 0) {
            inventory[2] += *quantity;
        } else if (strcmp(item_name, "gun") == 0) {
            inventory[3] += *quantity;
        } 

    } else {
        if (player_progress[2] > 75) {
            printf("Purchase unsuccessful, cargo full.");
        } else if (player_data[1] < total_cost) {
            printf("Purchase unsuccessful, insufficient capital");
        }
        printf("Returning to Main Screen...");
        
    }
    Sleep(2000);
    DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
}

void Sell(int player_data[],int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    int total_cost = 0;
    if (strcmp(item_name, "coconut") == 0) {
        total_cost = *quantity * market_prices[0];
        if (inventory[0] >= *quantity) {
            player_data[1] += total_cost;
            inventory[0] -= *quantity;
            player_progress[2] -= *quantity;
            player_progress[1] += total_cost;
        } else {
            printf("Sale unsuccessful, insufficient quantity of Coconut.\n Returning to Main Screen...");
        }
    } else if (strcmp(item_name, "silk") == 0) {
        total_cost = *quantity * market_prices[1];
        if (inventory[1]>= *quantity) {
            player_data[1] += total_cost;
            inventory[1] -= *quantity;
            player_progress[2] -= *quantity;
            player_progress[1] += total_cost;
        } else {
            printf("Sale unsuccessful, insufficient quantity of Silk.\n Returning to Main Screen...");
        }
    } else if (strcmp(item_name, "rice") == 0) {
        total_cost = *quantity * market_prices[2];
        if (inventory[2] >= *quantity) {
            player_data[1] += total_cost;
            inventory[2] -= *quantity;
            player_progress[2] -= *quantity;
            player_progress[1] += total_cost;
        } else {
            printf("Sale unsuccessful, insufficient quantity of Rice.\n Returning to Main Screen...");
        }
    } else if (strcmp(item_name, "gun") == 0) {
        total_cost = *quantity * market_prices[3];
        if (inventory[3] >= *quantity) {
            player_data[1] += total_cost;
            inventory[3] -= *quantity;
            player_progress[2] -= *quantity;
            player_progress[1] += total_cost;
        } else {
            printf("Sale unsuccessful, insufficient quantity of Gun.\n Returning to Main Screen...");
        }
    }
    Sleep(2000);
    DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
}
