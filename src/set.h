#ifndef SET_H
#define SET_H

#include <stdint.h>
#include "array.h"

typedef Array Set;

void set_init(Set *const set);
void set_destroy(Set *const set);
bool set_contains(const Set *const set, const void *const element, const size_t size);
void set_add(Set *const set, const void *const element, const size_t size);
void set_remove(Set *const set, const void *const element, const size_t size);

#endif