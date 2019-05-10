#include "lib/queue.h"
#include "lib/list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXBUFFER 10000
#define SOURCE 0
#define TARGET 1
#define EMPTY 0

int number_vertices;
int number_providers;
int number_distributors;
int number_connections;
int *current_vertex, *height, *excess;
list_t **adj_list, **capacity, **flow;
queue_t *vertices_queue;

int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    
    else 
    { 
        return b;
    } 
}

int *init_int_array()
{
    int *array = (int *)malloc(number_vertices * sizeof(int));
    return array;
}

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
    addList(flow[v], capacity_number);
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
    if(index == -1)
    {
        fprintf(stderr, "No Such Index u:%d v:%d", u, v);
    }
    changeList(flow[u], index, flow_number);
}

int is_distributor_in(int vertex)
{
    int distributor_in_start = 2 + number_providers;
    int distributor_in_end = distributor_in_start + number_distributors;

    return vertex >= distributor_in_start && vertex <= distributor_in_end;
}

int get_distributor_out(int vertex)
{
    if (!is_distributor_in(vertex))
    {
        printf("not a distributor");
        return -1;
    }

    return vertex + number_distributors;
}

void print_graph()
{
    int v, cap;
    printf("\n");
    for (int u = 0; u < number_vertices; u++)
    {
        for (int i = 0; i < capacity[u]->size; i++)
        {
            v = getList(adj_list[u], i);
            cap = getList(capacity[u], i);
            printf("u:%d v:%d cap:%d\n", u, v, cap);
        }
    }
}

void add_connections()
{
    int u, v, capacity_number;
    printf("Enter following lines\n");

    for (int i = 0; i < number_connections; i++)
    {
        scanf("%d %d %d", &u, &v, &capacity_number);

        if(u == TARGET && is_distributor_in(v))
        {
            add_capacity(u, get_distributor_out(v), capacity_number);
        }

        else if(v == TARGET && is_distributor_in(u))
        {
            add_capacity(get_distributor_out(u), v, capacity_number);
        }

        else
        {
            add_capacity(u, v, capacity_number);
        } 
    }
    print_graph();
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
    int provider = 2;

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
    current_vertex = init_int_array();
    height = init_int_array();
    excess = init_int_array();
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

void discharge()
{

}

void fill_queue()
{
    // Start in 1 to skip source
    for(int vertex = 1; vertex < number_vertices; vertex++)
    {
        pushQueue(vertices_queue, vertex);
    }
}

void preflow()
{
    int v, capacity_number;

    for(int i = 0; i < number_vertices; i++)
    {
        current_vertex[i] = 0;
        excess[i] = 0;
        height[i] = 0;
    }
    height[SOURCE] = number_vertices;
    
    // Saturate vertices leaving source
    for(int i = 0; i < adj_list[SOURCE]->size; i++)
    {
        v = getList(adj_list[SOURCE], i);
        capacity_number = getList(adj_list[SOURCE], i);
        change_flow(SOURCE, v, capacity_number);
        change_flow(v, SOURCE, 0);
    }
}

void relabel_front()
{
    int vertex, old_height;
    preflow();
    fill_queue();

    vertex = popQueue(vertices_queue);
    while(vertex != EMPTY)
    {
        old_height = height[vertex];
        discharge(vertex);

        if(height[vertex] > old_height)
        {
            // relabel TO FRONT of the list
            pushQueue(vertices_queue, vertex);
        }
        vertex = popQueue(vertices_queue);
    }
}

int main()
{
    make_graph();
    relabel_front();
}