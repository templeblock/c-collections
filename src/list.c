#include "list.h"

void list_init(List *const list, const ListIndex capacity) {
	list->capacity = capacity;
	list->len = 0;
	list->els = NULL;
	list_alloc(list);
}

void list_destroy(List *const list) {
	assert(list != NULL);
	free(list->els);
}

void list_alloc(List *const list) {
	assert(list != NULL);
	if (!list->capacity) return list_clear(list);
	list->els = realloc(list->els, list->capacity * sizeof(ListEl));
	assert(list->els);
}

void list_expand(List *const list) {
	assert(list != NULL);
	list->capacity *= LIST_EXPANSION_RATE;
	if (!list->capacity) list->capacity++;
	list_alloc(list);
}

void list_contract(List *const list) {
	assert(list != NULL);
	while (list->capacity && list->len <= list->capacity / (LIST_EXPANSION_RATE * LIST_EXPANSION_RATE)) list->capacity /= LIST_EXPANSION_RATE;
	list_alloc(list);
}

void list_append(List *const list, const ListEl el) {
	assert(list != NULL);
	if (list->len == list->capacity) list_expand(list);
	list->els[list->len] = el;
	list->len++;
}

void list_concat(List *const list, const List *const other) {
	assert(list != NULL);
	while (list->len + other->len > list->capacity) list_expand(list);
	memcpy(list->els + list->len, other->els, other->len * sizeof(ListEl));
	list->len += other->len;
}

void list_remove(List *const list, const ListIndex index) {
	assert(list != NULL);
	assert(index < list->len);
	for (ListIndex i = index + 1; i < list->len; i++) list->els[i - 1] = list->els[i];
	list->len--;
	list_contract(list);
}

void list_clear(List *const list) {
	assert(list != NULL);
	list->capacity = 0;
	free(list->els);
	list->els = NULL;
}

ListEl list_get(const List *const list, const ListIndex index) {
	assert(list != NULL);
	assert(index < list->len);
	return list->els[index];
}

void list_set(List *const list, const ListIndex index, const ListEl el) {
	assert(list != NULL);
	assert(index < list->len);
	list->els[index] = el;
}

ListEl list_first(const List *const list) {
	assert(list != NULL);
	return list_get(list, 0);
}

ListEl list_last(const List *const list) {
	assert(list != NULL);
	return list_get(list, list->len - 1);
}

bool list_empty(const List *const list) {
	assert(list != NULL);
	return list->len == 0;
}