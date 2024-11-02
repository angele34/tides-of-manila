#include "../header/common.h"

// Import user-defined libraries
#include "../header/location.h"
#include "../header/menu.h"
#include "../header/end_of_game.h"

int Check_Turns(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);

void Manila(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);
void Tondo(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state); 
void Pandakan(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);
void Sapa(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);

void Travel(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state);

int Check_Turns(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    int total_gold = player->initial_capital + progress->current_profit;
    if (progress->day >= 30 || total_gold >= player->target_profit + player->initial_capital) {
        *game_state = false;
        return 1;
    }
    return 0;
}

void Manila(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    strcpy(current_location, "Manila");
    if (Check_Turns(player, progress, current_location, screen_type, game_state)) return;
    (progress->day)++;
    DisplayMainScreen(player, progress, current_location, screen_type, game_state);
}

void Tondo(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    strcpy(current_location, "Tondo");
    if (Check_Turns(player, progress, current_location, screen_type, game_state)) return;
    (progress->day)++; 
   DisplayMainScreen(player, progress, current_location, screen_type, game_state);
}

void Pandakan(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    strcpy(current_location, "Pandakan"); 
    if (Check_Turns(player, progress, current_location, screen_type, game_state)) return;
    (progress->day)++; 
    DisplayMainScreen(player, progress, current_location, screen_type, game_state);

}

void Sapa(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    strcpy(current_location, "Sapa   ");
    if (Check_Turns(player, progress, current_location, screen_type, game_state)) return;
    (progress->day)++;
    DisplayMainScreen(player, progress, current_location, screen_type, game_state);
}

void Travel(PlayerData *player, PlayerProgress *progress, char current_location[], char screen_type[], bool *game_state) {
    if (strcmp(current_location, "Manila") == 0) 
    {
        printf("Where would you like to go?\n");
        printf("%*s%s", 3, "", "[1] Tondo\n");
        printf("%*s%s", 3, "", "[2] Pandakan\n");
        printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
        printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

        char key = getch();
        if (key == '1') {
            Tondo(player, progress, current_location, screen_type, game_state);
        } else if (key == '2') {
            Pandakan(player, progress, current_location, screen_type, game_state);
        } else if (key == '3') {
            Sapa(player, progress, current_location, screen_type, game_state);
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player, progress, current_location, screen_type, game_state);
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
            Manila(player, progress, current_location, screen_type, game_state);
        } else if (key == '2') {
            Pandakan(player, progress, current_location, screen_type, game_state);
        } else if (key == '3') {
            Sapa(player, progress, current_location, screen_type, game_state);
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player, progress, current_location, screen_type, game_state);
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
            Tondo(player, progress, current_location, screen_type, game_state);
        } else if (key == '2') {
            Manila(player, progress, current_location, screen_type, game_state);
        } else if (key == '3') {
            Sapa(player, progress, current_location, screen_type, game_state);
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player, progress, current_location, screen_type, game_state);
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
            Tondo(player, progress, current_location, screen_type, game_state);
        } else if (key == '2') {
            Pandakan(player, progress, current_location, screen_type, game_state);
        } else if (key == '3') {
            Manila(player, progress, current_location, screen_type, game_state);
        } else if (key == 'x' || key == 'X') {
            DisplayMainScreen(player, progress, current_location, screen_type, game_state);
        }
    }
}
