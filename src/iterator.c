#include "../headers/iterator.h"


Iterator* iter_create(const STRUCT_TYPE* struct_object) {
    Iterator* iter = (Iterator*)malloc(sizeof(Iterator));
    if (iter == NULL) {
        printf("MEMORY ALLOCATION ERROR\n");
        exit(1);
    }
    iter->node = struct_object->head;
    return iter;
}


void next(Iterator* iter) {
    if (iter->node != NULL) {
        iter->node = iter->node->next;
    }
}
