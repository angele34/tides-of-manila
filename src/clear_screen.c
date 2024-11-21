#include "../header/common.h"
#include "../header/clear_screen.h"

void Clear() {
    printf("\033[H");
    printf("\033[J");
}