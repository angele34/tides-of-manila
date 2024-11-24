#include "../header/common.h"

// Import user-defined libraries
#include "../header/generate_price.h" 
#include "../header/location.h"
#include "../header/menu.h"
#include "../header/check_turns.h"
#include "../header/clear_screen.h"

// @param total = 8
/*
This function displays the data and current progress of the player throughout the game
Precondition: Game has not yet ended
@param nPlayer_code is the code inputted by the player at the beginning of the game
@param nInitial_capital is the amount of gold coins the player initially inputted and starts with
@param nTarget_profit is the amount of profit set by the player and one of the goals to reach to win the game
@param nDay increments once the player travels to another port
@param nCurrent_profit displays the current profit the player has gained through selling goods
@param nCargo is the overall amount of goods the player has bought
@param nScreen_type labelled from 1-4 is used to keep track on which Screen the user is in, dynamically displaying it
@param nCash is the value of the initial capital entered by the player used to calculate the profit 
@return None
*/
void DisplayMenu(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, int *nCargo, int *nCurrent_Loc, int *nScreen_type, int nCash)
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
    *nCurrent_profit = *nInitial_capital - nCash;
    printf(" \t\t\t Profit: %5d/%d%%\n", *nInitial_capital, *nCurrent_profit);
    printf("Day %d\n\n\n\n", *nDay);
}

// @param total = 20
/*
This function displays the default screen upon starting the game, displaying options for the player to choose
Precondition: Game has not yet ended
@param nPlayer_code is the code inputted by the player at the beginning of the game
@param nInitial_capital is the amount of gold coins the player initially inputted and starts with
@param nTarget_profit is the amount of profit set by the player and one of the goals to reach to win the game
@param nDay increments once the player travels to another port
@param nCurrent_profit displays the current profit the player has gained through selling goods
@param bNavigated checks if the player has successfully travelled to another port
@param bGame_state checks if the game has not yet ended
@param nScreen_type ranges from 1-4 is used to keep track on which Screen the user is in, dynamically displaying it
@param nCargo is the overall amount of goods the player has bought
@param nCoconut shows the amount of Coconut the player currently has in cargo
@param nSilk shows the amount of Silk the player currently has in cargo
@param nRice shows the amount of Rice the player currently has in cargo
@param nGun shows the amount of Gun the player currently has in cargo
@param nItem ranges 1-4 is used to keep track of the item player is buying/selling
@param nQuantity takes the quantity the player wants to buy/sell
@param nCoconut_price stores a randomly generated value from Generate_Price based on the current location
@param nSilk_price stores a randomly generated value from Generate_Price based on the current location
@param nRice_price stores a randomly generated value from Generate_Price based on the current location
@param nGun_price stores a randomly generated value from Generate_Price based on the current location
@param nCash is the value of the initial capital entered by the player used to calculate the profit 
@return None
*/
void Main_Screen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, 
bool *bNavigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, 
int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity, int *nCoconut_price, int *nSilk_price,
int *nRice_price, int *nGun_price, int nCash) 
{
    Clear();
    // Sets the screen type
    *nScreen_type = 1;
    DisplayMenu(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, nCargo, nCurrent_Loc, nScreen_type, nCash);
    if (Check_Turns(nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bGame_state)) return;

    printf("What would you like to do?\n");
    printf("%*s%s", 4, "", "[1] Buy\n");
    printf("%*s%s", 4, "", "[2] Sell\n");
    printf("%*s%s", 4, "", "[3] Go to Another Port\n\n");
    printf("%*s%s", 4, "", "[Q] Quit\n\n\n");

    Print_Inventory(nCargo, nCoconut, nSilk, nRice, nGun, nCoconut_price, nSilk_price, nRice_price, nGun_price);

    // Handle the user cKey press input while the game is still running
    while (*bGame_state) {
        char cKey;
        do {
            scanf(" %c", &cKey);
            if (cKey != '1' && cKey != '2' && cKey != '3' && cKey != 'q' && cKey != 'Q') {
                printf("Please enter a valid key\n");
            }
        } while (cKey != '1' && cKey != '2' && cKey != '3' && cKey != 'q' && cKey != 'Q');
        switch(cKey) {
            case '1':
                BuyScreen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                break;
            case '2':
                SellScreen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut, nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                break;
            case '3':
                DisplayNavigationScreen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                break;
            case 'q': 
            case 'Q':
                *bGame_state = false;  
                break;
        }
    }
}
// @param total = 20
/*
This function displays Buy Screen screen upon pressing [1] Buy
Precondition: Game has not yet ended
@param nPlayer_code is the code inputted by the player at the beginning of the game
@param nInitial_capital is the amount of gold coins the player initially inputted and starts with
@param nTarget_profit is the amount of profit set by the player and one of the goals to reach to win the game
@param nDay increments once the player travels to another port
@param nCurrent_profit displays the current profit the player has gained through selling goods
@param bNavigated checks if the player has successfully travelled to another port
@param bGame_state checks if the game has not yet ended
@param nScreen_type ranges from 1-4 is used to keep track on which Screen the user is in, dynamically displaying it
@param nCargo is the overall amount of goods the player has bought
@param nCoconut shows the amount of Coconut the player currently has in cargo
@param nSilk shows the amount of Silk the player currently has in cargo
@param nRice shows the amount of Rice the player currently has in cargo
@param nGun shows the amount of Gun the player currently has in cargo
@param nItem ranges 1-4 is used to keep track of the item player is buying/selling
@param nQuantity takes the quantity the player wants to buy/sell
@param nCoconut_price stores a randomly generated value from Generate_Price based on the current location
@param nSilk_price stores a randomly generated value from Generate_Price based on the current location
@param nRice_price stores a randomly generated value from Generate_Price based on the current location
@param nGun_price stores a randomly generated value from Generate_Price based on the current location
@param nCash is the value of the initial capital entered by the player used to calculate the profit 
@return None
*/
void BuyScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *bNavigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price, int nCash) {
    Clear();
    *nScreen_type = 2;
    DisplayMenu(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, nCargo, nCurrent_Loc, nScreen_type, nCash);
    Print_Inventory(nCargo, nCoconut, nSilk, nRice, nGun, nCoconut_price, nSilk_price, nRice_price, nGun_price);

    printf("What would you like to Buy?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");
    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n");

    while (*bGame_state) {
        *nQuantity = 0; 
        char cKey;
        do {
            scanf(" %c", &cKey);
            if (cKey != '1' && cKey != '2' && cKey != '3' && cKey != '4' && cKey != 'x' && cKey != 'X') {
                printf("Please enter a valid key\n");
            }
        } while (cKey != '1' && cKey != '2' && cKey != '3' && cKey != '4' && cKey != 'x' && cKey != 'X');

        switch (cKey) {
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
                Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                break;
        }
        scanf("%d", nQuantity);
        if (*nQuantity > 0) {
            switch (*nItem) 
                {
                    case 1: // Coconut
                        Buy(nQuantity, nCoconut_price, nInitial_capital, nCoconut, nCargo);
                        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                        break;
                    case 2: // Silk
                        Buy(nQuantity, nRice_price, nInitial_capital, nRice, nCargo);
                        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                        break;
                    case 3: // Rice
                        Buy(nQuantity, nSilk_price, nInitial_capital, nSilk, nCargo);
                        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                        break;
                    case 4: // Gun
                        Buy(nQuantity, nGun_price, nInitial_capital, nGun, nCargo);
                        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                        break; 
                } 
            }
    }
}

