#include "../header/common.h"

// Import user-defined libraries
#include "../header/end_of_game.h"

void End_Of_Game(int player_data[], int player_progress[]) {
    int total_gold = player_data[1] + player_progress[1];
    
    #ifdef _WIN32
        system("cls");
    #endif
    
    if (player_progress[0] >= 30 && total_gold < player_data[2] + player_data[1]) {
        printf("You Lose :( \n\n");
    } else if (total_gold >= player_data[2] + player_data[1]) {
        printf("You Win!\n\n");
    }
    
    printf("Total Gold %d\n", total_gold);
    printf("Profit %d\n", player_progress[1]);
    printf("Number of turns %d\n\n\n", player_progress[0]);
}
