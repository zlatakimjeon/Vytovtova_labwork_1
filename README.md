Разработать итератор всех подмножеств множества {0, . . . , n − 1}, где n — параметр, вводимый пользователем. Реализация включает структуру, хранящую состояние:
typedef struct Set{...} set_t;
typedef struct SetIterator {
// Current value.
set_t value ;
// Iterationstate .
...
} iterator_t;
и следующие функции:
void iterator_init(iterator_t ∗i, unsigned n) ;
const set_t ∗iterator_value (const iterator_t ∗i) ;
int iterator_has_next (const iterator_t ∗i) ;
void iterator_next (iterator_t ∗i) ;
void iterator_destroy (iterator_t ∗i) ;
