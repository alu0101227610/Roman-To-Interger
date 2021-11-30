# Romans to Intergers, and back
### Author: Antonella Sofia Garcia Alvarez
### Github: www.github.com/alu0101227610
### This repository: https://github.com/alu0101227610/Roman-To-Interger

## How to compile and execute this program.

I'm providing a *Makefile* which will make really easy to compile in a UNIX system. You can go to the directory where the program is and write on command line:

`make` or `make main`

After, we can also write:

`make clean`

To erase all the binaries and object files that we don't need anymore.

Another way to compile this program is using the raw command line with your favorite compiler giving the files _main.c_ and _romans.c_. An example using _gcc_ could be:

```bash
  gcc main.c romans.c -o main
```

## Implementation in C programming language

To start explaining my implementation of the code, I started by creating the files _romans.c_ and _romans.h_. To have a development file, and a header file.

In my header file I, of course, add the libraries that I will need to develop the functions necessary to translate from Roman numerals to Intergers and viceversa.
Next, I declare the two functions I will need and their parameters that will include the type of function they are.

If we go to our *header*(.h) file we have:

```c
char *int_to_roman(int val);
```

As we can see, __char  *int_to_roman__ will set the function as a string value, which has _int val_  that stores an interger value. This means _val_ will always be a number between 1 and 3999, both included.

```c
int roman_to_int(char *numeral);
```

In the next function, we can appreciate that is the opposite of the other, the function will have an interger value and it has a _char_ (string) as a parameter.
As I said in the other function, it is also guaranteed that the numbers will be between 1 and 3999, both included.

To see the development of each function, we have the file _romans.c_:

```c
char *int_to_roman(int val) {
  char *result = "";

  char thousands[4][4] = { "", "M", "MM", "MMM"};
  char hundreds[10][5] = { "",  "C",  "CC",  "CCC",  "CD", "D", "DC", "DCC", "DCCC", "CM"};
  char tens[10][5] = { "",  "X",  "XX",  "XXX",  "XL", "L", "LX", "LXX", "LXXX", "XC"};
  char ones[10][5] = { "",  "I",  "II",  "III",  "IV", "V", "VI", "VII", "VIII", "IX"};

  result = (char *) malloc(15);

  strcat(result, thousands[val / 1000]);
  strcat(result, hundreds[(val % 1000) / 100]);
  strcat(result, tens[(val % 100) / 10]);
  strcat(result, ones[(val % 10)]);
  return result;
```

As it is documented on the file, to translate to the desired numeral, we divide the given number and append that value to the respective "magnitude" with strcat; which is a library that allow us to append two blocks of memory, which is really helpful in this case.

Continuing, we check the roman to int function, on it we go through the char array here checking the current value and the next, if it exists. if the next number is lesser than the current value we add the current value to result and we go on normally. On the contrary, we substract the current value from the next value, and we skip one iteration.

```c
int roman_to_int(char *numeral) {
  int result = 0;

  int numSize = strlen(numeral);
  int i;

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

```

Moving on to out *main*(.c) file, as we see. If arguments are given, numerals or integers it will convert them printing them on the console. If no arguments are given, I implemented the optional part where if you execute the program all the numbers will be translated to roman numerals.

```c
  if(argc == 2 ) {
    int num = atoi(argv[1]);
    if(num > 0) {    
      char *roman = int_to_roman(num);
      printf("%d in roman numerals is %s\n", num, roman);
    } else {
      int integer = roman_to_int(argv[1]);
      printf("%s in integer is %d\n", argv[1], integer);
    }
  } else {
    int number;
    for(number = 1; number <= 3999; number++) {
      char *roman = int_to_roman(number);
      int integer = roman_to_int(roman);
      printf("%d in roman numerals is %s\n", integer, roman);
    }
  }
```

We have this condition where if we get arguments, we will translate our char value to and int value, using _atoi_ and we will of course print it to the user. If no arguments are given, it will just print the number 513 in Roman Numerals.
