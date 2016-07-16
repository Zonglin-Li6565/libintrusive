/**
 * The AVL tree struct and functions.
 * Author: Zonglin Li
 */
#ifndef _AVL_H
#define _AVL_H

#include "binarytree.h"
#include <stdint.h>
#include <stdio.h>

/**
 * Implementation note: The reserved0 field will be used to store the height 
 * of the subtree. And the height should be initialized to 1.
 */

#define INIT_NODE(node, key)            \
do                                      \
{                                       \
    /* code */                          \
    (node).left = (node).right = NULL;  \
    (node).key_ptr = (void*)(key);      \
    (node).reserved0 = 1;               \
} while (0)

/**
 * avl_insert
 *   DESCRIPTION: insert a new node into the AVL tree
 *   INPUTS: root -------- The root node of the tree
 *           new_node ---- The new node to insert
 *           compare_key - The function pointer for comparing two nodes
 *   RETURN VALUE: 0 on success, -1 on failure
 *   SIDE EFFECTS: 
 *   NOTE: The function pointer should return 
 *              0 if key0 == key1
 *              1 if key0 >  key1
 *              -1 if key0 < key1 
 *              -2 if any error
 *   AUTHOR: Zonglin Li
 */
int avl_insert(bin_tree_node_t** root, bin_tree_node_t* new_node, 
    int32_t (*compare_key) (void*, void*));

/**
 * avl_remove
 *   DESCRIPTION: remove a node from the AVL tree
 *   INPUTS: root -------- The root node of the tree
 *           key --------- The key of the node to remove
 *           compare_key - The function pointer for comparing two nodes
 *   RETURN VALUE: The pointer to the removed tree node or NULL if any failure
 *   SIDE EFFECTS: 
 *   NOTE: The function pointer should return 
 *              0 if key0 == key1
 *              1 if key0 >  key1
 *              -1 if key0 < key1 
 *              -2 if any error
 *   WARNING: No validation of the parameter key will be performed
 *   AUTHOR: Zonglin Li
 */
bin_tree_node_t* avl_remove(bin_tree_node_t** root, void* key,
    int32_t (*compare_key) (void*, void*));

/**
 * avl_find
 *   DESCRIPTION: find a node from the AVL tree
 *   INPUTS: root -------- The root node of the tree
 *           key --------- The key of the target node
 *           compare_key - The function pointer for comparing two nodes
 *   RETURN VALUE: The pointer to the removed tree node or NULL if any failure
 *   SIDE EFFECTS: 
 *   NOTE: The function pointer should return 
 *              0 if key0 == key1
 *              1 if key0 >  key1
 *              -1 if key0 < key1 
 *              -2 if any error
 *   AUTHOR: Zonglin Li
 */
bin_tree_node_t* avl_find(bin_tree_node_t* root, void* key, 
    int32_t (*compare_key) (void*, void*));
#endif /* _AVL_H */
