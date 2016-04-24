#ifndef QUEUE_H
#define QUEUE_H

#include <assert.h>
#include <stdbool.h>
#include "list.h"

typedef List Queue;

void queue_init(Queue *const queue);
void queue_destroy(Queue *const queue);
void queue_push(Queue *const queue, const ListEl el);
ListEl queue_peek(const Queue *const queue);
void queue_pop(Queue *const queue);
void queue_clear(Queue *const queue);
bool queue_empty(const Queue *const queue);

#endif