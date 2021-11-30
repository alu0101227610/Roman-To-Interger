#include "romans.h"

char *int_to_roman(int val) {
    /*
    First it's good practice to check if the number
    given can be represented in roman numerals, but since
    it's guarantied that the number will be between 1 and 3999, 
    this step is not necessary now.
    */

    char *result = "";

    /*
    To create a our first function, we need the roman numeral data.
    As we know, the roman numerals are known and they have a limited
    value list. So I can easily create Strings with the numerals.
    */

    char thousands[4][4] = { "", "M", "MM", "MMM"};
    char hundreds[10][5] = { "",  "C",  "CC",  "CCC",  "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char tens[10][5] = { "",  "X",  "XX",  "XXX",  "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char ones[10][5] = { "",  "I",  "II",  "III",  "IV", "V", "VI", "VII", "VIII", "IX"};

    /*
    To translate to the desired numeral, we divide the given number
    and append that value to the respective "magnitude" with strcat; 
    which is a library that allow us to append two blocks of memory
    */

    result = (char *) malloc(15); //We reserve the length up to a numeral with 15 digits, the longest it can be.

    strcat(result, thousands[val / 1000]);
    strcat(result, hundreds[(val % 1000) / 100]);
    strcat(result, tens[(val % 100) / 10]);
    strcat(result, ones[(val % 10)]);

    return result;
}

int roman_to_int(char *numeral) {
/* C function implementation here */

    /*
    Doing the operation the other way around is not as easy
    */

}

