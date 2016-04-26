#include "queue.h"

void queue_init(Queue *const queue) {
	list_init(queue);
}

void queue_destroy(Queue *const queue) {
	assert(queue != NULL);
	list_destroy(queue);
}

void queue_push(Queue *const queue, const void *const element, const size_t size) {
	assert(queue != NULL);
	list_append(queue, element, size);
}

const void *queue_peek(const Queue *const queue) {
	assert(queue != NULL);
	return list_first(queue);
}

void queue_pop(Queue *const queue, const size_t size) {
	assert(queue != NULL);
	list_remove(queue, 0, size);
}

void queue_clear(Queue *const queue) {
	assert(queue != NULL);
	list_clear(queue);
}

bool queue_empty(const Queue *const queue) {
	assert(queue != NULL);
	return list_empty(queue);
}