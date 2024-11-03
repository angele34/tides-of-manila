#include "../header/common.h"

// Import user-defined libraries
#include "../header/location.h"
#include "../header/menu.h"
#include "../header/end_of_game.h"
#include "../header/check_turns.h"

void Manila(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    strcpy(current_location, "Manila");
    if (Check_Turns(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state)) return;
    (player_progress[0])++;
    printf("Travel successful! Returning to Main screen...");
    Sleep(2000);
    DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
}

void Tondo(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    strcpy(current_location, "Tondo");
    if (Check_Turns(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state)) return;
    (player_progress[0])++; 
    printf("Travel successful! Returning to Main screen...");
    Sleep(2000);
    DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
}

void Pandakan(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    strcpy(current_location, "Pandakan"); 
    if (Check_Turns(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state)) return;
    (player_progress[0])++; 
    printf("Travel successful! Returning to Main screen...");
    Sleep(2000);
    DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);

}

void Sapa(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    strcpy(current_location, "Sapa   ");
    if (Check_Turns(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state)) return;
    (player_progress[0])++;
    printf("Travel successful! Returning to Main screen...");
    Sleep(2000);
    DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
}

void Travel(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    if (strcmp(current_location, "Manila") == 0) 
    {
        printf("Where would you like to go?\n");
        printf("%*s%s", 3, "", "[1] Tondo\n");
        printf("%*s%s", 3, "", "[2] Pandakan\n");
        printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
        printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

        char key = getch();
        if (key == '1') {
            Tondo(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '2') {
            Pandakan(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '3') {
            Sapa(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        }
    } 
    
    else if (strcmp(current_location, "Tondo") == 0) 
    {
        printf("Where would you like to go?\n");
        printf("%*s%s", 3, "", "[1] Manila\n");
        printf("%*s%s", 3, "", "[2] Pandakan\n");
        printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
        printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

        char key = getch();
        if (key == '1') {
            Manila(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '2') {
            Pandakan(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '3') {
            Sapa(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        }
    } 
    
    else if (strcmp(current_location, "Pandakan") == 0) 
    {
        printf("Where would you like to go?\n");
        printf("%*s%s", 3, "", "[1] Tondo\n");
        printf("%*s%s", 3, "", "[2] Manila\n");
        printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
        printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

        char key = getch();
        if (key == '1') {
            Tondo(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '2') {
            Manila(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '3') {
            Sapa(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        }
    } 
    
    else if (strcmp(current_location, "Sapa   ") == 0) 
    {
        printf("Where would you like to go?\n");
        printf("%*s%s", 3, "", "[1] Tondo\n");
        printf("%*s%s", 3, "", "[2] Pandakan\n");
        printf("%*s%s", 3, "", "[3] Manila\n\n\n");
        printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

        char key = getch();
        if (key == '1') {
            Tondo(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '2') {
            Pandakan(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == '3') {
            Manila(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player_data, player_progress, inventory, market_prices, quantity, current_location, screen_type, item_name, game_state);
        }
    }
}
