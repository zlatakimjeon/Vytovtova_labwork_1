#include <stdlib.h>
#include "set_iterator.h"

void iterator_init(iterator_t *i, unsigned n) {
    i->n = n;
    i->mask = 0;
    i->total = 1U << n;
    i->value.elements = (int *)malloc(n * sizeof(int));
    i->value.size = 0;
}

const set_t *iterator_value(const iterator_t *i) {
    return &i->value;
}

int iterator_has_next(const iterator_t *i) {
    return i->mask < i->total;
}

void iterator_next(iterator_t *i) {
    i->value.size = 0;
    for (unsigned bit = 0; bit < i->n; ++bit) {
        if (i->mask & (1U << bit)) {
            i->value.elements[i->value.size++] = bit;
        }
    }
    i->mask++;
}

void iterator_destroy(iterator_t *i) {
    free(i->value.elements);
}
