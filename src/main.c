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
    // Randomize seed
    srand(time(NULL));
    // Player data
    int nPlayer_code, nInitial_capital, nTarget_profit;
    // Player progress
    int nDay = 0, nCurrent_profit = 0, nCargo = 0;
    // Player inventory
    int nCoconut = 0, nSilk = 0, nRice = 0, nGun = 0;
    int nQuantity = 0, nItem = 0;
    // Starting port: Manila, initially initialized the prices, current location, and screen type (Main Screen)
    int nCoconut_price = Generate_Price(3, 18);
    int nRice_price = Generate_Price(5, 20);
    int nSilk_price = Generate_Price(24, 39);
    int nGun_price = Generate_Price(65, 84);
    int nCurrent_Loc = 1,  nScreen_type = 1;

    // Displays the welcome message
    Welcome();
    // Prompts user for input before starting
    GetInput(&nPlayer_code, &nInitial_capital, &nTarget_profit);
    // Calculate profit
    int nCash = nInitial_capital;

    // Set initial value of game_state to true to run the game
    bool bGame_state = true;
    bool bNavigated = false;
    
    while (bGame_state) {
        Check_Turns(&nInitial_capital, nTarget_profit, &nDay, &nCurrent_profit, &bGame_state);
        // Checks if game_state is not false
        if (bGame_state) {
            // Displays the Main Screen and Menu containing Player stats
            Main_Screen(nPlayer_code, &nInitial_capital, nTarget_profit, &nDay, &nCurrent_profit, &bNavigated, &bGame_state, &nCurrent_Loc, &nScreen_type, &nCargo, &nCoconut, &nSilk, &nRice, &nGun, &nItem, &nQuantity, &nCoconut_price, &nSilk_price, &nRice_price, &nGun_price, nCash);
        }
    }
    // Displays End of Game
    End_Of_Game(&nInitial_capital, nTarget_profit, &nDay, &nCurrent_profit, nCash);
    return 0;
}
