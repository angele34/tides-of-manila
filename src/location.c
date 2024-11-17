#include "../header/common.h"

// Import user-defined libraries
#include "../header/location.h"
#include "../header/generate_price.h"
#include "../header/menu.h"
#include "../header/end_of_game.h"
#include "../header/check_turns.h"

int Travel (int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity) {
    // Check if game is still running
    if (Check_Turns(nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bGame_state)) return 1;

    // Display options for navigation
    printf("Where would you like to go?\n");
    switch(*nCurrent_Loc) {
        case 1: // Manila
            printf("%*s%s", 3, "", "[1] Tondo\n");
            printf("%*s%s", 3, "", "[2] Pandakan\n");
            printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
            break;
        case 2: // Tondo:
            printf("%*s%s", 3, "", "[1] Manila\n");
            printf("%*s%s", 3, "", "[2] Pandakan\n");
            printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
            break;
        case 3: // Pandakan
            printf("%*s%s", 3, "", "[1] Tondo\n");
            printf("%*s%s", 3, "", "[2] Manila\n");
            printf("%*s%s", 3, "", "[3] Sapa\n\n\n");
            break;
        case 4: // Sapa:
            printf("%*s%s", 3, "", "[1] Tondo\n");
            printf("%*s%s", 3, "", "[2] Pandakan\n");
            printf("%*s%s", 3, "", "[3] Manila\n\n\n");
            break;
    }

    printf("%*s%s", 3, "", "[X] Return to the Main Screen\n\n\n");

    char key = getch();
    switch(*nCurrent_Loc) {
        case 1:
            if (key == '1') { *nCurrent_Loc = 2; *navigated = true; } 
            else if (key == '2') { *nCurrent_Loc = 3; *navigated = true; }
            else if (key == '3') { *nCurrent_Loc = 4; *navigated = true; }
            break;
        case 2:
            if (key == '1') { *nCurrent_Loc = 1; *navigated = true; }
            else if (key == '2') { *nCurrent_Loc = 3; *navigated = true; }
            else if (key == '3') { *nCurrent_Loc = 4;*navigated = true; }
            break;
        case 3: 
            if (key == '1') { *nCurrent_Loc = 2; *navigated = true; }
            else if (key == '2') { *nCurrent_Loc = 1; *navigated = true; }
            else if (key == '3') { *nCurrent_Loc = 4; *navigated = true; }
            break;
        case 4: 
            if (key == '1') { *nCurrent_Loc = 2; *navigated = true; }
            else if (key == '2') { *nCurrent_Loc = 3; *navigated = true; }
            else if (key == '3') { *nCurrent_Loc = 1; *navigated = true; }
            break;
    }

    if (*navigated) {
        (*nDay)++;
        printf("Travel successful! Returning to Main screen...");
        Sleep(2000);
        *navigated = false; 
        Set_Prices(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity);
        
    } else if (key == 'x' || key == 'X') {
        printf("Travel unsuccessful! Returning to Main screen...");
        Sleep(2000); 
        Set_Prices(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity);
        
    }
   return 0;
}