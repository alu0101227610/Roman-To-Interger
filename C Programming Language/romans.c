#include "romans.h"

char *int_to_roman(int val) {
  /*
  First it's good practice to check if the number
  given can be represented in roman numerals, but since
  it's guaranteed that the number will be between 1 and 3999, 
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
  int result = 0;

  /*
  To translate the roman numeral to interger we must go through
  the given roman numeral. This way, we can compare the different
  digits and convert them to intergers; Given that the roman numerals
  can add or substract digits of less magnitude.
  */

  int numSize = strlen(numeral);
  int i;

  /* 
  We go through the char array here checking the current value and
  the next, if it exists. if the next number is lesser than the
  current value we add the current value to result and we go on
  normally. On the contrary, we substract the current value from the
  next value, and we skip one iteration.
  */

  for(i = 0; i < numSize; i++) {
    int s1 = value(numeral[i]); 
    if (i + 1 < numSize) {
      int s2 = value(numeral[i+1]);
      if( s1 >= s2){
        result += s1;
      } else {
        result += s2 - s1;
        i++;
      }
    } else {
      result += s1;
    }
  }
  return result;
}

/*
To be able to know the value of each digit in our numeral we create
a function that translate a digit to interger.
*/

int value(char r) {
  switch (r) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return -1;
  } 
}
