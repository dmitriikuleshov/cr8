#ifndef LW_ITERATOR_H
#define LW_ITERATOR_H

#include "list.h"

#define STRUCT_NODE_TYPE ListNode
#define STRUCT_TYPE List


typedef struct Iterator {
	STRUCT_NODE_TYPE* node;
} Iterator;

Iterator* iter_create(const STRUCT_TYPE* struct_object);
void next(Iterator*);

#endif