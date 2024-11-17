#include "../header/common.h"

#include "../header/menu.h"
#include "../header/generate_price.h"

int Generate_Price(int min, int max) {
    return min + rand() % (max - min + 1);
}

void Set_Prices(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity) 
{
    #ifdef _WIN32
        system("cls");
    #endif
    *nScreen_type = 1;
    
    int nCoconut_price, nSilk_price, nRice_price, nGun_price;

    // Randomly generate prices everytime the user travels to another port
    if (!*navigated) {
        switch(*nCurrent_Loc) {
            case 1: // Manila
                nCoconut_price = Generate_Price(3, 18);
                nSilk_price = Generate_Price(5, 20);
                nRice_price = Generate_Price(24, 39);
                nGun_price = Generate_Price(65, 84);
                break;
            case 2: // Tondo:
                nCoconut_price = Generate_Price(4, 24);
                nSilk_price = Generate_Price(1, 20);
                nRice_price = Generate_Price(48, 68);
                nGun_price = Generate_Price(70, 95);
                break;
            case 3: // Pandakan
                nCoconut_price = Generate_Price(2, 12);
                nSilk_price = Generate_Price(4, 14);
                nRice_price = Generate_Price(22, 32);
                nGun_price = Generate_Price(90, 103);
                break;
            case 4: // Sapa:
                nCoconut_price = Generate_Price(9, 14);
                nSilk_price = Generate_Price(1, 6);
                nRice_price = Generate_Price(17, 22);
                nGun_price = Generate_Price(204, 301);
                break;
        }
    }

    // Display options
    DisplayMenu(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, nCargo, nCurrent_Loc, nScreen_type);

    printf("What would you like to do?\n");
    printf("%*s%s", 4, "", "[1] Buy\n");
    printf("%*s%s", 4, "", "[2] Sell\n");
    printf("%*s%s", 4, "", "[3] Go to Another Port\n\n");
    printf("%*s%s", 4, "", "[Q] Quit\n\n\n");

     // Display items in cargo
    printf("   Cargo \t%3d of 75\n", *nCargo);
    printf("   =======================\n");
    printf("   Coconut - %2d  Silk - %2d\n", *nCoconut, *nSilk);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", *nRice, *nGun);

    // Display market prices based on location
    printf("   Market Prices\n");
    printf("   =======================\n");
    printf("   Coconut - %2d  Silk - %2d\n", nCoconut_price, nSilk_price);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", nRice_price, nGun_price);

    // Handle the user key press input while the game is still running
    while (*bGame_state) {
        char key = getch();
        switch(key) {
            case '1':
                BuyScreen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity);
                switch (*nItem) 
                {
                    case 1: // Coconut
                        Buy(nQuantity, &nCoconut_price, nInitial_capital, nCoconut, nCargo);
                        break;
                    case 2: // Silk
                        Buy(nQuantity, &nSilk_price, nInitial_capital, nSilk, nCargo);
                        break;
                    case 3: // Rice
                        Buy(nQuantity, &nRice_price, nInitial_capital, nRice, nCargo);
                        break;
                    case 4: // Gun
                        Buy(nQuantity, &nGun_price, nInitial_capital, nGun, nCargo);
                        break; 
                } 
                break;
            case '2':
                SellScreen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut, nSilk, nRice, nGun, nItem, nQuantity);
                switch (*nItem) 
                {
                    case 1: // Coconut
                        Sell(nQuantity, &nCoconut_price, nInitial_capital, nCoconut, nCargo);
                        break;
                    case 2: // Silk
                        Sell(nQuantity, &nSilk_price, nInitial_capital, nSilk, nCargo);
                        break;
                    case 3: // Rice
                        Sell(nQuantity, &nRice_price, nInitial_capital, nRice, nCargo);
                        break;
                    case 4: // Gun
                        Sell(nQuantity, &nGun_price, nInitial_capital, nGun, nCargo);
                        break; 
                } 
                break;
            case '3':
                DisplayNavigationScreen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, navigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity);
                break;
            case 'q': 
            case 'Q':
                *bGame_state = false;  
                break;
        }
    }
}

void Buy(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo) {
    int nTotal = *nQuantity * (*nPrice);
    
    if (*nInitial_capital >= nTotal && *nCargo + *nQuantity <= 75) {
        *nInitial_capital -= nTotal;
        *nCargo += *nQuantity;
        *nGoods += *nQuantity;
    } else if (*nCargo + *nQuantity > 75) {
        printf("Purchase unsuccessful, cargo full.");
    } else if (*nInitial_capital < nTotal) {
        printf("Purchase unsuccessful, insufficient capital");
    }
}

void Sell(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo) {
    int nTotal = *nQuantity * (*nPrice);

    if (*nGoods < *nQuantity) {
        printf("Sale unsuccessful, insufficient quantity.\n");
    } else {
        printf("Sale successful!");
        *nCargo -= *nQuantity;
        *nGoods -= *nQuantity;
        *nInitial_capital += nTotal;
    }
}