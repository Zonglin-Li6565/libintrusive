#include <linkedlist.h>

int linkedlist_insert_head(linkedlist_node_t* node, linked_list_t* list)
{
    node->next = list->head;
    list->head = node;
    node->prev = NULL;
    if (list->tail == NULL)
    {
        list->tail = node;
    }else
    {
        node->next->prev = node;
    }
    return 0;
}

int linkedlist_insert_tail(linkedlist_node_t* node, linked_list_t* list)
{
    node->prev = list->tail;
    list->tail = node;
    node->next = NULL;
    if (list->head == NULL)
    {
        list->head = node;
    }else
    {
        node->prev->next = node;
    }
    return 0;
}

int linkedlist_remove(linkedlist_node_t* node, linked_list_t* list)
{
    if (node->prev == NULL)             // head
    {
        list->head = node->next;
    }else
    {
        node->prev->next = node->next;
    }
    if (node->next == NULL)
    {
        list->tail = node->prev;
    }else
    {
        node->next->prev = node->prev;
    }
    node->prev = node->next = NULL;
    return 0;
}

