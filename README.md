# Romans to Intergers, and back
### Author: Antonella Sofia Garcia Alvarez.
### Github: www.github.com/alu0101227610

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

Moving on to out *main*(.c) file:

```c
    if(argc >= 2 ) {
        //Arguments
        int num = atoi(argv[1]);
        printf("%d in roman numerals is %s\n", num, int_to_roman(num));
    } else {
        //No arguments
        printf("%s\n",int_to_roman(513));
    }
```

We have this condition where if we get arguments, we will translate our char value to and int value, using _atoi_ and we will of course print it to the user. If no arguments are given, it will just print the number 513 in Roman Numerals.
