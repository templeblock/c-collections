#include "../src/list.h"

void test_list(void) {
	List list;
	list_init(&list);

	// Verify that the list is empty
	assert(list.capacity == 0);
	assert(list.len == 0);
	assert(list.elements == NULL);
	assert(list_empty(&list));

	// Build the list
	for (int i = 0; i <= 1; i++) {
		list_append(&list, &i, sizeof(i));
		assert(list.len == i + 1);
		assert(list.capacity >= list.len);
		assert(!list_empty(&list));
		assert(*(int *)list_get(&list, i, sizeof(i)) == i);
	}

	// Verify that the list equals itself
	assert(list_eq(&list, &list, sizeof(int)));

	// Build another list
	List other;
	list_init(&other);
	for (int n = 2; n <= 4; n++) {
		list_append(&other, &n, sizeof(n));
	}
	assert(other.len = 3);

	// Concatenate the lists
	list_concat(&list, &other, sizeof(int));
	assert(list.len == 5);
	assert(list.capacity >= list.len);
	for (int i = 0; i < 5; i++) {
		assert(*(int *)list_get(&list, i, sizeof(i)) == i);
		ListIndex index;
		assert(list_contains(&list, &i, sizeof(i), &index));
		assert(index == i);
	}

	// Remove first element
	list_remove(&list, 0, sizeof(int));
	assert(list.len == 4);
	for (int i = 0; i < 4; i++) {
		assert(*(int *)list_get(&list, i, sizeof(i)) == i + 1);
	}

	// Remove last element
	list_remove(&list, 3, sizeof(int));
	assert(list.len == 3);
	for (int i = 0; i < 3; i++) {
		assert(*(int *)list_get(&list, i, sizeof(i)) == i + 1);
	}

	// Clear the list
	list_clear(&list);
	assert(list.capacity == 0);
	assert(list.len == 0);
	assert(list.elements == NULL);
}