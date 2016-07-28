/**
 * The hashtable data structure, with both chaining and probing
 * Author: Zonglin Li
 */
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <stdint.h>

/**
 * The hashtable node structure
 */ 
typedef struct hashtable_node
{
    void *key;
}hashtable_node_t;

typedef struct hashtable
{
    hashtable_node_t **table;
    int size;
    int elements;
    /**
     *
     */
    uint32_t (*hash) (void *key, int size);
    /**
     *
     */
    void (*insert) (struct hashtable *self, hashtable_node_t *newnode);
    /**
     *
     */
    hashtable_node_t *(*remove) (struct hashtable *self, hashtable_node_t *node);
    hashtable_node_t *(*find) (struct hashtable *self, void *key);
} hashtable_t;

#endif  /* _HASHTABLE_H */

