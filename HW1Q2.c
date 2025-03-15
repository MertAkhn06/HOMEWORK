#include <stdio.h>


/* function main begins program execution */
/*int main( void )
{
    int integer1  |in this line ; is missing at the end
//    int integer2 |in this line ; is missing at the end
//    int x;      /* variable in which sum will be stored */

//    printf( Enter first integer\n ); |in this line the string is not between " ".
//   scanf( "%d", &integer1 );

//    printf( "Enter second integer\n" );
//    scanf( "%d", &integer2 );

//    sum = integer1 + integer2; |sum is not defined in the function.We can exchange it with x.

//    printf( "Sum is %d\n", sum ); |sum is not defined in the function.We can exchange it with x.
//    return 0;

//} the corrected function is written down.


/* function main begins program execution */
int main( void )
{
    int integer1; /* first number to be input by user  */
    int integer2; /* second number to be input by user */
    int x;      /* variable in which sum will be stored */

    printf( "Enter first integer\n "); /* prompt */
    scanf( "%d", &integer1 );        /* read an integer */

    printf( "Enter second integer\n" ); /* prompt */
    scanf( "%d", &integer2 );           /* read an integer */

    x = integer1 + integer2; /* assign total to sum */

    printf( "Sum is %d\n", x ); /* print sum */
    return 0; /* indicate that program ended successfully */

}

