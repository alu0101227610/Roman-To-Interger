#include "romans.h"

char *int_to_roman(int val) {
/* C function implementation here */

    /*
    First it'll be a good practice to check if the number
    given can be represented on roman numerals, but since
    it's guarantied that the number is between 1 and 3999, 
    there shouldn't be problem so I'll skip the check.
    */

    char *result = "";

    /*
    An easy way to "build" our roman numeral is to write
    the necesary numbers as we need them since the roman 
    numbers are a limited set.
    */

    char thousands[4][3] = { "", "M", "MM", "MMM",};
    char hundreds[10][4] = { "",  "C",  "CC",  "CCC",  "CD", "D", "DC", "DCC", "DCCC", "CM",};
    char tens[10][4] = { "",  "X",  "XX",  "XXX",  "XL", "L", "LX", "LXX", "LXXX", "XC",};
    char ones[10][4] = { "",  "I",  "II",  "III",  "IV", "V", "VI", "VII", "VIII", "IX",};

    /*
    Now to get the desired numeral we divide the given number 
    and append the corresponding number on the respective magnitudes.
    */

    result = (char *) malloc(15); //We reserve size up to a numeral with 15 digits, the longest it could be.

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

