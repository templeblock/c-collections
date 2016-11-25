#include "stack.h"

void stack_init(Stack *const stack) {
	array_init(stack);
}

void stack_destroy(Stack *const stack) {
	assert(stack != NULL);
	array_destroy(stack);
}

void stack_push(Stack *const stack, const void *const element, const size_t size) {
	assert(stack != NULL);
	assert(element != NULL);
	array_append(stack, element, size);
}

const void *stack_peek(const Stack *const stack, const size_t size) {
	assert(stack != NULL);
	return array_last(stack, size);
}

void stack_pop(Stack *const stack, const size_t size) {
	assert(stack != NULL);
	array_remove(stack, stack->len - 1, size);
}

void stack_clear(Stack *const stack) {
	assert(stack != NULL);
	array_clear(stack);
}

bool stack_is_empty(Stack *const stack) {
	assert(stack != NULL);
	return array_is_empty(stack);
}