#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/set_iterator.h"

void test_empty_set() {
    iterator_t it;
    iterator_init(&it, 0);

    assert(iterator_has_next(&it));
    iterator_next(&it);
    const set_t *s = iterator_value(&it);
    assert(s->size == 0);

    iterator_next(&it);
    assert(!iterator_has_next(&it));

    iterator_destroy(&it);
    printf("test_empty_set passed\n");
}

void test_set_size_1() {
    iterator_t it;
    iterator_init(&it, 1);

    int count = 0;
    int expected_sizes[] = {0, 1};
    while (iterator_has_next(&it)) {
        iterator_next(&it);
        const set_t *s = iterator_value(&it);
        assert(s->size == expected_sizes[count]);
        count++;
    }
    assert(count == 2); // 2^1 = 2 подмножества

    iterator_destroy(&it);
    printf("test_set_size_1 passed\n");
}

void test_set_size_2() {
    iterator_t it;
    iterator_init(&it, 2);

    int count = 0;
    int expected_sizes[] = {0, 1, 1, 2};
    while (iterator_has_next(&it)) {
        iterator_next(&it);
        const set_t *s = iterator_value(&it);
        assert(s->size == expected_sizes[count]);
        count++;
    }
    assert(count == 4); // 2^2 = 4 подмножества

    iterator_destroy(&it);
    printf("test_set_size_2 passed\n");
}

void test_set_size_3() {
    iterator_t it;
    iterator_init(&it, 3);

    int count = 0;
    while (iterator_has_next(&it)) {
        iterator_next(&it);
        count++;
    }
    assert(count == 8); // 2^3 = 8 подмножеств

    iterator_destroy(&it);
    printf("test_set_size_3 passed\n");
}

void test_iterator_reuse() {
    iterator_t it;
    
    // Первое использование
    iterator_init(&it, 2);
    int count1 = 0;
    while (iterator_has_next(&it)) {
        iterator_next(&it);
        count1++;
    }
    assert(count1 == 4);
    iterator_destroy(&it);

    // Повторное использование
    iterator_init(&it, 1);
    int count2 = 0;
    while (iterator_has_next(&it)) {
        iterator_next(&it);
        count2++;
    }
    assert(count2 == 2);
    iterator_destroy(&it);

    printf("test_iterator_reuse passed\n");
}

void test_content_validation() {
    iterator_t it;
    iterator_init(&it, 2);

    // Проверяем, что подмножества содержат правильные элементы
    int subset_count = 0;
    while (iterator_has_next(&it)) {
        iterator_next(&it);
        const set_t *s = iterator_value(&it);
        
        // Проверяем, что все элементы в подмножестве корректны
        for (int i = 0; i < s->size; i++) {
            assert(s->elements[i] >= 0 && s->elements[i] < 2);
        }
        subset_count++;
    }
    assert(subset_count == 4);

    iterator_destroy(&it);
    printf("test_content_validation passed\n");
}

int main() {
    test_empty_set();
    test_set_size_1();
    test_set_size_2();
    test_set_size_3();
    test_iterator_reuse();
    test_content_validation();

    printf("All tests passed!\n");
    return 0;
}