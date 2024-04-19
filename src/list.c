#include "../headers/list.h"


List* list_create() {
	List* list = (List*)malloc(sizeof(List));
	if (list == NULL) {
		printf("MEMORY ALLOCATION ERROR\n");
		exit(1);
	}
	list->head = NULL;
	return list;
}


ListNode* create_node(size_t data) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		printf("MEMORY ALLOCATION ERROR\n");
		exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}


int list_size(List* list) {
	size_t size = 0;
	ListNode* current = list->head;
	while (current != NULL) {
		size++;
		current = current->next;
	}
	return size;
}

void list_print(List* list) {
    ListNode* current = list->head;
    while (current != NULL) {
        printf("%u ", current->data);
        current = current->next;
    }
    printf("\n");
}


void list_insert_to_begin(size_t data, List* list) {
    ListNode* new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
}



void list_insert_to_end(size_t data, List* list) {
    if (list->head == NULL) {
        list_insert_to_begin(data, list);
        return;
    }
    ListNode* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    ListNode* new_node = create_node(data);
    current->next = new_node;
}


int list_insert_after(int index, int data, List* list) {
    if (index < 0 || index >= list_size(list)) {
        printf("List index out of range\n");
        return -1;
    }
    ListNode* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    ListNode* new_node = create_node(data);
    new_node->next = current->next;
    current->next = new_node;
	return 0;
}


void list_delete_end(List *list) {
    if (list->head == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }
    ListNode* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}


void list_delete_begin(List* list) {
    if (list->head == NULL) {
        printf("The list is empty\n");
        return;
    }
    ListNode* temp = list->head;
    list->head = list->head->next;
    free(temp);
}


void list_clear(List* list) {
	while (list->head) {
        list_delete_begin(list);
    }
}

void list_destroy(List* list) {
	list_clear(list);
	free(list);	
}

// добавить k экземпляров последнего элемента в  начало списка
void list_action(size_t k, List* list) {
    if (list == NULL || list->head == NULL) {
        printf("The list is empty\n");
        return;
    }

    ListNode* last = list->head;
    while (last->next != NULL) {
        last = last->next;
    }

    for (size_t i = 0; i < k; i++) {
        ListNode* new_node = create_node(last->data);
        new_node->next = list->head;
        list->head = new_node;
    }
}