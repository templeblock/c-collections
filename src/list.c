#include "list.h"

void list_init(List *const list) {
	list->capacity = 0;
	list->len = 0;
	list->elements = NULL;
}

void list_destroy(List *const list) {
	assert(list != NULL);
	free(list->elements);
}

void list_alloc(List *const list, const size_t size) {
	assert(list != NULL);
	if (!list->capacity) return list_destroy(list);
	list->elements = realloc(list->elements, list->capacity * size);
	assert(list->elements != NULL);
}

void list_expand(List *const list, const size_t size) {
	assert(list != NULL);
	assert(list->capacity < LIST_MAX_LEN);
	list->capacity *= LIST_ALLOCATION_RATE;
	list->capacity += !list->capacity;
	list_alloc(list, size);
}

void list_contract(List *const list, const size_t size) {
	assert(list != NULL);
	while (list->capacity && list->len <= list->capacity / (LIST_ALLOCATION_RATE * LIST_ALLOCATION_RATE)) list->capacity /= LIST_ALLOCATION_RATE;
	list_alloc(list, size);
}

const void *list_get(const List *const list, const ListIndex index, const size_t size) {
	assert(list != NULL);
	assert(index < list->len);
	return (void *)(list->elements + index * size);
}

void list_set(List *const list, const ListIndex index, const void *const element, const size_t size) {
	assert(list != NULL);
	assert(index < list->len);
	assert(element != NULL);
	memcpy(list->elements + index * size, element, size);
}

const void *list_first(const List *const list) {
	assert(list != NULL);
	return (void *)list->elements;
}

const void *list_last(const List *const list, const size_t size) {
	assert(list != NULL);
	return list_get(list, list->len - 1, size);
}

void list_append(List *const list, const void *const element, const size_t size) {
	assert(list != NULL);
	assert(element != NULL);
	if (list->len == list->capacity) list_expand(list, size);
	list->len++;
	list_set(list, list->len - 1, element, size);
}

void list_concat(List *const list, const List *const other, const size_t size) {
	assert(list != NULL);
	assert(other != NULL);
	while (list->len + other->len > list->capacity) list_expand(list, size);
	memcpy(list->elements + list->len * size, other->elements, other->len * size);
	list->len += other->len;
}

void list_remove(List *const list, const ListIndex index, const size_t size) {
	assert(list != NULL);
	assert(index < list->len);
	void *const dest = list->elements + index * size;
	memmove(dest, dest + size, (list->len - index - 1) * size);
	list->len--;
	list_contract(list, size);
}

void list_clear(List *const list) {
	assert(list != NULL);
	list_destroy(list);
	list_init(list);
}

bool list_empty(const List *const list) {
	assert(list != NULL);
	return list->len == 0;
}

bool list_equal(const List *const list, const List *const other, const size_t size) {
	assert(list != NULL);
	assert(other != NULL);
	return list->len == other->len && memcmp(list->elements, other->elements, list->len * size) == 0;
}

bool list_contains(const List *const list, const void *const element, const size_t size, ListIndex *const index) {
	assert(list != NULL);
	assert(element != NULL);
	for (ListIndex i = 0; i < list->len; i++) {
		if (memcmp(list_get(list, i, size), element, size) != 0) continue;
		if (index) *index = i;
		return true;
	}
	return false;
}