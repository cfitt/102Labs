/* list.c */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

link_t::link_t(void *newentity)
{
	next = NULL;
	entity = newentity;
}

link_t::~link_t(void)
{
   fprintf(stderr, "in link destructor \n");
}

void link_t::set_next(link_t *new_next)
{
	next = new_next;
}

link_t * link_t::get_next()
{
	return(next);
}

void * link_t::get_entity()
{
	return(entity);
}


list_t::list_t()
{
	first = NULL;
	last = NULL;
	current = NULL;
}


void list_t::add(void *entity)
{

/* Create a new link passing it the entity pointer */
	link_t *link;
	link = new link_t(entity);
/* Now add the link to the list using generally the */
/* same approach as the C version                   */
	if(first == NULL)
	{
		first = link;
		last = link;
	}
	else
	{
		last->set_next(link);
		last = link;
	}
	current = link;
}

void list_t::reset(void)
{
	current = first;
}

int list_t::not_end(void)
{
	if (current == NULL)
		return 0;
	else
		return 1;
}

void list_t::next_link(void)
{
   assert(current != NULL);
	current = current->get_next();
}

void *list_t::get_entity(void)
{
   assert(current != NULL);
	return(current->get_entity());
}

list_t::~list_t()
{
	link_t *kill;
	fprintf(stderr, "in list destructor \n");

/* Delete each link_t in the list */
	while (first != NULL)
	{
		kill = first->get_next();
		delete first;
		first = kill;
	}
}
