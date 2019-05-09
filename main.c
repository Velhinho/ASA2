#include "lib/queue.h"
#include "lib/list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXBUFFER 10000
#define SOURCE 0
#define TARGET 1

int number_vertices;
int number_providers;
int number_distributors;
int number_connections;
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

void add_capacity(int u, int v, int capacity_number)
{
    addList(adj_list[u], v);
    addList(adj_list[v], u);
    
    addList(capacity[u], capacity_number);
    addList(capacity[v], capacity_number);

    addList(flow[u], 0);
    addList(flow[v], 0);
}

int get_capacity(int u, int v)
{
    int index = findIndex(adj_list[u], v);
    return getList(capacity[u], index);
}

int get_flow(int u, int v)
{
    int index = findIndex(adj_list[u], v);
    return getList(flow[u], index);
}

void change_flow(int u, int v, int flow_number)
{
    int index = findIndex(adj_list[u], v);
    changeList(flow[u], index, flow_number);
}

void add_providers()
{
    char input_line[MAXBUFFER];
    char *token;
    int provider_capacity;
    int provider = 0;

    printf("Enter second line\n");
    fgets(input_line, MAXBUFFER, stdin);
    token = strtok(input_line, " ");

    /* 
    Creates a vertex to be connected to the source
    and creates an edge from the source to the vertex
    Each vertex and edge represent the max production
    of a provider
    */
    while (token != NULL)
    {
        provider_capacity = atoi(token);
        add_capacity(SOURCE, provider, provider_capacity);
        printf("%d\n", provider_capacity);

        // Next value
        token = strtok(NULL, " ");
        provider += 1;
    }
}

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
    printf("Enter first line\n");
    scanf("%d %d %d",
            &number_providers,
            &number_distributors,
            &number_connections);

    number_vertices = number_providers + 2 * number_distributors;
    fill_pointers();
    add_providers();
}

void relabel_front()
{

}

int main()
{
    make_graph();
    relabel_front();
}