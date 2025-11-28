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
    printf(" ___         _ _             _____         _ _   _ _\n");
    printf("| _ \\__ _ __| (_)__ ___ ___ |_   _|__  ___| | |_(_) |_\n");
    printf("|   / _` / _` | / _/ -_|_-<   | |/ _ \\/ _ \\ | / / |  _|\n");
    printf("|_|_\\__,_\\__,_|_\\__\\___/__/   |_|\\___/\\___/_|_\\_\\_|\\__|\n\n");
}

void display_menu() {
    printf("Welcome to your Radices Toolkit!\n\n");

    // menu options
    printf("1. Decimal to Radices Converter\n");
    printf("2. Radices to Decimal Converter\n");
    printf("3. Radices Calculator\n\n");
}

/*
// FIND LENGTH OF ARRAY
int length(char* arr) {
    int len = sizeof(arr) / sizeof(arr[0]);

    return len;
}
*/

int return_int(char ch) {
    int n = 0;

    if (ch >= '0' && ch <= '9') {
        n = ch - '0';
    }

    return n;
}

// DECIMAL TO RADICES CONVERTER
void decimal_to_radices() {

    clear();
    menu_banner();
    printf("DECIMAL TO RADICES CONVERTER\n");
    printf("Convert decimal numbers to radices (binary - hexadecimal)!\n\n");

    bool persist = true;

    while(persist) {
        char decimal[10];
        char radix[2];

        printf("Enter your number: ");
        scanf("%9s", decimal);

        printf("Enter your radix: ");
        scanf("%1s", radix);

        int len = 0;
        for (int i = 0; decimal[i] != '\0'; i++) {
            len += 1;
        }

        printf("len: %d\n", len);

        int int_arr[len];
        for (int i = 0; decimal[i] != '\0'; i++) {
            int_arr[i] = return_int(decimal[i]);
        }

        for (int i = 0; i < len; i++) {
            printf("%d\n", int_arr[i]);
        }

        persist = false;
    }

    printf("Coming soon! Program ending...\n");
}

// RADICES TO DECIMAL CONVERTER
void radix_to_decimal() {
    clear();
    menu_banner();
    printf("RADICES TO DECIMAL CONVERTER\n");
    printf("Convert radices (binary - hexadecimal) to decimal!\n\n");

    bool persist = true;
    while (persist) {
        int radix;
        printf("Choose Radix: ");
        scanf("%d", &radix);

        int radix_num;
        printf("Enter number in base %d: ", radix);
        scanf("%d", &radix_num);
        if (radix_num > 0) {
            persist = false;
        } else {
            persist = false;
        }
    }

    printf("Coming soon! Program ending...\n");
}

// RADICES CALCULATOR
void radices_calculator() {
    clear();
    menu_banner();
    printf("RADICES CALCULATOR\n");
    printf("Add, Subtract or Multiply radices from binary to hexadecimal!\n\n");

    bool persist = true;
    while (persist) {
        int radix;
        printf("Choose your radix: ");
        scanf("%d", &radix);

        int radix_num1;
        printf("Enter your first number in base %d: ", radix);
        scanf("%d", &radix_num1);

        char op;
        printf("Enter your operator (*, + or -): ");
        scanf(" %c", &op);

        int radix_num2;
        printf("Enter your second number in base %d: ", radix);
        scanf("%d", &radix_num2);

        persist = false;
    }

    printf("Thank you, calculator coming soon...\n");
}

// MAIN MENU
int main() {

    // menu functionality
    bool menu_persist = true;
    bool run_menu = true;
    while (menu_persist) {
        if (run_menu) {
            clear();
            menu_banner();
            display_menu();
        } else {
            clear();
            menu_banner();
            display_menu();
            printf("Incorrect choice\n");
        }
        char choice[16];
        printf("Choose your tool (1-3): ");
        scanf("%15s", choice);
        if (strcmp(choice, "1") == 0) {
            decimal_to_radices();
            menu_persist = false;
        } else if (strcmp(choice, "2") == 0) {
            radix_to_decimal();
            menu_persist = false;
        } else if (strcmp(choice, "3") == 0) {
            radices_calculator();
            menu_persist = false;
        } else if (strcmp(choice, "exit") == 0) {
            return EXIT_SUCCESS;
        } else {
            run_menu = false;
            printf("test\n");
        }
    }

    return EXIT_SUCCESS;
}

