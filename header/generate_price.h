#ifndef GENERATE_PRICE_H
#define GENERATE_PRICE_H

int Generate_Price(int min, int max);
void Set_Prices(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *navigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity);
void Buy(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo);
void Sell(int *nQuantity, int *nPrice, int *nInitial_capital, int *nGoods, int *nCargo);

#endif