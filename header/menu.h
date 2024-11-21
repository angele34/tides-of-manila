#ifndef MENU_H
#define MENU_H

void DisplayMenu(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, int *nCargo, int *nCurrent_Loc, int *nScreen_type, int nCash);
void Main_Screen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *bNavigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price, int nCash);
void BuyScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *bNavigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price, int nCash);
void SellScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *bNavigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price, int nCash);
void DisplayNavigationScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *bNavigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price, int nCash);

#endif
