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

void menu_banner() {
    printf(" _____           _ _                 _______          _ _    _ _\n");
    printf("|  __ \\         | (_)               |__   __|        | | |  (_) |\n");
    printf("| |__) |__ _  __| |_  ___ ___  ___     | | ___   ___ | | | ___| |_\n");
    printf("|  _  // _` |/ _` | |/ __/ _ \\/ __|    | |/ _ \\ / _ \\| | |/ / | __|\n");
    printf("| | \\ \\ (_| | (_| | | (_|  __/\\__ \\    | | (_) | (_) | |   <| | |_\n");
    printf("|_|  \\_\\__._|\\__._|_|\\___\\___||___/    |_|\\___/ \\___/|_|_|\\_\\_|\\__|\n\n");
}

// CONVERT DECIMAL TO RADICES
void decimal_to_radices() {

    clear();
    menu_banner();
    printf("DECIMAL TO RADICES CONVERTER\n");
    printf("Convert Base 10 to any radix from binary to hexadecimal!\n\n");

    bool persist = true;

    while(persist) {
        int decimal_num;

        printf("Enter your number: ");
        scanf("%d", &decimal_num);
        if (decimal_num > 0) {
            persist = false;
        } else {
            persist = false;
        }
    }

    printf("Not yet though!\n");
    printf("Program ending...\n");
}

// CONVERT RADICES TO DECIMAL
void radix_to_decimal() {
    clear();
    menu_banner();
    printf("RADICES TO DECIMAL CONVERTER\n");
    printf("Convert radices from binary to hexadecimal to decimal!\n\n");

    printf("Coming soon...\n");
}

void radices_calculator() {
    clear();
    menu_banner();
    printf("RADICES CALCULATOR\n");
    printf("Add, Subtract or Multiply radices from binary to hexadecimal!\n\n");

    printf("Coming soon...\n");
}

// MAIN FUNCTION FOR MAIN MENU
int main() {
    clear();

    // menu banner
    menu_banner();
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
    } else if (num == 2) {
        radix_to_decimal();
    } else if (num == 3) {
        radices_calculator();
    } else {
        printf("Your number is: %d\n", num);
    }

    return EXIT_SUCCESS;
}

