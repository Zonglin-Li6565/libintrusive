#ifndef _AVL_TEST_H
#define _AVL_TEST_H

#include <binarytree.h>
#include <avltree.h>
#include <common.h>
#include <stdio.h>

typedef struct test_avl
{
    int label;
    bin_tree_node_t node;
} test_avl_t;

int32_t compare(void* first, void* second);

void avl_test();

#endif /* _AVL_TEST_H */
