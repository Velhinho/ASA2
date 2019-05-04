#include "lib/list.h"
#include "lib/queue.h"
#include "vertex.h"

#include <stdio.h>
#include <string.h>

#define MAXBUFFER 1000


void add_providers()
{
    char input_line[MAXBUFFER];
    fgets(input_line, MAXBUFFER, stdin);

    char* token;
    token = strtok(input_line, " ");

    while(token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    /*
    Tentar descobrir como ler a primeira
    linha de input
    */
}

graph_t* makeGraph()
{
    graph_t* graph = initGraph();
    vertex_t* source = initVertex();
    vertex_t* target = initVertex();
        
    addGraphVertex(graph, source);
    addGraphVertex(graph, target);

    int number_providers;
    int number_distributors;
    int number_connections;
    scanf("%d %d %d", 
            &number_providers, 
            &number_distributors, 
            &number_connections);

    add_providers();

    return NULL;
}

int main()
{
    graph_t* graph = makeGraph();
    return 0;
}

/* 
Duas ultimas do teste 1
e a primeira do teste 2
*/

// Cardinalidade
// Rice
// Reducao ?