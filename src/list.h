#ifndef LIST_H
#define LIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define LIST_EXPANSION_RATE 2

typedef unsigned int ListIndex;
typedef void *ListEl;

typedef struct {
	ListIndex capacity;
	ListIndex len;
	ListEl *els;
} List;

void list_init(List *const list, const ListIndex capacity);
void list_destroy(List *const list);

void list_alloc(List *const list);
void list_expand(List *const list);
void list_contract(List *const list);

void list_append(List *const list, const ListEl el);
void list_concat(List *const list, const List *const other);
void list_remove(List *const list, const ListIndex index);
void list_clear(List *const list);

ListEl list_get(const List *const list, const ListIndex index);
void list_set(List *const list, const ListIndex index, const ListEl el);
ListEl list_first(const List *const list);
ListEl list_last(const List *const list);
bool list_empty(const List *const list);

#endif