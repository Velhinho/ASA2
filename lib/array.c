#include "array.h"
#include <stdlib.h>

array_t *initArray(int initialSize)
{
    array_t *a = (array_t *)malloc(sizeof(array_t));
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
    return a;
}

array_t **initMatrix(int matrix_size, int array_size)
{
    array_t **a = (array_t **)malloc(
        matrix_size * sizeof(array_t*));

    for(int i = 0; i < matrix_size; i++)
    {
        a[i] = initArray(array_size);
    }

    return a;
}

void insertArray(array_t *a, int element)
{
    // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
    // Therefore a->used can go up to a->size
    if (a->used == a->size)
    {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(array_t *a)
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}