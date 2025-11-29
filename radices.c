#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// TODO: Add functionality for numbers with fractionals
// TODO: Add functionality for negative numbers
// TODO: Don't end program after calculation finishes or invalid digit entered

// CLEAR TERMINAL
void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// DISPLAY MENU BANNER
void menu_banner() {
    printf(".___         _ _            ._____.        _ _   _ _\n");
    printf("| _ \\__ _ __| (_)__ ___ ___ |_   _|__  ___| | |_(_) |_\n");
    printf("|   / _` / _` | / _/ -_|_-<   | |/ _ \\/ _ \\ | / / |  _|\n");
    printf("|_|_\\__,_\\__,_|_\\__\\___/__/   |_|\\___/\\___/_|_\\_\\_|\\__|\n\n");
}

// DISPLAY MAIN MENU
void display_menu() {
    printf("Welcome to your Radices Toolkit!\n\n");

    // menu options
    printf("1. Decimal to Radices Converter\n");
    printf("2. Radices to Decimal Converter\n");
    printf("3. Radices Calculator\n\n");
}

// RETURN LENGTH OF CHAR ARRAY
int arr_len(char *arr) {
    int len = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        len += 1;
    }
    return len;
}

// CONVERT CHARACTER TO INTEGER
int return_int(char ch) {
    int n = 0;

    if (ch >= '0' && ch <= '9') {
        n = ch - '0';
    } else if (tolower(ch) == 'a') {
        n = 10;
    } else if (tolower(ch) == 'b') {
        n = 11;
    } else if (tolower(ch) == 'c') {
        n = 12;
    } else if (tolower(ch) == 'd') {
        n = 13;
    } else if (tolower(ch) == 'e') {
        n = 14;
    } else if (tolower(ch) == 'f') {
        n = 15;
    } else {
        n = -1;
    }

    return n;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~ DECIMAL TO RADICES CONVERTER ~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void decimal_to_radix() {

    clear();
    menu_banner();
    printf("DECIMAL TO RADICES CONVERTER\n");
    printf("Convert decimal numbers to radices (binary - hexadecimal)!\n\n");

    bool persist = true;

    while(persist) {
        int decimal;
        int radix;

        printf("Enter your number: ");
        scanf("%d", &decimal);

        printf("Enter your radix: ");
        scanf("%d", &radix);

        int exponent_count = 1;
        int num_length = 0;
        for (int i = 0; decimal >= exponent_count; i++) {
            if (decimal >= exponent_count) {
                exponent_count = exponent_count * radix;
                num_length += 1;
            }
        }

        // calculates decimal to radix
        int ans[num_length];

        int dividend = decimal;
        int divisor = radix;
        int temp_decimal = 0;
        int index = 1;
        for (int i = 0; dividend > (radix-1); i++) {
            ans[num_length-index] = dividend % radix;
            dividend = dividend / radix;
            index++;
        }

        ans[num_length-index] = dividend;

        for (int i = 0; i < num_length; i++) {
            printf("%d", ans[i]);
        }
        printf("\n");
        persist = false;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~ RADICES TO DECIMAL CONVERTER ~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void radix_to_decimal() {
    clear();
    menu_banner();
    printf("RADICES TO DECIMAL CONVERTER\n");
    printf("Convert radices (binary - hexadecimal) to decimal!\n\n");

    bool persist = true;

    while(persist) {
        char number[10];
        int radix;

        printf("Enter your radix: ");
        scanf("%d", &radix);

        printf("Enter your base %d number: ", radix);
        scanf("%9s", number);
        int length = arr_len(number);

        // checks for invalid digit symbols, adds to array if valid
        int int_arr[length];
        for (int i = 0; number[i] != '\0'; i++) {
            if (return_int(number[i]) == -1 || return_int(number[i]) >= radix) {
                printf("Digit %c invalid in base %d\n", number[i], radix);
                persist = false;
                break;
            } else {
                int_arr[i] = return_int(number[i]);
            }
        }

        // ends program if invalid digit symbol detected
        if (persist == false) {
            break;
        }

        // calculates decimal version of radix
        int ans = 0;
        int final_arr[length];
        int position = length-1;
        int position_radix = radix;
        for (int i = 0; i < length; i++) {
            if (position == 0) {
                ans += int_arr[i] * 1;
            } else if (position == 1) {
                ans += int_arr[i] * radix;
            } else {
                for (int i = 0; i < position-1; i++) {
                    position_radix = position_radix * radix;
                }
                ans += int_arr[i] * position_radix;
                position_radix = radix;
            }
            position -= 1;
        }

        printf("Your number in decimal: %d\n", ans);
        persist = false;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~ RADICES CALCULATOR ~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
            decimal_to_radix();
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

