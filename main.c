#include "lib/list.h"
#include "lib/queue.h"
#include "vertex.h"

#include <stdio.h>


list_t* makeGraph()
{
    graph_t* graph = initGraph();
    vertex_t* source = initVertex();
    
    edge_t* edge = initEdge();
    changeEdgeCurrentFlow(edge, 123);
    source->excess = 2;
    addVertexEdge(source, edge);
    
    vertex_t* target = initVertex();
    addGraphVertex(graph, source);
    addGraphVertex(graph, target);

    edge_t* edge2 = getVertexEdge(source, 0);
    printf("cf = %d", getEdgeCurrentFlow(edge2->currentflow));
    printf("excess = %d", getVertexExcess)
}

int main()
{
    list_t* graph = makeGraph();
}

/* 
Duas ultimas do teste 1
e a primeira do teste 2
*/

// Cardinalidade
// Rice
// Reducao ?