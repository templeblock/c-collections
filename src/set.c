#include "set.h"

void set_init(Set *const set) {
	assert(set != NULL);
	list_init(set);
}

void set_destroy(Set *const set) {
	assert(set != NULL);
	list_destroy(set);
}

bool set_contains(const Set *const set, const void *const element, const size_t size) {
	assert(set != NULL);
	assert(element != NULL);
	return list_contains(set, element, size, NULL);
}

void set_add(Set *const set, const void *const element, const size_t size) {
	assert(set != NULL);
	assert(element != NULL);
	if (!set_contains(set, element, size)) list_append(set, element, size);
}

void set_remove(Set *const set, const void *const element, const size_t size) {
	assert(set != NULL);
	assert(element != NULL);
	ListIndex index;
	if (list_contains(set, element, size, &index)) list_remove(set, index, size);
}