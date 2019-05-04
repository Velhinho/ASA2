#include "lib/list.h"
#include "vertex.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXBUFFER 1000


int main()
{
    //Test code
    graph_t* graph = initGraph();
    vertex_t* source = initVertex();
    addGraphVertex(graph, source);
    
    char input_line[MAXBUFFER];
    char *token;
    int capacity;
    vertex_t* vertex;
    edge_t* edge_out;
    edge_t* edge_in;

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

    return 0;
}