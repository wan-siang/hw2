all: Linked_list.c Linked_list.h Array.h Array.c Array_Binary_Search.h Array_Binary_Search.c BST.h BST.c hash.h hash.c hw.c insert_data.c query_data.c basic.h
	gcc insert_data.c -o insert
	gcc query_data.c -o query
	gcc -c Array.c
	gcc -c Linked_list.c
	gcc -c Array_Binary_Search.c
	gcc -c hash.c
	gcc -c BST.c
	gcc hw.c -o hw
clean:
	rm -f hw
	rm -f query
	rm -f insert
