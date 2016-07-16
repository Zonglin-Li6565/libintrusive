/**
 * The common binary tree node struct
 * Author: Zonglin Li
 */

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <stdint.h>
#include <stddef.h>

typedef struct bin_tree_node
{
    struct bin_tree_node* left;
    struct bin_tree_node* right;
    void* key_ptr;
    /* reserved for data structure specific usage */
    uint32_t reserved0;
} bin_tree_node_t __attribute__((aligned(16)));

#endif /* _BINARYTREE_H */
