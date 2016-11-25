#include "array.h"

void array_init(Array *const array) {
	assert(array != NULL);
	array->capacity = 0;
	array->len = 0;
	array->data = NULL;
}

void array_destroy(Array *const array) {
	assert(array != NULL);
	free(array->data);
}

void array_expand(Array *const array, const size_t size) {
	assert(array != NULL);
	assert(array->capacity < ARRAY_MAX_LEN);
	
	array->capacity *= ARRAY_RESIZE_RATE;
	array->capacity += !array->capacity;
	array->data = realloc(array->data, array->capacity * size);
	assert(array->data != NULL);
}

void array_contract(Array *const array, const size_t size) {
	assert(array != NULL);

	while (array->capacity && array->len <= array->capacity / (ARRAY_RESIZE_RATE * ARRAY_RESIZE_RATE)) {
		array->capacity /= ARRAY_RESIZE_RATE;
	}

	if (array->capacity) {
		array->data = realloc(array->data, array->capacity * size);
		assert(array->data != NULL);
	} else {
		array_destroy(array);
		array->data = NULL;
	}
}

const void *array_get(const Array *const array, const ArrayIndex index, const size_t size) {
	assert(array != NULL);
	assert(index < array->len);

	return (void *)(array->data + index * size);
}

void array_set(Array *const array, const ArrayIndex index, const void *const element, const size_t size) {
	assert(array != NULL);
	assert(index < array->len);
	assert(element != NULL);

	memcpy(array->data + index * size, element, size);
}

const void *array_first(const Array *const array) {
	assert(array != NULL);
	return (void *)array->data;
}

const void *array_last(const Array *const array, const size_t size) {
	assert(array != NULL);
	return array_get(array, array->len - 1, size);
}

void array_append(Array *const array, const void *const element, const size_t size) {
	assert(array != NULL);
	assert(element != NULL);
	if (array->len == array->capacity) {
		array_expand(array, size);
	}
	array->len++;
	array_set(array, array->len - 1, element, size);
}

void array_concat(Array *const array, const Array *const other, const size_t size) {
	assert(array != NULL);
	assert(other != NULL);
	while (array->len + other->len > array->capacity) {
		array_expand(array, size);
	}
	memcpy(array->data + array->len * size, other->data, other->len * size);
	array->len += other->len;
}

void array_remove(Array *const array, const ArrayIndex index, const size_t size) {
	assert(array != NULL);
	assert(index < array->len);
	void *const dest = array->data + index * size;
	memmove(dest, dest + size, (array->len - index - 1) * size);
	array->len--;
	array_contract(array, size);
}

void array_clear(Array *const array) {
	assert(array != NULL);
	array_destroy(array);
	array_init(array);
}

bool array_is_empty(const Array *const array) {
	assert(array != NULL);
	return array->len == 0;
}

bool array_equal(const Array *const array, const Array *const other, const size_t size) {
	assert(array != NULL);
	assert(other != NULL);
	return array->len == other->len && memcmp(array->data, other->data, array->len * size) == 0;
}

bool array_contains(const Array *const array, const void *const element, const size_t size, ArrayIndex *const index) {
	assert(array != NULL);
	assert(element != NULL);

	for (ArrayIndex i = 0; i < array->len; i++) {
		if (memcmp(array_get(array, i, size), element, size) == 0) {
			if (index) {
				*index = i;
			}
			return true;
		}
	}

	return false;
}