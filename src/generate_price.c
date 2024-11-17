#include "../header/common.h"

#include "../header/menu.h"
#include "../header/generate_price.h"

int Generate_Price(int min, int max) {
    return min + rand() % (max - min + 1);
}

void Print_Inventory(int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price) {
    // Display items in cargo
    printf("   Cargo \t%3d of 75\n", *nCargo);
    printf("   =======================\n");
    printf("   Coconut - %2d  Silk - %2d\n", *nCoconut, *nSilk);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", *nRice, *nGun);

    // Display market prices based on location
    printf("   Market Prices\n");
    printf("   =======================\n");
    printf("   Coconut - %2d  Silk - %2d\n", *nCoconut_price, *nSilk_price);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", *nRice_price, *nGun_price);
}

int Buy(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo) {
    int nTotal = *nQuantity * (*nPrice);
    if (*nInitial_capital >= nTotal && *nCargo + *nQuantity <= 75) {
        *nInitial_capital -= nTotal;
        *nCargo += *nQuantity;
        *nGoods += *nQuantity;
        printf("Purchase successful! Returning to Main Screen...\n");
        Sleep(2000); 
        return 1;
    } else if (*nCargo + *nQuantity > 75) {
        printf("Purchase unsuccessful, cargo full. Returning to Main Screen...\n");
        return 0;
    } else if (*nInitial_capital < nTotal) {
        printf("Purchase unsuccessful, insufficient capital. Returning to Main Screen...\n");
        Sleep(2000); 
        return 0;
    }
}

int Sell(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo) {
    int nTotal = *nQuantity * (*nPrice);

    if (*nGoods < *nQuantity) {
        printf("Sale unsuccessful, insufficient quantity. Returning to Main Screen...\n");
        Sleep(2000); 
        return 0;
    } else {
        *nCargo -= *nQuantity;
        *nGoods -= *nQuantity;
        *nInitial_capital += nTotal;
        printf("Sale successful! Returning to Main Screen...");
        Sleep(2000); 
        return 1;
    }
}