#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARRAY_RESIZE_RATE
	#define ARRAY_RESIZE_RATE 2
#endif

// Makes the array memory aligned with 16, 32 and 64 bit pointers
#if defined(ARRAY_MAX_LEN) && defined(ARRAY_INDEX_TYPE)
	typedef ARRAY_INDEX_TYPE ArrayIndex;
#elif INTPTR_MAX == INT16_MAX
	#define ARRAY_MAX_LEN (0xFF)
	typedef uint8_t ArrayIndex;
#elif INTPTR_MAX == INT32_MAX
	#define ARRAY_MAX_LEN (0xFFFF)
	typedef uint16_t ArrayIndex;
#else
	#define ARRAY_MAX_LEN (0xFFFFFFFF)
	typedef uint32_t ArrayIndex;
#endif

typedef struct {
	ArrayIndex capacity;
	ArrayIndex len;
	char *data;
} Array;

void array_init(Array *const array);
void array_destroy(Array *const array);

void array_alloc(Array *const array, const size_t size);
void array_expand(Array *const array, const size_t size);
void array_contract(Array *const array, const size_t size);

const void *array_get(const Array *const array, const ArrayIndex index, const size_t size);
void array_set(Array *const array, const ArrayIndex index, const void *const element, const size_t size);
const void *array_first(const Array *const array);
const void *array_last(const Array *const array, const size_t size);

void array_append(Array *const array, const void *const element, const size_t size);
void array_concat(Array *const array, const Array *const other, const size_t size);
void array_remove(Array *const array, const ArrayIndex index, const size_t size);
void array_clear(Array *const array);

bool array_is_empty(const Array *const array);
bool array_equal(const Array *const array, const Array *const other, const size_t size);
bool array_contains(const Array *const array, const void *const element, const size_t size, ArrayIndex *const index);

#endif