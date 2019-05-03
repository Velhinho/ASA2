#ifndef VERTEX
#define VERTEX

typedef struct
{
    int height;
    int excess;
}vertex_t;

typedef struct
{
    int currentflow;
    int capacity;
}edge_t;


void vertexError();
void edgeError();

vertex_t* initVertex();
void changeVertexExcess(vertex_t* vertex, int excess);
int getVertexExcess(vertex_t* vertex);
void changeVertexHeight(vertex_t *vertex, int height);
int getVertexHeight(vertex_t *vertex);
int removeVErtex(vertex_t *vertex);

edge_t* initEdge();
void changeEdgeCurrentFlow(edge_t *edge, int currentflow);
int getEdgeCurrentFlow(edge_t *edge);
void changeEdgeCapacity(edge_t *edge, int capacity);
int getEdgeCapacity(edge_t *edge);
int removeEdge(edge_t *edge);

#endif