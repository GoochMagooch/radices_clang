#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// CLEAR TERMINAL
void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// CONVERT DECIMAL TO RADICES
void decimal_to_radices() {

    clear();
    printf("This tool will allow you to convert any decimal number \n");
    printf("(base 10) into any radix from binary to hexadecimal!\n\n");

    bool test = true;

    while(test) {
        int test_num = 1;

        printf("Enter another number: ");
        scanf("%d", &test_num);
        if (test_num >= 1) {
            test = true;
        } else {
            test = false;
        }
    }
    printf("Program ending...\n");
}

// MAIN FUNCTION FOR MAIN MENU
int main() {
    clear();

    // menu banner
    printf(" _____           _ _                 _______          _ _    _ _\n");
    printf("|  __ \\         | (_)               |__   __|        | | |  (_) |\n");
    printf("| |__) |__ _  __| |_  ___ ___  ___     | | ___   ___ | | | ___| |_\n");
    printf("|  _  // _` |/ _` | |/ __/ _ \\/ __|    | |/ _ \\ / _ \\| | |/ / | __|\n");
    printf("| | \\ \\ (_| | (_| | | (_|  __/\\__ \\    | | (_) | (_) | |   <| | |_\n");
    printf("|_|  \\_\\__._|\\__._|_|\\___\\___||___/    |_|\\___/ \\___/|_|_|\\_\\_|\\__|\n\n");
    printf("Welcome to your Radices Toolkit!\n");
    printf("Choose a tool to use...\n\n");

    // menu options
    printf("1. Decimal to Radices Converter\n");
    printf("2. Radices to Decimal Converter\n");
    printf("3. Radices Calculator\n\n");

    // menu functionality
    int num;
    printf("Choose your option: ");
    scanf("%d", &num);
    if (num == 1) {
        decimal_to_radices();
    } else {
        printf("Your number is: %d\n", num);
    }

    return EXIT_SUCCESS;
}

