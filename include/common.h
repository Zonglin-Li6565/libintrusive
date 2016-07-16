/**
 * The common infrastructure for the intrusive data structures.
 * Noting: using some of the code from Linux source 
 * Author: Zonglin Li
 */

#ifndef _COMMON_H
#define _COMMON_H

#include <stdint.h>

/* 
 * offsetof
 *   DESCRIPTION: Get the offset of a field in a struct
 *   INPUTS: type ---- The type of the struct the member is in
 *           member -- The name of the member field in the structs
 *   RETURN VALUE: The offset in number of bytes for the member from the start of the struct
 *   SIDE EFFECTS: none 
 *   WARNING: Please provide the correct parameters
 */
#define offsetof(type, member)                              \
    ((size_t) &((type *)0)->member)

/* 
 * container_of
 *   DESCRIPTION: Get the container of the intrusive data structure struct
 *   INPUTS: ptr ----- The pointer to the member data structure of the container
 *           type ---- The type of the container struct the data structure embedded in.
 *           member -- The name of the member data structure in the container
 *   RETURN VALUE: The container data structure of the specific intrusice data structure
 *   SIDE EFFECTS: none 
 *   WARNING: Please provide the correct parameters
 */
#define container_of(ptr, type, member)                     \
({                                                          \
 const typeof( ((type *)0)->member ) *__mptr = (ptr);       \
 (type *)( (char *)__mptr - offsetof(type,member) );        \
})

#endif /* _COMMON_H */
