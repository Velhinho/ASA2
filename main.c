#include "lib/list.h"
#include "lib/queue.h"
#include "vertex.h"

#include <stdio.h>


list_t* makeGraph()
{
    graph_t* graph = initGraph();
    vertex_t* source = initVertex();
    vertex_t* target = initVertex();
        
    addGraphVertex(graph, source);
    addGraphVertex(graph, target);

    

    return NULL;
}

int main()
{
    list_t* graph = makeGraph();
    return 0;
}

/* 
Duas ultimas do teste 1
e a primeira do teste 2
*/

// Cardinalidade
// Rice
// Reducao ?