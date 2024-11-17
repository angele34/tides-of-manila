#include "../header/common.h"
#include "../header/check_turns.h"

int Check_Turns(int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *bGame_state) {
    int total_gold = *nInitial_capital + *nCurrent_profit;
    if (*nDay >= 30 || total_gold >= nTarget_profit + *nInitial_capital) {
        *bGame_state = false;
        return 1;
    }
    return 0;
}

