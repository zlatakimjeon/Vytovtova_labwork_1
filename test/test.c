#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/set_iterator.h"  // Подкорректируй путь, если нужно

void test_empty_set() {
    iterator_t it;
    iterator_init(&it, 0);  // Пустое множество

    assert(iterator_has_next(&it));
    iterator_next(&it);
    const set_t *s = iterator_value(&it);
    assert(s->size == 0);

    iterator_next(&it);
    assert(!iterator_has_next(&it));

    iterator_destroy(&it);
    printf("test_empty_set passed\n");
}

void test_set_size_2() {
    iterator_t it;
    iterator_init(&it, 2);

    int count = 0;
    while (iterator_has_next(&it)) {
        iterator_next(&it);
        const set_t *s = iterator_value(&it);
        assert(s->size <= 2);
        count++;
    }
    assert(count == 4); // 2^2 = 4 подмножества

    iterator_destroy(&it);
    printf("test_set_size_2 passed\n");
}

int main() {
    test_empty_set();
    test_set_size_2();

    printf("All tests passed!\n");
    return 0;
}
