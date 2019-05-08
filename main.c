#include "lib/queue.h"
#include "lib/list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXBUFFER 10000


int number_vertices;
list_t *current_vertex, *height, *excess;
list_t **adj_list, **capacity, **flow;
queue_t *vertices_queue;

void init_matrix(list_t **list)
{
    list = (list_t **)malloc(number_vertices * sizeof(list_t*));

    for(int i = 0; i < number_vertices; i++)
    {
        list[i] = initList();
    }
}

int getEdge(list_t **list, int u, int v)
{
    return getList(list[u], v);(
}

void addEdge(list_t **list, int u, int v)
{
    addList(list[u], v);
    addList(list[v], u);
}

/*
2 5 60

capacity[2][5] = 60



*/

/* 
3 fornecedores
4 estacoes

v[2] a [5] fornecedores

v_in(v[6]): 6 + 4 + 1

v[6] ao v[10]
v[11] ao v[17]
*/

void fill_pointers()
{
    current_vertex = initList();
    height = initList();
    excess = initList();
    init_matrix(adj_list);
    init_matrix(capacity);
    init_matrix(flow);
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