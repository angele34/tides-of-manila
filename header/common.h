#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>

typedef struct {
    int player_code;
    int initial_capital;
    int target_profit;
} PlayerData;

typedef struct {
    int day;
    int current_profit;
    int cargo;
} PlayerProgress;

typedef struct {
    int coconut;
    int silk;
    int rice;
    int gun;
} Goods;

extern Goods inventory;

typedef struct {
    int coconut;
    int rice;
    int silk;
    int gun;
} MarketPrices;

extern MarketPrices prices;

#endif