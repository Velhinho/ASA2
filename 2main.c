#include "lib/list.h"
#include "lib/queue.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXBUFFER 10000


typedef struct
{
    list_t **capacity, **flow;
    list_t *height, *excess;
    queue_t *vertices_queue;
} graph_t;

graph_t *initGraph()
{
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->capacity = initList();
    graph->flow = initList();
    graph->height = initList();
    graph->excess = initList();
    graph->vertices_queue = initQueue();
    return graph;
}

void add_providers(graph_t *graph, int number_providers)
{
    char input_line[MAXBUFFER];
    char *token;
    int capacity;

    graphAddProviders(graph, number_providers);

    printf("Enter second line");
    fgets(input_line, MAXBUFFER, stdin);
    
    token = strtok(input_line, " ");
    while(token != NULL)
    {
        capacity = atoi(token);
        
    }
}

graph_t *make_graph()
{
    graph_t *graph = initGraph();
    int number_providers;
    int number_distributors;
    int number_connections;
    int number_vertices = number_providers
                        + 2 * number_distributors;

    printf("Enter first line\n");
    scanf("%d %d %d",
          &number_providers,
          &number_distributors,
          &number_connections);
    
    add_providers();
}

int main()
{
    graph_t* graph = make_graph();
}