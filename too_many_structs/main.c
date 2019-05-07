#include "lib/list.h"
#include "vertex.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXBUFFER 1000

// Encontrei uma cena melhor na net vou tentar fazer outro
// https://cp-algorithms.com/graph/push-relabel.html


void add_distributors(graph_t* graph)
{
    vertex_t *vertex;

}

void add_providers(graph_t* graph)
{
    vertex_t *source = getGraphVertex(graph, 0);
    char input_line[MAXBUFFER];
    char *token;
    int capacity;
    vertex_t *vertex;
    edge_t *edge_out;
    edge_t *edge_in;

    printf("Enter second line\n");
    fgets(input_line, MAXBUFFER, stdin);
    token = strtok(input_line, " ");

    /* 
    Creates a vertex to be connected to the source
    and creates an edge from the source to the vertex
    Each vertex and edge represent the max production
    of a provider
    */
    while(token != NULL)
    {
        capacity = atoi(token);
        vertex = initVertex();
        edge_out = initEdge();
        edge_in = initEdge();
        changeEdgeCapacity(edge_out, capacity);
        addVertexEdge(source, edge_out);

        // Representing residual graph
        changeEdgeCapacity(edge_in, capacity);
        changeEdgeCurrentFlow(edge_in, capacity);
        addVertexEdge(vertex, edge_in);

        // Next value
        token = strtok(NULL, " ");
    }
}

graph_t* makeGraph()
{
    graph_t *graph = initGraph();
    vertex_t *source = initVertex();
    vertex_t *target = initVertex();

    addGraphVertex(graph, source);
    addGraphVertex(graph, target);

    int number_providers;
    int number_distributors;
    int number_connections;
    printf("Enter first line\n");
    scanf("%d %d %d", 
            &number_providers, 
            &number_distributors, 
            &number_connections);

    add_providers(graph);
    add_distributors(graph);

    return NULL;
}

int main()
{
    graph_t *graph = makeGraph();
    return 0;
}

/* 
Duas ultimas do teste 1
e a primeira do teste 2
*/

// Cardinalidade
// Rice
// Reducao ?
