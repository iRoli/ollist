#ifndef LIST_C
#define LIST_C
/*	Author: Bryan (Roli)
 *	mail: roli@cock.li
 *	Last updated: 3/July/2014
 *	License: None.
 */

/*	definition of create_node
 *	Description: Allocates memory for the new node and the id.
 *	Parameters: An id for the list.
 *	Returns: A pointer to the node allocated.
 */
struct node *create_node(int id)
{
	struct node *newnode;
	
	// Allocate memoy for the node
	if ((newnode = malloc(sizeof(struct node))) == NULL)
	{
		printf("Error: malloc failed at allocating memory for the node.\n");
		exit(EXIT_FAILURE);
	}
	
	// Allocate memory of the int id
	if ((newnode->id_member = malloc(sizeof(int))) == NULL)
	{
		printf("Error: malloc failed at allocating memory for the int value.\n");
		exit(EXIT_FAILURE);
	}
	
	// Copy the int to the newnode
	*newnode->id_member = id;
	
	return newnode;
}

/*	definition of insert_in_order
 *	Description: Insert a node in order, the list is ordered from greater to less. Allows to insert duplicated id's.
 *	Parameters: A pointer to the list an a pointer to the node being inserted.
 *	Returns: A pointer to the top of the list.
 */
struct node *insert_in_order(struct node *list, struct node *new_node)
{
	/* declarations goes here :^) */
	struct node *current = list; // Alias for list
	struct node *next_of_current; // Next node of current
	struct node *lowest = NULL; // Smallest value encountered on the list to insert between.
	
	
	/* The newnode is the first on the list */
	if (list == NULL)
	{
		new_node->next = list;
		return new_node;
	}
	
	/* There's value(s) greater than the one we're gonna insert */
	while (current != NULL)
	{
		if (*new_node->id_member <= *current->id_member)
		{
			lowest = current;
		}
		current = current->next;
	}
	/* Since there was a greater id_member on the list, make point the little greatest  */
	if (lowest != NULL)
	{
		new_node->next = lowest->next;
		lowest->next = new_node;
		return list;
	}
	
	// The node being inserted has greater id than all of the id's on the list
	if (lowest == NULL)
	{
		new_node->next = list;
		return new_node;
	}
}

/*	definition of insert
 *	Description: Just calls the create_node and insert_in_order functions.
 *	Parameters: A pointer to the linked list, and the value of id_member.
 *	Returns: A pointer to the top of the linked list.
 */
struct node *insert(struct node *list, int id)
{
	struct node *newnode;
	
	newnode = create_node(id);
	list = insert_in_order(list, newnode);
	
	return list;
}

/*	definition of print_list
 *	Description: Prints the id's nodes of the list.
 *	Parameters: A pointer to the list.
 *	Returns: Nothing.
 */
void print_list(const struct node *list)
{
	while (list != NULL)
	{
		printf("Value of member_id: %d\n", *list->id_member);
		list = list->next;
	}
}


/*	definition of search_by_id
 *	Description: Search for an id in a linked list.
 *	Paramaters: The list, and the id value to be searched.
 *	Returns: A pointer to the node if the id was found, NULL otherwise.
 */
struct node *search_by_id(struct node *list, int id)
{
	while (list != NULL)
	{
		if (*list->id_member == id)
		{
			return list;
		}
		list = list->next;
	}
	
	return NULL;
}

/*	definition of delete_list
 *	Description: Frees the memory allocated for the ordered list.
 *	Parameters: A pointer to the list. (Pass it a pointer to the top of the list to make sure we're freeing all the nodes.)
 *	Returns: A generic pointer to null.
 */
void *delete_list(struct node *list)
{
#ifdef DEBUG
	int i = 0;
#endif
	
	struct node *current_node;
	while (list != NULL)
	{
#ifdef DEBUG
		i++;
#endif
		// Advance to the next node
		current_node = list;
		list = list->next;
		free(current_node->id_member);
		free(current_node);
	}
#ifdef DEBUG
	printf("%d node(s) freed.\n", i);
#endif
	
	return NULL;	
}

#endif /* --> LIST_C */
