#include <stdio.h>
#include <stdlib.h>
#include "../header/welcome.h" 

// This function displays the welcome message

void Welcome() {
    system("cls");
    printf("\n");

    // Display text in gold
    printf("\033[1;38;5;214m");
    printf("\tWelcome to\n");
    printf("\033[0m");

    // Display text in cyan
    printf("\033[0;36m");
    printf("\t\n"
    " _____ _ __  ___  __    __  ___   __ __  __  __  _ _ _    __  \n"
    "|_   _| | _\\| __/' _/  /__\\| __| |  V  |/  \\|  \\| | | |  /  \\ \n"
    "  | | | | v | _|`._`. | \\/ | _|  | \\_/ | /\\ | | ' | | |_| /\\ |\n"
    "  |_| |_|__/|___|___/  \\__/|_|   |_| |_|_||_|_|\\__|_|___|_||_|\n"
    "\n");
    printf("\033[0m");

    printf("\033[1;38;5;214m");
    printf("\tTo get started, please enter the following \n");
    printf("\033[0m");
    
    printf("\n\n");
}

