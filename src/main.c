#include "../header/common.h"
// Import user-defined libraries
#include "../header/welcome.h"
#include "../header/generate_price.h"
#include "../header/menu.h"
#include "../header/input.h"
#include "../header/end_of_game.h"
#include "../header/location.h"
#include "../header/check_turns.h"

int main() {
    srand(time(0));

    // Declare as local variables
    int player_data[3];
    // player_data[0]: player_code, player_data[1]: initial_capital, player_data[2]: target_profit
    int player_progress[3] = {0, 0, 0};
    // player_progress[0]: day, player_progress[1]: current_profit, player_progress[2]: cargo
    int inventory[4] = {0, 0, 0, 0};
    // inventory [0]: coconut, inventory [1]: silk, inventory [2]: rice, inventory [3]: gun
    int market_prices[4];
    // market_prices[0]: coconut, market_prices[1]: silk, market_prices[2]: rice, market_prices[3]: gun

    int quantity = 0;
    char current_location[20] = "Manila";
    char screen_type[20] = "Main";
    char item_name[20] = "";

    // Displays the welcome message
    Welcome();
    // Prompts user for input before starting
    GetInput(player_data);

    // Set initial value of game_state to true to run the game
    bool game_state = true;

    while (game_state) {
        Check_Turns(player_data, player_progress, inventory, market_prices, &quantity, current_location, screen_type, item_name, &game_state);
        // Checks if game_state is not false
        if (game_state) {
            // Displays the Main Screen
            DisplayMenu(player_data, player_progress, inventory, market_prices, &quantity, current_location, screen_type, item_name, &game_state);
            DisplayMainScreen(player_data, player_progress, inventory, market_prices, &quantity, current_location, screen_type, item_name, &game_state);
        }
    }

    // Displays End of Game
    End_Of_Game(player_data, player_progress);
    return 0;
}
