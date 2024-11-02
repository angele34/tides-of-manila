#include "../header/common.h"

#include "../header/menu.h"
#include "../header/generate_price.h"

MarketPrices prices;

int Generate_Price(int min, int max) {
    return min + rand() % (max - min + 1);
}

void Print_Prices() {
    printf("   Coconut - %2d  Silk - %2d\n", prices.coconut, prices.silk);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", prices.rice, prices.gun);
}

void Tondo_Market() {
    prices.coconut = Generate_Price(4, 24);
    prices.rice = Generate_Price(1, 20);
    prices.silk = Generate_Price(48, 68);
    prices.gun = Generate_Price(70, 95);
}

void Manila_Market() {
    prices.coconut = Generate_Price(3, 18);
    prices.rice = Generate_Price(5, 20);
    prices.silk = Generate_Price(24, 39);
    prices.gun = Generate_Price(65, 84);
}

void Pandakan_Market() {
    prices.coconut = Generate_Price(2, 12);
    prices.rice = Generate_Price(4, 14);
    prices.silk = Generate_Price(22, 32);
    prices.gun = Generate_Price(90, 103);
}

void Sapa_Market() {
    prices.coconut = Generate_Price(9, 14);
    prices.rice = Generate_Price(1, 6);
    prices.silk = Generate_Price(17, 22);
    prices.gun = Generate_Price(204, 301);
}
