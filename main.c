/*
 *  main.c
 *  Ordered linked list.
 */
#include <stdio.h>
#include <stdlib.h>

// Turn on Debugging, used for checking that we freed the list and the int values.
#define DEBUG
// Turn off Debugging
/*#undef DEBUG*/

#include "olist/list.h"

int main(void)
{
	/* This is the list, don't modify it by doing this: list = list->next, instead create an alias.
	   Because you don't want lose some nodes */
	struct node *list = NULL;
	struct node *alias_list = NULL; // Alias for the list
	int array[] = {327, 4810, 1, 382, 892, 298, 238, 982, 12673, 37229, 3133, 8391};
	int size = sizeof(array) / sizeof(array[0]);
	int i;

	/* Create some nodes */
	for (i = 0; i < size; i++)
	{
		list = insert(list, array[i]);
	}
	
	// Alias
	alias_list = list;
	
	/* Print the list */
	print_list(list);
	
	/* Search for an id */
	if ((alias_list = search_by_id(list, 982)))
	{
		printf("Node found.\n");
		printf("Value of node: %d\n", *alias_list->id_member);
	} else
	{
		printf("Node not found.\n");
	}
	
	/* Delete the list */
	list = delete_list(list);
	
	exit(EXIT_SUCCESS);
}
