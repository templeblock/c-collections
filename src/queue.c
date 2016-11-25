#include "queue.h"

void queue_init(Queue *const queue) {
	array_init(queue);
}

void queue_destroy(Queue *const queue) {
	assert(queue != NULL);
	array_destroy(queue);
}

void queue_push(Queue *const queue, const void *const element, const size_t size) {
	assert(queue != NULL);
	array_append(queue, element, size);
}

const void *queue_peek(const Queue *const queue) {
	assert(queue != NULL);
	return array_first(queue);
}

void queue_pop(Queue *const queue, const size_t size) {
	assert(queue != NULL);
	array_remove(queue, 0, size);
}

void queue_clear(Queue *const queue) {
	assert(queue != NULL);
	array_clear(queue);
}

bool queue_is_empty(const Queue *const queue) {
	assert(queue != NULL);
	return array_is_empty(queue);
}