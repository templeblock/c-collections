#ifndef STACK_H
#define STACK_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "list.h"

typedef List Stack;

void stack_init(Stack *const stack);
void stack_destroy(Stack *const stack);
void stack_push(Stack *const stack, const void *const element, const size_t size);
const void *stack_peek(const Stack *const stack, const size_t size);
void stack_pop(Stack *const stack, const size_t size);
void stack_clear(Stack *const stack);
bool stack_empty(Stack *const stack);

#endif