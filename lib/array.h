#ifndef ARRAY
#define ARRAY

typedef struct
{
    int *array;
    int used;
    int size;
} array_t;

array_t *initArray(int initialSize);
array_t **initMatrix(int matrix_size, int array_size);
void insertArray(array_t *a, int element);
void freeArray(array_t *a);

#endif