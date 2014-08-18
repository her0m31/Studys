#include "function.h"

void delete_cell(struct cell_f **pointer)
{
	struct cell_f *target;

	while((*pointer) != NULL){
		target = *pointer;
		*pointer = target->next;
		free((void *)target);
		(*pointer) = (*pointer)->next;
	}
}
