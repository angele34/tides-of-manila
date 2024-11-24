#include "../header/common.h"
#include "../header/clear_screen.h"

// This function clears the screen using ANSI escape sequences

void Clear() {
    printf("\033[H");
    printf("\033[J");
}