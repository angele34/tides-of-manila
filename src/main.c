#include "../header/common.h"
// Import user-defined libraries
#include "../header/input.h"
#include "../header/end_of_game.h"
#include "../header/generate_price.h"
#include "../header/location.h"
#include "../header/check_turns.h"
#include "../header/menu.h"
#include "../header/welcome.h"

int main() {
    srand(time(0));

    // Player data
    int nPlayer_code, nInitial_capital, nTarget_profit;
    // Player progress
    int nDay = 1, nCurrent_profit = 0, nCargo = 0;
    // Player inventory
    int nCoconut = 0, nSilk = 0, nRice = 0, nGun = 0;

    int nQuantity = 0, nItem = 1;

    int nCurrent_Loc = 1;
    int nScreen_type = 1;


    // Displays the welcome message
    Welcome();
    // Prompts user for input before starting
    GetInput(&nPlayer_code, &nInitial_capital, &nTarget_profit);

    // Set initial value of game_state to true to run the game
    bool bGame_state = true;
    bool navigated = false;

    while (bGame_state) {
        Check_Turns(&nInitial_capital, nTarget_profit, &nDay, &nCurrent_profit, &bGame_state);
        // Checks if game_state is not false
        if (bGame_state) {
            // Displays the Main Screen and Menu containing Player stats
            // DisplayMenu(nPlayer_code, &nInitial_capital, nTarget_profit, &nDay, &nCurrent_profit, &nCargo, &nCurrent_Loc, &nScreen_type);
            Set_Prices(nPlayer_code, &nInitial_capital, nTarget_profit, &nDay, &nCurrent_profit, &navigated, &bGame_state, &nCurrent_Loc, &nScreen_type, &nCargo, &nCoconut, &nSilk, &nRice, &nGun, &nItem, &nQuantity);
        }
    }

    // Displays End of Game
    End_Of_Game(&nInitial_capital, nTarget_profit, &nDay, &nCurrent_profit);
    return 0;
}
