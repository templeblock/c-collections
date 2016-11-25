#include "set.h"

void set_init(Set *const set) {
	assert(set != NULL);
	array_init(set);
}

void set_destroy(Set *const set) {
	assert(set != NULL);
	array_destroy(set);
}

bool set_contains(const Set *const set, const void *const element, const size_t size) {
	assert(set != NULL);
	assert(element != NULL);
	return array_contains(set, element, size, NULL);
}

void set_add(Set *const set, const void *const element, const size_t size) {
	assert(set != NULL);
	assert(element != NULL);
	
	if (!set_contains(set, element, size)) {
		array_append(set, element, size);
	}
}

void set_remove(Set *const set, const void *const element, const size_t size) {
	assert(set != NULL);
	assert(element != NULL);
	ArrayIndex index;
	if (array_contains(set, element, size, &index)) {
		array_remove(set, index, size);
	}
}