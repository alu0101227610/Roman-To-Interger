#include "romans.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc >= 2 ) {
        //Arguments
        int num = atoi(argv[1]);
        printf("%d in roman numerals is %s\n", num, int_to_roman(num));
    } else {
        //No arguments
        printf("%s\n",int_to_roman(513));
    }

}