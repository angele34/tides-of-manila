#include "../header/common.h"

// Import user-defined libraries
#include "../header/location.h"
#include "../header/generate_price.h"
#include "../header/menu.h"
#include "../header/end_of_game.h"
#include "../header/check_turns.h"

int Travel (int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price) {
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
        *navigated = false;
        switch(*nCurrent_Loc) {
            case 1: // Manila
                *nCoconut_price = Generate_Price(3, 18);
                *nRice_price = Generate_Price(5, 20);
                *nSilk_price = Generate_Price(24, 39);
                *nGun_price = Generate_Price(65, 84);
                break;
            case 2: // Tondo:
                *nCoconut_price = Generate_Price(4, 24);
                *nRice_price = Generate_Price(1, 20);
                *nSilk_price = Generate_Price(48, 68);
                *nGun_price = Generate_Price(70, 95);
                break;
            case 3: // Pandakan
                *nCoconut_price = Generate_Price(2, 12);
                *nRice_price = Generate_Price(4, 14);
                *nSilk_price = Generate_Price(22, 32);
                *nGun_price = Generate_Price(90, 103);
                break;
            case 4: // Sapa:
                *nCoconut_price = Generate_Price(9, 14);
                *nRice_price = Generate_Price(1, 6);
                *nSilk_price = Generate_Price(17, 22);
                *nGun_price = Generate_Price(204, 301);
                break;
        } 
        printf("Travel successful! Returning to Main screen...");
        Sleep(1500);
        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price);
        
    } else if (key == 'x' || key == 'X') {
        printf("Travel unsuccessful, Returning to Main screen...");
        Sleep(1500); 
        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price);
        
    }
   return 0;
}