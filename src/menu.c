#include "../header/common.h"

// Import user-defined libraries
#include "../header/generate_price.h" 
#include "../header/location.h"
#include "../header/menu.h"
#include "../header/check_turns.h"

// Displays the main menu containing player data and progress
// @param = 
void DisplayMenu(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, int *nCargo, int *nCurrent_Loc, int *nScreen_type)
{
     switch(*nScreen_type) {
        case 1:
            printf("Main Screen\n\n\n");
            break;
        case 2:
            printf("Purchase Screen\n\n\n");
            break;
        case 3:
            printf("Sell Screen\n\n\n");
            break;
        case 4:
            printf("Navigation Screen\n\n\n");
            break;
    }

    printf("Player: %03d \t\t\t\t Gold Coins: %d\n", nPlayer_code, *nInitial_capital);
    printf("Location: ");
    printf("\033[1;38;5;214m");
    switch (*nCurrent_Loc) {
        case 1:
            printf("Manila");
            break;
        case 2:
            printf("Tondo");
            break;
        case 3:
            printf("Pandakan");
            break;
        case 4:
            printf("Sapa");
            break;
    }
    printf("\033[0m");
    printf(" \t\t\t Profit: %5d/%d%%\n", *nCurrent_profit, nTarget_profit);
    printf("Day %d\n\n\n\n", *nDay);
}

// Displays the Buy Screen screen upon pressing [1] Buy

void BuyScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity) {
    *nScreen_type = 2;
    #ifdef _WIN32
        system("cls");
    #endif
    DisplayMenu(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, nCargo, nCurrent_Loc, nScreen_type);

    printf("What would you like to Buy?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");
    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n");

    while (*bGame_state) {
        *nQuantity = 0; 
        char key = getch(); 

        switch (key) {
            case '1':
                *nItem = 1;  // Coconut
                printf("How many Coconut(s) would you like to buy? ");
                break;
            case '2':
                *nItem = 2;  // Rice
                printf("How many Rice(s) would you like to buy? ");
                break;
            case '3':
                *nItem = 3;  // Silk
                printf("How many Silk(s) would you like to buy? ");
                break;
            case '4':
                *nItem = 4;  // Gun
                printf("How many Gun(s) would you like to buy? ");
                break;
            case 'x':
            case 'X':
                // Return to main screen, exit loop
                Set_Prices(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity);
                return; 
        }
        scanf("%d", nQuantity);
        if (*nQuantity > 0) {
            printf("Purchase successful!\n");
            Set_Prices(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity);
        }
        
    }
}



void SellScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity) {
    *nScreen_type = 3;
    #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, nCargo, nCurrent_Loc, nScreen_type);

    printf("What would you like to Sell?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");
    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n");

    while (*bGame_state) {
        *nQuantity = 0; 
        char key = getch();

        switch (key) {
            case '1':
                *nItem = 1;  // Coconut
                printf("How many Coconut(s) would you like to sell? ");
                break;
            case '2':
                *nItem = 2;  // Rice
                printf("How many Rice(s) would you like to sell? ");
                break;
            case '3':
                *nItem = 3;  // Silk
                printf("How many Silk(s) would you like to sell? ");
                break;
            case '4':
                *nItem = 4;  // Gun
                printf("How many Gun(s) would you like to sell? ");
                break;
            case 'x':
            case 'X':
                Set_Prices(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut, nSilk, nRice, nGun, nItem, nQuantity);
                continue;
        }
        scanf("%d", nQuantity); 
        if (*nQuantity > 0) {
            Set_Prices(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut, nSilk, nRice, nGun, nItem, nQuantity);
        }
    }
}



// Displays the navigation screen upon pressing [3] Go to Another Port
void DisplayNavigationScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity) {
    *nScreen_type = 4;

    #ifdef _WIN32
        system("cls");
    #endif

    DisplayMenu(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, nCargo, nCurrent_Loc, nScreen_type);
    Travel(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity);
}
