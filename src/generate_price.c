#include "../header/common.h"

#include "../header/menu.h"
#include "../header/generate_price.h"

int Generate_Price(int min, int max) {
    return min + rand() % (max - min + 1);
}

void Tondo_Market(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    int coconut_price = Generate_Price(4, 24);
    int rice_price = Generate_Price(1, 20);
    int silk_price = Generate_Price(48, 68);
    int gun_price = Generate_Price(70, 95);

    printf("   Coconut - %2d  Silk - %2d\n", coconut_price, silk_price);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", rice_price, gun_price);
}

void Manila_Market(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    int coconut_price = Generate_Price(3, 18);
    int rice_price = Generate_Price(5, 20);
    int silk_price = Generate_Price(24, 39);
    int gun_price = Generate_Price(65, 84);

    printf("   Coconut - %2d  Silk - %2d\n", coconut_price, silk_price);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", rice_price, gun_price);
}

void Pandakan_Market(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    int coconut_price = Generate_Price(2, 12);
    int rice_price = Generate_Price(4, 14);
    int silk_price = Generate_Price(22, 32);
    int gun_price = Generate_Price(90, 103);

    printf("   Coconut - %2d  Silk - %2d\n", coconut_price, silk_price);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", rice_price, gun_price);
}

void Sapa_Market(int player_code, int initial_capital, int target_profit, int current_profit, int *day, int cargo, char current_location[], char screen_type[], bool *game_state) {
    int coconut_price = Generate_Price(9, 14);
    int rice_price = Generate_Price(1, 6);
    int silk_price = Generate_Price(17, 22);
    int gun_price = Generate_Price(204, 301);

    printf("   Coconut - %2d  Silk - %2d\n", coconut_price, silk_price);
    printf("   Rice    - %2d  Gun  - %2d\n\n\n", rice_price, gun_price);
}
