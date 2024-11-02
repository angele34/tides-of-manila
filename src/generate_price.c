#include "../header/common.h"

#include "../header/menu.h"
#include "../header/generate_price.h"

int Generate_Price(int min, int max) {
    return min + rand() % (max - min + 1);
}

void Print_Prices(MarketPrices *prices) {
    printf("   Coconut - %2d  Silk - %2d\n", prices->coconut, prices->silk);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", prices->rice, prices->gun);
}

void Tondo_Market(MarketPrices *prices) {
    prices->coconut = Generate_Price(4, 24);
    prices->rice = Generate_Price(1, 20);
    prices->silk = Generate_Price(48, 68);
    prices->gun = Generate_Price(70, 95);
}

void Manila_Market(MarketPrices *prices) {
    prices->coconut = Generate_Price(3, 18);
    prices->rice = Generate_Price(5, 20);
    prices->silk = Generate_Price(24, 39);
    prices->gun = Generate_Price(65, 84);
}

void Pandakan_Market(MarketPrices *prices) {
    prices->coconut = Generate_Price(2, 12);
    prices->rice = Generate_Price(4, 14);
    prices->silk = Generate_Price(22, 32);
    prices->gun = Generate_Price(90, 103);
}

void Sapa_Market(MarketPrices *prices) {
    prices->coconut = Generate_Price(9, 14);
    prices->rice = Generate_Price(1, 6);
    prices->silk = Generate_Price(17, 22);
    prices->gun = Generate_Price(204, 301);
}

// TODO: Fix Market Prices updating every time the player navigates between screens
void Set_Prices(MarketPrices *prices, char current_location[]) {
    if (strcmp(current_location, "Manila") == 0) {
        Manila_Market(prices);
    } else if (strcmp(current_location, "Tondo") == 0) {
        Tondo_Market(prices);
    } else if (strcmp(current_location, "Pandakan") == 0) {
        Pandakan_Market(prices);
    } else if (strcmp(current_location, "Sapa   ") == 0) {
        Sapa_Market(prices);
    }
}

void Buy(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state) {
    int total_cost = 0;
    if (strcmp(items->item, "coconut") == 0) {
        total_cost = items->quantity * prices->coconut;
    } else if (strcmp(items->item, "rice") == 0) {
        total_cost = items->quantity * prices->rice;
    } else if (strcmp(items->item, "silk") == 0) {
        total_cost = items->quantity * prices->silk;
    } else if (strcmp(items->item, "gun") == 0) {
        total_cost = items->quantity * prices->gun;
    } 

    if (player->initial_capital >= total_cost && progress->cargo <= 75) {
        progress->cargo += items->quantity;
        player->initial_capital -= total_cost;
        printf("Purchase successful! Returning to Main Screen...\n");

        // Update quantity of the items in Player inventory
        if (strcmp(items->item, "coconut") == 0) {
            inventory->coconut += items->quantity;
        } else if (strcmp(items->item, "rice") == 0) {
            inventory->rice+= items->quantity;
        } else if (strcmp(items->item, "silk") == 0) {
            inventory->silk += items->quantity;
        } else if (strcmp(items->item, "gun") == 0) {
            inventory->gun += items->quantity;
        } 

    } else {
        if (progress->cargo > 75) {
            printf("Purchase unsuccessful, cargo full.");
        } else if (player->initial_capital < total_cost) {
            printf("Purchase unsuccessful, insufficient capital");
        }
        printf("Returning to Main Screen...");
        
    }
    Sleep(2000);
    DisplayMainScreen(player, progress, inventory, prices, items, current_location, screen_type, game_state);
}

void Sell(PlayerData *player, PlayerProgress *progress, Goods *inventory, MarketPrices *prices, Item *items, char current_location[], char screen_type[], bool *game_state) {
    int total_cost = 0;
    if (strcmp(items->item, "coconut") == 0) {
        total_cost = items->quantity * prices->coconut;
        if (inventory->coconut >= items->quantity) {
            player->initial_capital += total_cost;
            inventory->coconut -= items->quantity;
            progress->cargo -= items-> quantity;
        } else {
            printf("Sale unsuccessful, insufficient quantity of Coconut.\n Returning to Main Screen...");
        }
    } else if (strcmp(items->item, "rice") == 0) {
        total_cost = items->quantity * prices->rice;
        if (inventory->rice >= items->quantity) {
            player->initial_capital += total_cost;
            inventory->rice -= items->quantity;
            progress->cargo -= items-> quantity;
        } else {
            printf("Sale unsuccessful, insufficient quantity of Rice.\n Returning to Main Screen...");
        }
    } else if (strcmp(items->item, "silk") == 0) {
        total_cost = items->quantity * prices->silk;
        if (inventory->silk >= items->quantity) {
            player->initial_capital += total_cost;
            inventory->silk -= items->quantity;
            progress->cargo -= items-> quantity;
        } else {
            printf("Sale unsuccessful, insufficient quantity of Silk.\n Returning to Main Screen...");
        }
    } else if (strcmp(items->item, "gun") == 0) {
        total_cost = items->quantity * prices->gun;
        if (inventory->gun >= items->quantity) {
            player->initial_capital += total_cost;
            inventory->gun -= items->quantity;
            progress->cargo -= items-> quantity;
        } else {
            printf("Sale unsuccessful, insufficient quantity of Gun.\n Returning to Main Screen...");
        }
    }
    Sleep(2000);
    DisplayMainScreen(player, progress, inventory, prices, items, current_location, screen_type, game_state);
}
