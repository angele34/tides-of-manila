#include "../header/common.h"

// Import user-defined libraries
#include "../header/generate_price.h" 
#include "../header/location.h"
#include "../header/menu.h"

Goods inventory = {0, 0, 0, 0};

void DisplayMenu(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);
void DisplayMainScreen(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);
void BuyScreen(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);
void SellScreen(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);
void DisplayNavigationScreen(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);

// Displays the main menu containing player data and progress
void DisplayMenu(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    
    // Dynamically updates the screen type
    if (strcmp(screen_type, "Main") == 0) {
        printf("Main Screen\n\n\n");
    } else if (strcmp(screen_type, "Purchase") == 0) {
        printf("Purchase Screen\n\n\n");
    } else if (strcmp(screen_type, "Sell") == 0) {
        printf("Sell Screen\n\n\n");
    } else if (strcmp(screen_type, "Navigation") == 0) {
        printf("Navigation Screen\n\n\n");
    }

    printf("Player: %03d \t\t\t\t Gold Coins: %d\n", player->player_code, player->initial_capital);
    printf("Location: ");
    printf("\033[1;38;5;214m");
    printf("%s", current_location);
    printf("\033[0m");
    printf(" \t\t\t Profit: %5d/%d%%\n", progress->current_profit, player->target_profit);

    printf("Day %d\n\n\n\n", progress->day);
}

// Displays the main screen containing cargo and market prices
void DisplayMainScreen(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(player, progress, current_location, "Main", game_state);
    
    printf("   Cargo \t%3d of 75\n", progress->cargo);
    printf("   =======================\n");
    printf("   Coconut - %2d  Silk - %2d\n", inventory.coconut, inventory.silk);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", inventory.rice, inventory.gun);


    // Display market prices based on location
    printf("   Market Prices\n");
    printf("   =======================\n");
    if (strcmp(current_location, "Manila") == 0) {
        Manila_Market();
    } else if (strcmp(current_location, "Tondo") == 0) {
        Tondo_Market();
    } else if (strcmp(current_location, "Pandakan") == 0) {
        Pandakan_Market();
    } else if (strcmp(current_location, "Sapa   ") == 0) {
        Sapa_Market();
    }

    Print_Prices();

    printf("What would you like to do?\n");
    printf("%*s%s", 4, "", "[1] Buy\n");
    printf("%*s%s", 4, "", "[2] Sell\n");
    printf("%*s%s", 4, "", "[3] Go to Another Port\n\n");
    printf("%*s%s", 4, "", "[Q] Quit\n\n\n");
    
    while (*game_state) {
        char key = getch();
        if (key == '1') {
            BuyScreen(player, progress, current_location, screen_type, game_state);
        } else if (key == '2') {
            SellScreen(player, progress, current_location, screen_type, game_state);
        } else if (key == '3') {
            DisplayNavigationScreen(player, progress, current_location, screen_type, game_state);
        } else if (key == 'q' || key == 'Q') {
            *game_state = false;
        }
    }

}

// Displays the BuyScreen screen upon pressing [1] BuyScreen
void BuyScreen(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(player, progress, current_location, "Purchase", game_state);

    printf("What would you like to Buy?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");
    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n\n\n");

    // TODO: Implement purchasing based on location prices

    while(*game_state) {
        char key = getch();
        if (key == '1') {
            printf("Buying Coconut\n");
        } else if (key == '2') {
            printf("Buying Rice\n");
        } else if (key == '3') {
            printf("Buying Silk\n");
        } else if (key == '4') {
            printf("Buying Gun\n");
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player, progress, current_location, screen_type, game_state);
        }
    }

}

void SellScreen(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player, progress, current_location, "Sell", game_state);

    printf("What would you like to Sell?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");
    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n\n\n");

    while(*game_state) {
        char key = getch();
        if (key == '1') {
            printf("Selling Coconut\n");
        } else if (key == '2') {
            printf("Selling Rice\n");
        } else if (key == '3') {
            printf("Selling Silk\n");
        } else if (key == '4') {
            printf("Selling Gun\n");
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player, progress, current_location, screen_type, game_state);
        }
    }

}

// Displays the navigation screen upon pressing [3] Go to Another Port
void DisplayNavigationScreen(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player, progress, current_location, "Navigation", game_state);
    Travel(player, progress, current_location, screen_type, game_state);
}
