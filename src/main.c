#include <stdio.h>
#include <stdbool.h>

// Import user-defined libraries
#include "../header/welcome.h"
#include "../header/menu.h"
#include "../header/input.h"
#include "../header/end_of_game.h"
#include "../header/location.h"

int main() {
    // Declare as local variables
    int player_code, initial_capital, target_profit;
    int day = 0, current_profit = 0, cargo = 0;
    char current_location[20] = "Manila";
    char screen_type[20] = "Main";

    // Displays the welcome message
    Welcome();
    // Prompts user for input
    GetInput(&player_code, &initial_capital, &target_profit);
    
    bool game_state = true;

    while (game_state) {
        Check_Turns(player_code, initial_capital, target_profit, current_profit, &day, cargo, current_location, screen_type, &game_state);
        if (game_state) {
            // Displays Menu
            DisplayMenu(player_code, initial_capital, target_profit, current_profit, &day, cargo, current_location, screen_type, &game_state);
            DisplayMainScreen(player_code, initial_capital, target_profit, current_profit, &day, cargo, current_location, screen_type, &game_state);
        }
    }

    End_Of_Game(target_profit, initial_capital, current_profit, day);
    return 0;
}
