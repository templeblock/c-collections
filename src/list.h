#ifndef LIST_H
#define LIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifndef LIST_EXPANSION_RATE
	#define LIST_EXPANSION_RATE 2
#endif

// Makes the list memory aligned with 16, 32 and 64 bit pointers
#if defined(LIST_MAX_LEN) && defined(LIST_INDEX)
	typedef LIST_INDEX ListIndex;
#elif INTPTR_MAX == INT16_MAX
	#define LIST_MAX_LEN (0xFF)
	typedef uint8_t ListIndex;
#elif INTPTR_MAX == INT32_MAX
	#define LIST_MAX_LEN (0xFFFF)
	typedef uint16_t ListIndex;
#else
	#define LIST_MAX_LEN (0xFFFFFFFF)
	typedef uint32_t ListIndex;
#endif

typedef struct {
	ListIndex capacity;
	ListIndex len;
	char *elements;
} List;

void list_init(List *const list);
void list_destroy(List *const list);

void list_alloc(List *const list, const size_t size);
void list_expand(List *const list, const size_t size);
void list_contract(List *const list, const size_t size);

const void *list_get(const List *const list, const ListIndex index, const size_t size);
void list_set(List *const list, const ListIndex index, const void *const element, const size_t size);
const void *list_first(const List *const list);
const void *list_last(const List *const list, const size_t size);

void list_append(List *const list, const void *const element, const size_t size);
void list_concat(List *const list, const List *const other, const size_t size);
void list_remove(List *const list, const ListIndex index, const size_t size);
void list_clear(List *const list);

bool list_empty(const List *const list);
bool list_equal(const List *const list, const List *const other, const size_t size);
bool list_contains(const List *const list, const void *const element, const size_t size, ListIndex *const index);

#endif