#ifndef GENERATE_PRICE_H
#define GENERATE_PRICE_H

int Generate_Price(int min, int max);
void Print_Inventory(int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price);
int Buy(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo);
int Sell(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo);

#endif