#include "stack.h"

void stack_init(Stack *const stack) {
	list_init(stack);
}

void stack_destroy(Stack *const stack) {
	assert(stack != NULL);
	list_destroy(stack);
}

void stack_push(Stack *const stack, const void *const element, const size_t size) {
	assert(stack != NULL);
	assert(element != NULL);
	list_append(stack, element, size);
}

const void *stack_peek(const Stack *const stack, const size_t size) {
	assert(stack != NULL);
	return list_last(stack, size);
}

void stack_pop(Stack *const stack, const size_t size) {
	assert(stack != NULL);
	list_remove(stack, stack->len - 1, size);
}

void stack_clear(Stack *const stack) {
	assert(stack != NULL);
	list_clear(stack);
}

bool stack_empty(Stack *const stack) {
	assert(stack != NULL);
	return list_empty(stack);
}