// @param total = 20
/*
This function displays Sell Screen screen upon pressing [2] Buy
Precondition: Game has not yet ended
@param nPlayer_code is the code inputted by the player at the beginning of the game
@param nInitial_capital is the amount of gold coins the player initially inputted and starts with
@param nTarget_profit is the amount of profit set by the player and one of the goals to reach to win the game
@param nDay increments once the player travels to another port
@param nCurrent_profit displays the current profit the player has gained through selling goods
@param bNavigated checks if the player has successfully travelled to another port
@param bGame_state checks if the game has not yet ended
@param nScreen_type ranges from 1-4 is used to keep track on which Screen the user is in, dynamically displaying it
@param nCargo is the overall amount of goods the player has bought
@param nCoconut shows the amount of Coconut the player currently has in cargo
@param nSilk shows the amount of Silk the player currently has in cargo
@param nRice shows the amount of Rice the player currently has in cargo
@param nGun shows the amount of Gun the player currently has in cargo
@param nItem ranges 1-4 is used to keep track of the item player is buying/selling
@param nQuantity takes the quantity the player wants to buy/sell
@param nCoconut_price stores a randomly generated value from Generate_Price based on the current location
@param nSilk_price stores a randomly generated value from Generate_Price based on the current location
@param nRice_price stores a randomly generated value from Generate_Price based on the current location
@param nGun_price stores a randomly generated value from Generate_Price based on the current location
@param nCash is the value of the initial capital entered by the player used to calculate the profit 
@return None
*/

void SellScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *bNavigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price, int nCash) {
    Clear();
    *nScreen_type = 3;

    DisplayMenu(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, nCargo, nCurrent_Loc, nScreen_type, nCash);
    Print_Inventory(nCargo, nCoconut, nSilk, nRice, nGun, nCoconut_price, nSilk_price, nRice_price, nGun_price);

    printf("What would you like to Sell?\n");
    printf("%*s%s", 2, "", "[1] Coconut\n");
    printf("%*s%s", 2, "", "[2] Rice\n");
    printf("%*s%s", 2, "", "[3] Silk\n");
    printf("%*s%s", 2, "", "[4] Gun\n\n\n");
    printf("%*s%s", 2, "", "[X] Return to the Main Screen\n");

    while (*bGame_state) {
        *nQuantity = 0; 
        char cKey;
        do {
            scanf(" %c", &cKey);
            if (cKey != '1' && cKey != '2' && cKey != '3' && cKey != '4' && cKey != 'x' && cKey != 'X') {
                printf("Please enter a valid key\n");
            }
        } while (cKey != '1' && cKey != '2' && cKey != '3' && cKey != '4' && cKey != 'x' && cKey != 'X');

        switch (cKey) {
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
                Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut, nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                break;
        }
        scanf("%d", nQuantity); 
        if (*nQuantity > 0) {
            switch (*nItem) 
                {
                    case 1: // Coconut
                        Sell(nQuantity, nCoconut_price, nInitial_capital, nCoconut, nCargo);
                        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                        break;
                    case 2: // Silk
                        Sell(nQuantity, nRice_price, nInitial_capital, nRice, nCargo);
                        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                        break;
                    case 3: // Rice
                        Sell(nQuantity, nSilk_price, nInitial_capital, nSilk, nCargo);
                        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                        break;
                    case 4: // Gun
                        Sell(nQuantity, nGun_price, nInitial_capital, nGun, nCargo);
                        Main_Screen(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
                        break; 
                } 
        }
    }
}
 
// @param total = 20
/*
This function displays Navigation screen upon pressing [3] Go to Another Port
Precondition: Game has not yet ended
@param nPlayer_code is the code inputted by the player at the beginning of the game
@param nInitial_capital is the amount of gold coins the player initially inputted and starts with
@param nTarget_profit is the amount of profit set by the player and one of the goals to reach to win the game
@param nDay increments once the player travels to another port
@param nCurrent_profit displays the current profit the player has gained through selling goods
@param bNavigated checks if the player has successfully travelled to another port
@param bGame_state checks if the game has not yet ended
@param nScreen_type ranges from 1-4 is used to keep track on which Screen the user is in, dynamically displaying it
@param nCargo is the overall amount of goods the player has bought
@param nCoconut shows the amount of Coconut the player currently has in cargo
@param nSilk shows the amount of Silk the player currently has in cargo
@param nRice shows the amount of Rice the player currently has in cargo
@param nGun shows the amount of Gun the player currently has in cargo
@param nItem ranges 1-4 is used to keep track of the item player is buying/selling
@param nQuantity takes the quantity the player wants to buy/sell
@param nCoconut_price stores a randomly generated value from Generate_Price based on the current location
@param nSilk_price stores a randomly generated value from Generate_Price based on the current location
@param nRice_price stores a randomly generated value from Generate_Price based on the current location
@param nGun_price stores a randomly generated value from Generate_Price based on the current location
@param nCash is the value of the initial capital entered by the player used to calculate the profit 
@return None
*/
void DisplayNavigationScreen(int nPlayer_code, int *nInitial_capital, int nTarget_profit, int *nDay, int *nCurrent_profit, bool *bNavigated, bool *bGame_state, int *nCurrent_Loc, int *nScreen_type, int *nCargo, int *nCoconut, int *nSilk, int *nRice, int *nGun, int *nItem, int *nQuantity, int *nCoconut_price, int *nSilk_price, int *nRice_price, int *nGun_price, int nCash) {
    Clear();
    *nScreen_type = 4;
    DisplayMenu(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, nCargo, nCurrent_Loc, nScreen_type, nCash);
    Travel(nPlayer_code, nInitial_capital, nTarget_profit, nDay, nCurrent_profit, bNavigated, bGame_state, nCurrent_Loc, nScreen_type, nCargo, nCoconut,nSilk, nRice, nGun, nItem, nQuantity, nCoconut_price, nSilk_price, nRice_price, nGun_price, nCash);
}
