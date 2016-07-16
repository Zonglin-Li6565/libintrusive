
#include "avl_test.h"

int32_t compare(void* first, void* second)
{
    if (first == second)
        return 0;
    if (first > second)
        return 1;
    if (first < second)
        return -1;
    return -2;
}

void avl_test()
{
    int size = 10;
    test_avl_t test_array[size];
    bin_tree_node_t* root = &(test_array[0].node);
    INIT_NODE(*root, 0);
    test_array[0].label = 0;
    int i = 1;
    printf("start inserting...\n");
    for (; i < size; i++)
    {
        INIT_NODE(test_array[i].node, i);
        test_array[i].label = i;
        avl_insert(&root, &(test_array[i].node), &compare);
        printf("finished insert %d\n", i);
    }
    avl_remove(&root, (void*)3, compare);
    printf("root is: %d\n", root->key_ptr);
    for (i = 0; i < size; i++)
    {
        bin_tree_node_t* node = avl_find(root, (void*)i, compare);
        if (node == NULL)
        {
            printf("key: %d not found\n", i);
            continue;
        }
        printf("node %d: height = %d ", i, node->reserved0);
        test_avl_t* current = container_of(node, test_avl_t, node);
        printf("label = %d, left = %d, right = %d\n", current->label, 
            current->node.left == NULL ? -1 : (int)(current->node.left->key_ptr),
            current->node.right == NULL ? -1 : (int)(current->node.right->key_ptr));
    }
}

int main()
{
    avl_test();
    return 0;
}
