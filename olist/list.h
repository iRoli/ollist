#ifndef LIST_H
#define LIST_H
/*	Author: Bryan (Roli)
 *	mail: roli@cock.li
 *	Last updated: 3/July/2014
 *	License: None.
 */

/* struct, modify this to add more data types and make it useful */
struct node {int *id_member; struct node *next;};

/* prototypes */
struct node *create_node(int id);
struct node *insert_in_order(struct node *list, struct node *new_node);
struct node *insert(struct node *list, int id);
void print_list(const struct node *list);
struct node *search_by_id(struct node *list, int id);
void *delete_list(struct node *list);

/* Include the definitions of functions at last, because this file need to see the prototype of the structs */
#include "list.c"
#endif /* ->> LIST_H */
