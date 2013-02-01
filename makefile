all: threaded hash list first_nonrepeated_char_treap first_nonrepeated_char_hash random_chars

first_nonrepeated_char_treap: first_nonrepeated_char_treap.c threaded/treap.o threaded/threaded_binary_node.o
	gcc -I ./threaded first_nonrepeated_char_treap.c ./threaded/threaded_binary_node.o ./threaded/treap.o -o first_nonrepeated_char_treap

first_nonrepeated_char_hash: first_nonrepeated_char_hash.c
	gcc -I ./hash -I ./list first_nonrepeated_char_hash.c ./hash/hash.o ./hash/charhash.o ./hash/hash_default.o ./list/list.o -o first_nonrepeated_char_hash

random_chars: random_chars.c
	gcc random_chars.c -o random_chars

.PHONY: threaded

threaded:
	cd ./threaded && make

.PHONY: hash

hash:
	cd ./hash && make

.PHONY: list

list:
	cd ./list && make