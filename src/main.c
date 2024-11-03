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
    PlayerData player;
    PlayerProgress progress = {0, 0, 0};
    Goods inventory = {0, 0, 0, 0};
    MarketPrices prices;
    Item items;

    char current_location[20] = "Manila";
    char screen_type[20] = "Main";

    // Displays the welcome message
    Welcome();
    // Prompts user for input
    GetInput(&player);
    
    bool game_state = true;

    while (game_state) {
        Check_Turns(&player, &progress, &inventory, &prices, &items, current_location, screen_type, &game_state);

        // Checks if game_state is not false
        if (game_state) {
            // Displays Menu
            DisplayMenu(&player, &progress, &inventory, &prices, &items, current_location, screen_type, &game_state);
            DisplayMainScreen(&player, &progress, &inventory, &prices, &items, current_location, screen_type, &game_state);
        }
    }

    // Display End of Game
    End_Of_Game(&player, &progress);
    return 0;
}
