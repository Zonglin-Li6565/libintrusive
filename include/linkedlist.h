/**
 * The linked list data structure implemented in intrusive way.
 * Author: Zonglin Li
 */
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <stddef.h>

typedef struct linkedlist_node
{
    struct linkedlist_node* prev;
    struct linkedlist_node* next;
} linkedlist_node_t __attribute__((aligned(8)));

typedef struct linked_list
{
    linkedlist_node_t* head;
    linkedlist_node_t* tail;
} linked_list_t;

#define INIT_LINKEDLIST(newlist)        \
do                                      \
{                                       \
    (newlist).head = NULL;              \
    (newlist).tail = NULL;              \
} while (0)

/**
 * linkedlist_insert_head
 *   DESCRIPTION: insert a new node into the linkedlist at head.
 *   INPUTS: node --- the new node
 *           list --- the list to insert into
 *   RETURN VALUE: 0 on success, -1 on failure
 *   AUTHOR: Zonglin Li
 */
int linkedlist_insert_head(linkedlist_node_t* node, linked_list_t* list);

/**
 * linkedlist_insert_tail
 *   DESCRIPTION: insert a new node into the linkedlist at head.
 *   INPUTS: node --- the new node
 *           list --- the list to insert into
 *   RETURN VALUE: 0 on success, -1 on failure
 *   AUTHOR: Zonglin Li
 */
int linkedlist_insert_tail(linkedlist_node_t* node, linked_list_t* list);

/**
 * linkedlist_remove
 *   DESCRIPTION: remove a new node into the linkedlist.
 *   INPUTS: node --- the new node
 *           list --- the list to insert into
 *   RETURN VALUE: 0 on success, -1 on failure
 *   AUTHOR: Zonglin Li
 */
int linkedlist_remove(linkedlist_node_t* node, linked_list_t* list);

#endif /* _LINKEDLIST_H */

