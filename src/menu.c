#include "../header/common.h"

// Import user-defined libraries
#include "../header/generate_price.h" 
#include "../header/location.h"
#include "../header/menu.h"
#include "../header/check_turns.h"

// Displays the main menu containing player data and progress
void DisplayMenu(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    
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

    printf("Player: %03d \t\t\t\t Gold Coins: %d\n", player_data[0], player_data[1]);
    printf("Location: ");
    printf("\033[1;38;5;214m");
    printf("%s", current_location);
    printf("\033[0m");
    printf(" \t\t\t Profit: %5d/%d%%\n", player_progress[1], player_data[2]);

    printf("Day %d\n\n\n\n", player_progress[0]);
}

// Displays the main screen containing cargo and market prices
void DisplayMainScreen(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    if (Check_Turns(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state)) return;

    #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(player_data, player_progress, inventory, market_prices, quantity, current_location, "Main", item_name, game_state);

    // TODO: Set prices only once user goes to another port
    Set_Prices(market_prices, current_location);
    Display_Details(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);

    printf("What would you like to do?\n");
    printf("%*s%s", 4, "", "[1] Buy\n");
    printf("%*s%s", 4, "", "[2] Sell\n");
    printf("%*s%s", 4, "", "[3] Go to Another Port\n\n");
    printf("%*s%s", 4, "", "[Q] Quit\n\n\n");
    
    while (*game_state) {
        char key = getch();
        if (key == '1') {
            BuyScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '2') {
            SellScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '3') {
            DisplayNavigationScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == 'q' || key == 'Q') {
            *game_state = false;
        }
    }

}

void Display_Details(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    // Display items in cargo
    printf("   Cargo \t%3d of 75\n", player_progress[2]);
    printf("   =======================\n");
    printf("   Coconut - %2d  Silk - %2d\n", inventory[0], inventory[1]);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", inventory[2], inventory[4]);

    // Display market prices based on location
    printf("   Market Prices\n");
    printf("   =======================\n");

    Print_Prices(market_prices);
}

// Displays the Buy Screen screen upon pressing [1] Buy
void BuyScreen(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif
    
    DisplayMenu(player_data, player_progress, inventory, market_prices, quantity, current_location, "Purchase", item_name, game_state);
    
    Display_Details(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);

    printf("What would you like to Buy?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");
    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n");

    while (*game_state) {
        *quantity = 0; 
        char key = getch();

        if (key == '1') {
            strcpy(item_name, "coconut");
        } else if (key == '2') {
            strcpy(item_name, "rice");
        } else if (key == '3') {
            strcpy(item_name, "silk");
        } else if (key == '4') {
            strcpy(item_name, "gun");
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
            continue;
        }
        
        printf("How many would %s(s) you like to buy? ", item_name);
        scanf("%d", quantity); 

        if (*quantity > 0) {
            Buy(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else {
            printf("Please enter a valid quantity\n");
        }
    }
}

// Displays the Sell screen upon pressing [2] Sell
void SellScreen(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(player_data, player_progress, inventory, market_prices, quantity, current_location, "Sell", item_name, game_state);
    Display_Details(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);

    printf("What would you like to Sell?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");
    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n");

    while (*game_state) {
        *quantity = 0; 
        char key = getch();

        if (key == '1') {
            strcpy(item_name, "coconut");
        } else if (key == '2') {
            strcpy(item_name, "rice");
        } else if (key == '3') {
            strcpy(item_name, "silk");
        } else if (key == '4') {
            strcpy(item_name, "gun");
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
            continue;
        }
        
        printf("How many would %s(s) you like to sell? ", item_name);
        scanf("%d", quantity); 

        if (*quantity > 0) {
            Sell(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else {
            printf("Please enter a valid quantity.\n");
        }
    }

}

// Displays the navigation screen upon pressing [3] Go to Another Port
void DisplayNavigationScreen(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(player_data, player_progress, inventory, market_prices, quantity, current_location, "Navigation", item_name, game_state);
    Travel(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
}
