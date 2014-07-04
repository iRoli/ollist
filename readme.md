# Ollist
Ordered Linked List

The list is ordered from greater to less.

## Usage:

To create a list use the insert function:

    struct node *list = NULL;
    list = insert(list, 15); // 15 is an example of id
    list = insert(list, 3);
    list = insert(list, 6);
	
## Functions

Functions to manipulate the list:

## insert();

Function used to call create_node() and insert_in_order() functions.

## create_node();

Allocates memory for the node and the int id.

## insert_in_order();

Insert a node in greater to less order.

## print_list();

Prints the ids of the list.

## search_by_id();

Search for a node containing the id given.

## delete_list();

Delete the linked list.

## Testing

    $ gcc main.c -o main
    $ ./main