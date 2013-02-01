#include <stdio.h>
#include <stdlib.h>

int ALPHABET_SIZE = 26;

int main( int argc, char * argv[] ) {
    int number_of_chars = 100;
    if ( argc > 1 ) {
        sscanf( argv[1], "%d", &number_of_chars );
    }
    if ( argc > 2 ) {
        sscanf( argv[2], "%d", &ALPHABET_SIZE );
    }
    int i;
    char c;
    for ( i = 0; i < number_of_chars; i++ ) {
        c = 128 - ALPHABET_SIZE + rand() % ALPHABET_SIZE;
        putchar( c );
    }
}
