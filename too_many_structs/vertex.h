#ifndef VERTEX
#define VERTEX

#include "lib/list.h"

typedef struct
{
    int height;
    int excess;
    list_t* edges;
}vertex_t;

typedef struct
{
    int vertex_number;
    int currentflow;
    int capacity;
}edge_t;

typedef list_t graph_t;

void vertexError();
void edgeError();

vertex_t* initVertex();
void addVertexEdge(vertex_t* vertex, edge_t* edge);
edge_t* getVertexEdge(vertex_t *vertex, int index);
void changeVertexExcess(vertex_t* vertex, int excess);
int getVertexExcess(vertex_t* vertex);
void changeVertexHeight(vertex_t *vertex, int height);
int getVertexHeight(vertex_t *vertex);
int removeVertex(vertex_t *vertex);

edge_t* initEdge();
void changeEdgeCurrentFlow(edge_t *edge, int currentflow);
int getEdgeCurrentFlow(edge_t *edge);
void changeEdgeCapacity(edge_t *edge, int capacity);
int getEdgeCapacity(edge_t *edge);
int removeEdge(edge_t *edge);

graph_t* initGraph();
void addGraphVertex(graph_t* graph, vertex_t* vertex);
vertex_t* getGraphVertex(graph_t* graph, int index);
int removeGraphVertex(graph_t* graph, int index);


#endif