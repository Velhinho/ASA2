#include "vertex.h"
#include "stdlib.h"
#include "stdio.h"

void vertexError() 
{
    fprintf(stderr, "bad vertex"); 
}

void edgeError() 
{
    fprintf(stderr, "bad edge"); 
}


vertex_t* initVertex()
{
    vertex_t* vertex = (vertex_t*) malloc(sizeof(vertex_t));
    vertex->excess = -1;
    vertex->height = -1;
    return vertex;
}

void changeVertexExcess(vertex_t* vertex, int excess)
{
    if(vertex == NULL) 
        vertexError();

    else 
        vertex->excess = excess;
}

int getVertexExcess(vertex_t* vertex)
{
    if(vertex == NULL)
    {
        vertexError();
        return -1;
    }
    
    return vertex->excess;
}

void changeVertexHeight(vertex_t *vertex, int height)
{
    if (vertex == NULL)
        vertexError();

    else
        vertex->height = height;
}

int getVertexHeight(vertex_t* vertex)
{
    if (vertex == NULL)
    {
        vertexError();
        return -1;
    }

    return vertex->height;
}

int removeVertex(vertex_t* vertex)
{
    if(vertex == NULL)
    {
        vertexError();
        return 0;
    }

    free(vertex);
    return 1;
}


edge_t* initEdge()
{
    edge_t* edge = (edge_t*) malloc(sizeof(edge_t));
    edge->currentflow = -1;
    edge->capacity = -1;
    return edge;
}

void changeEdgeCurrentFlow(edge_t* edge, int currentflow)
{
    if (edge == NULL)
        vertexError();

    else
        edge->currentflow = currentflow;
}

int getEdgeCurrentFlow(edge_t* edge)
{
    if(edge == NULL)
    {
        edgeError();
        return -1;
    }

    return edge->currentflow;
}

void changeEdgeCapacity(edge_t *edge, int capacity)
{
    if (edge == NULL)
        vertexError();

    else
        edge->capacity = capacity;
}

int getEdgeCapacity(edge_t *edge)
{
    if (edge == NULL)
    {
        edgeError();
        return -1;
    }

    return edge->capacity;
}

int removeEdge(edge_t* edge)
{
    if (edge == NULL)
    {
        vertexError();
        return 0;
    }

    free(edge);
    return 1;
}