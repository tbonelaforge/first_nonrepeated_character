#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "list.h"

struct index_frequency {
    int index;
    int frequency;
};

int main() {    
    struct hash * frequency_hash = new_hash();
    char char_string[2] = { ' ', '\0' };
    int number_of_characters = 0;
    int i;
    char c;

    while ( ( c = getchar() ) != EOF ) {
        if ( c == '\n' ) {
            continue;
        }
        char_string[0] = c;
        struct hash * looked_up = hashlookup( frequency_hash, char_string );
        struct index_frequency * data;
        if ( !looked_up ) {
            data = malloc( sizeof( struct index_frequency ) );
            data->index = number_of_characters;
            data->frequency = 0;
            looked_up = add_to_hash( frequency_hash, char_string, (void *) data );
        }
        data = looked_up->data;
        int frequency = data->frequency;
        data->frequency = frequency + 1;
        number_of_characters++;
    }

    struct list * key_list = new_list();
    list_keys_in_hash( frequency_hash, key_list, "" );
    int min_index = number_of_characters + 1;
    char * min_key = "";
    int min_frequency = number_of_characters + 1;
    for ( i = 0; i < key_list->next_index; i++ ) {
        char * key = listlookup( key_list, i );
        struct index_frequency * data;
        data = hashlookup( frequency_hash, key )->data;
        if ( data->frequency < min_frequency ) {
            min_index = data->index;
            min_frequency = data->frequency;
            min_key = key;
        } else if ( data->frequency == min_frequency ) {
            if ( data->index < min_index ) {
                min_index = data->index;
                min_key = key;
            }
        }        
    }
    printf( "The first non-repeated character is: \n%s\n", min_key );

}
