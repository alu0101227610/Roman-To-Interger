#include "romans.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if(argc == 2 ) {
    //When arguments are given.
    int num = atoi(argv[1]);
    if(num > 0) {    
      char *roman = int_to_roman(num);
      printf("%d in roman numerals is %s\n", num, roman);
    } else {
      int integer = roman_to_int(argv[1]);
      printf("%s in integer is %d\n", argv[1], integer);
    }
  } else {
    /*
    If that no arguments are given, I decided to do the optional part.
    In this case, I interpreted the assignment as converting a number to
    roman numeral and back to intergers, I did it one by one for all the 
    numbers between 1 and 3999. I can also be interpreted as converting
    all numbers to romans, and all those roman numerals back to intergers;
    I thought this was not optimal or comfortable for working with memory, 
    especially in C also, I thought it would be hard to read and interpret
    in the console.
    */
    int number;
    for(number = 1; number <= 3999; number++) {
      char *roman = int_to_roman(number);
      int integer = roman_to_int(roman);
      printf("%d in roman numerals is %s\n", integer, roman);
    }
  }
}