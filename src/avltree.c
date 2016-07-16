/**
 * the source code for AVL tree
 * AUTHOR: Zonglin Li
 */

#include <avltree.h>

#define rotate_left(root)                   \
do                                          \
{                                           \
    bin_tree_node_t* tmp = root;            \
    root = root->right;                     \
    tmp->right = root->left;                \
    root->left = tmp;                       \
    /* update the height */                 \
    tmp->reserved0 = root->reserved0 - 1;   \
} while (0)

#define rotate_right(root)                  \
do                                          \
{                                           \
    /* code */                              \
    bin_tree_node_t* tmp = root;            \
    root = root->left;                      \
    tmp->left = root->right;                \
    root->right = tmp;                      \
    /* update the height */                 \
    tmp->reserved0 = root->reserved0 - 1;   \
} while (0)

#define rotate_left_right(root)             \
do                                          \
{                                           \
    rotate_left(root->left);                \
    rotate_right(root);                     \
} while (0)

#define rotate_right_left(root)             \
do                                          \
{                                           \
    rotate_right(root->right);              \
    rotate_left(root);                      \
} while (0)

static void rebalance(bin_tree_node_t** root)
{
    int32_t left_height = 0;
    int32_t right_height = 0;
    if (root == NULL || *root == NULL)
        return;
    bin_tree_node_t* temp_root = *root;
    // printf("temp_root = 0x%x, left = 0x%x, right = 0x%x\n", temp_root, temp_root->left, temp_root->right);
    if (temp_root->left != NULL)
    {
        // printf("rcp0.0\n");
        rebalance(&(temp_root->left));
        left_height = temp_root->left->reserved0;
    }
    // printf("rcp0\n");
    if (temp_root->right != NULL)
    {
        // printf("rcp0.1\n");
        rebalance(&(temp_root->right));
        right_height = temp_root->right->reserved0;
    }
    // printf("rcp1\n");
    temp_root->reserved0 = (left_height > right_height ? left_height : right_height) + 1;
    // printf("rcp2\n");
    printf("key = %x, left_height = %d, right_height = %d\n", (uint32_t*)(temp_root->key_ptr), left_height, right_height);
    if (left_height - right_height < -1)             // right > left
    {
        // printf("rcp2.1\n");
        if ((temp_root->right->left != NULL ? temp_root->right->left->reserved0 : 0)
             > (temp_root->right->right != NULL ? temp_root->right->right->reserved0 : 0))       // dog leg
        {
            rotate_right_left((*root));
        } else
        {
            rotate_left((*root));
        }
    }
    // printf("rcp3\n");
    if (left_height - right_height > 1)            // left > right
    {
        // printf("rcp3.1\n");
        if ((temp_root->left->right != NULL ? temp_root->left->right->reserved0 : 0)
             > (temp_root->left->left != NULL ? temp_root->left->left->reserved0 : 0))         // dog leg
        {
            rotate_left_right((*root));
        } else
        {
            rotate_right((*root));
        }
    }
    // printf("rcp4\n");
}

int avl_insert(bin_tree_node_t** root, bin_tree_node_t* new_node, 
    int32_t (*compare_key) (void*, void*))
{
    int ret_val = 0;
    // printf("ckp 0\n");
    if (root == NULL || *root == NULL || new_node == NULL || compare_key == NULL)
        return -1;
    // printf("ckp 1\n");
    int compare = compare_key((*root)->key_ptr, new_node->key_ptr);
    // printf("ckp 2\n");
    printf("compare = %d\n", compare);
    if (compare == -2)
        return -1;
    if (compare == 1)
    {
        if ((*root)->left == NULL) 
        {
            (*root)->left = new_node;
            ret_val = 0;
        }
        else
            ret_val = avl_insert(&((*root)->left), new_node, compare_key);
    } else
    {
        if ((*root)->right == NULL) 
        {
            (*root)->right = new_node;
            ret_val = 0;
        }
        else
            ret_val = avl_insert(&((*root)->right), new_node, compare_key);
    }
    // printf("ckp 3\n");
    rebalance(root);
    return ret_val;
}

bin_tree_node_t* avl_remove(bin_tree_node_t** root, void* key,
    int32_t (*compare_key) (void*, void*))
{
    bin_tree_node_t* ret_val;
    if (root == NULL || *root == NULL || compare_key == NULL)
        return NULL;
    int compare = compare_key((*root)->key_ptr, key);
    bin_tree_node_t* temp_root = *root;
    switch(compare)
    {
        case 1:
            ret_val = avl_remove(&((*root)->left), key, compare_key);
            break;
        case -1:
            ret_val = avl_remove(&((*root)->right), key, compare_key);
            break;
        case 0:
            ret_val = *root;
            if (temp_root->left == NULL && temp_root->right == NULL)
            {
                /* no-child remove */
                *root = NULL;
            } else if (temp_root->left != NULL && temp_root->right != NULL)
            {
                /* two-child remove */
                bin_tree_node_t** current = &temp_root->left;
                while((*current)->right != NULL)
                {
                    current = &((*current)->right);
                }
                (*current)->right = temp_root->right;
                (*current)->left  = temp_root->left != *current ? temp_root->left : NULL;
                (*root) = (*current);
                temp_root->left = temp_root->right = NULL;
                (*current) = NULL;
            } else 
            {
                if (temp_root->left != NULL)
                {
                    *root = (*root)->left;
                } else
                {
                    *root = (*root)->right;
                }
            }
            break;
        case -2:
            return NULL;
    }
    rebalance(root);
    return ret_val;
}

bin_tree_node_t* avl_find(bin_tree_node_t* root, void* key, 
    int32_t (*compare_key) (void*, void*))

{
    if (root == NULL || compare_key == NULL)
        return NULL;
    switch (compare_key(key, root->key_ptr))
    {
        case 0:                 // key == root->key_ptr
            return root;
        case 1:                 // key > root->key_ptr
            return avl_find(root->right, key, compare_key);
        case -1:                // key < root->key_ptr
            return avl_find(root->left, key, compare_key);
    }
    return NULL;
}

