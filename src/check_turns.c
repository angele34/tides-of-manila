#include "../header/common.h"
#include "../header/check_turns.h"

int Check_Turns(int player_data[], int player_progress[], int inventory[], int market_prices[], int *quantity, char current_location[], char screen_type[], char item_name[], bool *game_state) {
    int total_gold = player_data[1] + player_progress[1];
    if (player_progress[0] >= 30 || total_gold >= player_data[2] + player_data[1]) {
        *game_state = false;
        return 1;
    }
    return 0;
}
