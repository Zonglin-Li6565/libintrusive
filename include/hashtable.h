/**
 * The hashtable data structure, with both chaining and probing
 * Author: Zonglin Li
 */
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#define SEPERATE_CHAINING 0
#define PROBING           1

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
    uint32_t size;
    uint32_t elements;
    /**
     * hash
     *   DESCRIPTION: The hash function for the hashtable (provided by the user of this data structure)
     *   INPUTS: key --- the key as parameter
     *           size -- the size of the hash table
     *   RETURN VALUE: The computed entry of the entry.
     *   NOTE: This function is provided by the user of this datastructure. Also, note that 
     *         the output value shoule be less than the size.
     *   AUTHOR: Zonglin Li
     */
    uint32_t (*hash) (void *key, int size);
    /**
     * insert
     *   DESCRIPTION: Insert an element into this hashtable.
     *   INPUTS: self ----- The pointer to self
     *           newnode -- The pointer to the new node to insert.
     *   RETURN VALUE: none.
     *   NOTE: The self pointer points to the current structure. Use this function in 
     *         OOP manner. Since there is no implicite self pointer, that pointer should
     *         be provided explicitely.
     *   AUTHOR: Zonglin Li
     */
    void (*insert) (struct hashtable *self, hashtable_node_t *newnode);
    /**
     * remove
     *   DESCRIPTION: remove an element from the table.
     *   INPUTS: self --- The pointer to self
     *           key  --- The pointer to the key.
     *   RETURN VALUE: The removed structure.
     *   NOTE: The self pointer points to the current structure. Use this function in 
     *         OOP manner. Since there is no implicite self pointer, that pointer should
     *         be provided explicitely.
     *   AUTHOR: Zonglin Li
     */
    hashtable_node_t *(*remove) (struct hashtable *self, void *key);
    /**
     * find
     *   DESCRIPTION: find the element from the table.
     *   INPUTS: self --- The pointer to self
     *           key  --- The pointer to the key.
     *   RETURN VALUE: The found structure.
     *   NOTE: The self pointer points to the current structure. Use this function in 
     *         OOP manner. Since there is no implicite self pointer, that pointer should
     *         be provided explicitely.
     *   AUTHOR: Zonglin Li
     */
    hashtable_node_t *(*find) (struct hashtable *self, void *key);
    /**
     * deleteall
     *   DESCRIPTION: Delete the hash table. Free all allocated memory
     *   INPUTS: self --- The pointer to self
     *   RETURN VALUE: none
     *   NOTE: The self pointer points to the current structure. Use this function in 
     *         OOP manner. Since there is no implicite self pointer, that pointer should
     *         be provided explicitely.
     *   AUTHOR: Zonglin Li
     */
    void (*deleteall) (struct hashtable *self);
} hashtable_t;

/**
 * initialize_table
 *   DESCRIPTION: Initialize a new hash table with the specified size
 *                and mode.
 *   INPUTS: table ------ The pointer to the new table structure
 *           init_size -- The initial size of the table
 *           mode ------- The mode of the table. Either seperate chaining or probing. 
 *                        Use the macro above.
 *           hash ------- The hash function to use.
 *   RETURN VALUE: none
 *   SIDE EFFECTS: Will use allocator to allocate a new block of memory 
 *   NOTE: All the parameters are required
 *   AUTHOR: Zonglin Li
 */
void initialize_table(hashtable_t *table, uint32_t init_size, int mode, uint32_t (*hash) (void *key, int size));

#endif  /* _HASHTABLE_H */

