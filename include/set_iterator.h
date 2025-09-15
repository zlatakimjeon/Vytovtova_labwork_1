#ifndef SET_ITERATOR_H
#define SET_ITERATOR_H

typedef struct Set {
    int *elements;
    int size;
} set_t;

typedef struct SetIterator {
    set_t value;
    unsigned n;
    unsigned mask;
    unsigned total;
} iterator_t;

void iterator_init(iterator_t *i, unsigned n);
const set_t *iterator_value(const iterator_t *i);
int iterator_has_next(const iterator_t *i);
void iterator_next(iterator_t *i);
void iterator_destroy(iterator_t *i);

#endif // SET_ITERATOR_H
