#include "../headers/list.h"


void print_commands() {
	printf("Commands: \n");
	printf("\t1 - Print list\n");
	printf("\t2 - Insert to end\n");
	printf("\t3 - Delete from end\n");
	printf("\t4 - Insert to beginning\n");
	printf("\t5 - Delete from beginning\n");
	printf("\t6 - Insert after <index>\n");
	printf("\t7 - Clear list\n");
	printf("\t8 - action\n");
	printf("\t9 - exit\n");
}


int handle_input(int option, List* list) {
	if (!list) return -1;
	size_t index, value;
 	switch (option) {
		case 1:
			list_print(list);
			break;
		case 2:
			printf("Enter the value of the element: ");
			scanf("%zu", &value);
			list_insert_to_end(value, list);
			break;
		case 3:
			list_delete_end(list);
			break;
		case 4:
			printf("Enter the value of the element: ");
			scanf("%zu", &value);
			list_insert_to_begin(value, list);
			break;
		case 5:
			list_delete_begin(list);
			break;
		case 6:
		 	printf("Enter index, value of the element: ");
			scanf("%zu %zu", &index, &value);
			list_insert_after(index, value, list);
			break;
		case 7:
			list_clear(list);
			break;
		case 8:
			printf("How many last copies of last elements you want to insert to the beginning: ");
			scanf("%zu", &index);
			list_action(index, list);
			break;
		case 9:
			list_destroy(list);
			exit(0);
			break;
		default:
			print_commands();
			break;
	}
	return 0;
}


int input_option(int *option) {
	int is_eof = scanf("%d", option);
	char t;
	scanf("%c", &t);
	return is_eof;
}


int main() {
	List* list = list_create();
	if (!list) return -1;
	int option;
	print_commands();
	printf("Enter command: ");
	while ((input_option(&option)) != EOF) {
		handle_input(option, list);
		printf("Enter command: ");
	}
}