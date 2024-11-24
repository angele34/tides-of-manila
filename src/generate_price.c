#include "../header/common.h"

#include "../header/menu.h"
#include "../header/generate_price.h"

/*
This function randomly generates prices
@param min takes the minimum number to be generated when the function is called
@param max takes the maximum number to be generated when the function is called
@return randomly generated value ranging from min to max
*/

int Generate_Price(int min, int max) {
    return min + rand() % (max - min + 1);
}

/*
This function displays the items in cargo and the market prices of the products
@param nCargo is the overall amount of goods the player has bought
@param nCoconut shows the amount of Coconut the player currently has in cargo
@param nSilk shows the amount of Silk the player currently has in cargo
@param nRice shows the amount of Rice the player currently has in cargo
@param nGun shows the amount of Gun the player currently has in cargo
@param nQuantity takes the quantity the player wants to buy/sell
@param nCoconut_price stores a randomly generated value from Generate_Price based on the current location
@param nSilk_price stores a randomly generated value from Generate_Price based on the current location
@param nRice_price stores a randomly generated value from Generate_Price based on the current location
@param nGun_price stores a randomly generated value from Generate_Price based on the current location
@return None
*/

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
/*
This function handles the buying logic
@param nQuantity takes the quantity the player wants to buy/sell
@param nPrice takes the generated price from nCoconut, nRice, nSilk, and nGun
@param nInitial_capital is the amount of gold coins the player has, is deducted when the player purchases something
@param nGoods takes the items nCoconut, nRice, nSilk, nGun and adds to their quantity in cargo
@param cargo is incremented with nQuantity
*/
void Buy(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo) {
    int nTotal = *nQuantity * (*nPrice);
    if (*nInitial_capital >= nTotal && *nCargo + *nQuantity <= 75) {
        *nInitial_capital -= nTotal;
        *nCargo += *nQuantity;
        *nGoods += *nQuantity;
        printf("Purchase successful! Returning to Main Screen...\n");
    } else if (*nCargo + *nQuantity > 75) {
        printf("Purchase unsuccessful, cargo full. Returning to Main Screen...\n");
    } else if (*nInitial_capital < nTotal) {
        printf("Purchase unsuccessful, insufficient capital. Returning to Main Screen...\n");
    }
}

/*
This function handles the selling logic
@param nQuantity takes the quantity the player wants to buy/sell
@param nPrice takes the generated price from nCoconut_price, nRice_price, nSilk_price, and nGun_price
@param nInitial_capital is the amount of gold coins the player has, is deducted when the player purchases something
@param nGoods takes the items nCoconut, nRice, nSilk, nGun and adds to their quantity in cargo
@param cargo is incremented with nQuantity
*/

void Sell(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo) {
    int nTotal = *nQuantity * (*nPrice);
    if (*nGoods < *nQuantity) {
        printf("Sale unsuccessful, insufficient quantity. Returning to Main Screen...\n");
    } else {
        *nCargo -= *nQuantity;
        *nGoods -= *nQuantity;
        *nInitial_capital += nTotal;
        printf("Sale successful! Returning to Main Screen...");
    }
}