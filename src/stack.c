#include "stack.h"

void stack_init(Stack *const stack) {
	list_init(stack, 0);
}

void stack_destroy(Stack *const stack) {
	assert(stack != NULL);
	list_destroy(stack);
}

void stack_push(Stack *const stack, const ListEl el) {
	assert(stack != NULL);
	list_append(stack, el);
}

ListEl stack_peek(const Stack *const stack) {
	assert(stack != NULL);
	return list_last(stack);
}

void stack_pop(Stack *const stack) {
	assert(stack != NULL);
	list_remove(stack, stack->len - 1);
}

void stack_clear(Stack *const stack) {
	assert(stack != NULL);
	list_clear(stack);
}

bool stack_empty(Stack *const stack) {
	assert(stack != NULL);
	return list_empty(stack);
}