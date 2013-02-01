#include <stdio.h>
#include <stdlib.h>

#include "treap.h"

int main() {
    char c;
    int i = 0;
    struct threaded_binary_node * new_tree;
    struct threaded_binary_node * result_node;

    new_tree = new_threaded_binary_head();
    while ( ( c = getchar() ) != EOF ) {
        if ( c == '\n' ) {
            continue;
        }
        insert( new_tree, c, i );
        i++;
    }
    result_node = get_threaded_left_child( new_tree );
    struct treap_data * result_data = result_node->data;
    char result = result_data->value;
    printf( "The first non-repeating character is: \n%c\n", result );
}
