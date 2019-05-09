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


list_t **init_matrix()
{
    list_t **list = (list_t **)malloc(number_vertices * sizeof(list_t*));

    for(int i = 0; i < number_vertices; i++)
    {
        list[i] = initList();
    }

    return list;
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


void add_connections()
{
    int u, v, capacity;
    printf("Enter following lines\n");

    for (int i = 0; i < number_connections; i++)
    {
        scanf("%d %d %d", &u, &v, &capacity);
        add_capacity(u, v, capacity);
    }
}

void add_distributors()
{
    char input_line[MAXBUFFER];
    char *token;
    int distributor_capacity;

    /* 
    Each distributor is a vertex pair (distributor_in, distributor_out)
    The edge between these vertices represents the capacity of the distributor
    
    If there are 2 providers and 2 distributors then the list would look like:
    [0]source, [1]target, [2]provider_1, [3]provider_2, 
    [4]distributor_in_1, [5]distributor_in_2
    [5]distributor_out_1, [6]distributor_out_2

    So the indexes for distributor_in starts after the number of providers
    plus the source and target (number_providers + 2)

    And the indexes for distributor_out starts after all the distributor_in 
    */
    int distributor_in = number_providers + 2;
    int distributor_out = distributor_in + number_distributors;

    printf("Enter third line\n");
    fgets(input_line, MAXBUFFER, stdin);
    token = strtok(input_line, " ");

    while (token != NULL)
    {
        distributor_capacity = atoi(token);
        add_capacity(distributor_in, distributor_out, distributor_capacity);

        // Next value
        token = strtok(NULL, " ");
        distributor_in += 1;
        distributor_out += 1;
    }
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
    adj_list = init_matrix();
    capacity = init_matrix();
    flow = init_matrix();
    vertices_queue = initQueue();
}

void make_graph()
{
    char clean_input[MAXBUFFER];
    printf("Enter first line\n");
    scanf("%d %d %d",
            &number_providers,
            &number_distributors,
            &number_connections);

    // scanf leaves a newline char, screws next fgets
    fgets(clean_input, MAXBUFFER, stdin);

    // Source + Target + Providers + 2 * Distributors
    number_vertices = 2 + number_providers + 2 * number_distributors;
    fill_pointers();
    add_providers();
    add_distributors();
    add_connections();
}

void relabel_front()
{

}

int main()
{
    make_graph();
    relabel_front();
}