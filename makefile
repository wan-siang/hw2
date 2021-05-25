all: Linked_list.h Array.h Array_Binary_Search.h BST.h hash.h hw.c insert_data.c query_data.c basic.h
	gcc insert_data.c -o insert
	gcc query_data.c -o query
	gcc hw.c -o hw
clean:
	rm -f hw
	rm -f query
	rm -f insert
