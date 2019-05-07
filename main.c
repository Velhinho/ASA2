#include "lib/queue.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXBUFFER 10000


int number_vertices;
int *current_vertex, *height, *excess;
int **capacity, **flow;
queue_t *vertices_queue;


int *init_lists(int size)
{
    int *ret = (int *)malloc(size * sizeof(int));
    return ret;
}

int **init_matrix(int size)
{
    int **ret = (int **)malloc(size * sizeof(int*));

    for(int i = 0; i < size; i++)
    {
        ret[i] = init_lists(size);
    }
    return ret;
}

void fill_pointers()
{
    current_vertex = init_lists(number_vertices);
    height = init_lists(number_vertices);
    excess = init_lists(number_vertices);
    capacity = init_matrix(number_vertices);
    flow = init_matrix(number_vertices);
    vertices_queue = initQueue();
}

void make_graph()
{
    int number_providers;
    int number_distributors;
    int number_connections;
    printf("Enter first line\n");
    scanf("%d %d %d",
            &number_providers,
            &number_distributors,
            &number_connections);

    number_vertices = number_providers + 2 * number_distributors;
    fill_pointers();
}

void relabel_front()
{

}

int main()
{
    make_graph();
    relabel_front();
}