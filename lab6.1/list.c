/* list.c */

#include "list.h"

/* malloc() a new list header and initialize it */
list_t *list_init(void)
{
	list_t * list = (list_t*)malloc(sizeof(list_t));
	list->first = NULL;
	list->last = NULL;
	list->current = NULL;
	return list;
}


/**/
/* add an element to the end of a list */
void list_add(list_t *list, void *entity)
{
	link_t * node = (link_t*)malloc(sizeof(link_t));
	node -> next = NULL;
	node -> entity =  entity;
	list -> current = node;

	if (list->first == NULL)
	{			//check if list exists
		list -> first = node;
		list -> last = node;
	} else {
		list -> last -> next = node;
		list -> last = node;
	}
}


/**/
/* set current pointer to first pointer */
void list_reset(list_t *list)
{
	list -> current = list -> first;
}


/**/
/* return 1 if current pointer is pointing at a valid link */
/* return 0 if current pointer is NULL                     */
int list_not_end(list_t *list)
{
	if (list->current == NULL)
	{
		return 0;
	} else {
		return 1;
	}
}


/**/
/* advance current pointer to next link */
void list_next_link(list_t *list)
{
   assert(list->current != NULL);
	list->current = list -> current -> next;
}


/**/
/* return address of entity pointed to by current link */
void *list_get_entity(list_t *list)
{
   assert(list->current != NULL);
	return list->current->entity;
}


/**/
/* free() all entities, links, and then the list header */
void list_del(list_t *list)
{
	list_reset(list);
	while (list->first != NULL)
	{
		list->first = list -> first -> next;
		free(list->current);
		list_reset(list);
	}
	free(list);
}
  
