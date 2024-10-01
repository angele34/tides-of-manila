#include <stdio.h>
#include "../header/welcome.h"
#include "../header/menu.h"
#include "../header/input.h"

int main() {
    // Declare as local variables
    int player_code, initial_capital, target_profit;

    // Displays the welcome message
    Welcome();
    // Prompts user for input
    GetInput(&player_code, &initial_capital, &target_profit);

    // Displays Menu
    DisplayMenu(player_code, initial_capital, target_profit);
}
