#include "list.h"
#include <stdlib.h>
#include <stdio.h>


list_t *initList()
{
    list_t *newList = (list_t*) malloc(sizeof(list_t));
    newList->start = NULL;
    newList->end = NULL;
    newList->size = 0;

    return newList;
}

void addList(list_t *list, int data)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    
    if(list->start == NULL)
    {
        list->start = newNode;
        list->end = newNode;
    }
    else
    {
     list->end->next = newNode;
     list->end = newNode;   
    }
    list->size += 1;
}

node_t *findList(list_t *list, int index)
{
    node_t *node = list->start;

    if (index >= list->size || index < 0)
        return NULL;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

int findIndex(list_t *list, int data)
{
    node_t *node = list->start;

    for (int i = 0; i < list->size; i++)
    {
        if(node->data == data)
            return i;

        node = node->next;
    }

    return -1;
}

int getList(list_t *list, int index)
{
    node_t* node = findList(list, index);

    if(node == NULL)
        return -1;

    return node->data;
}

void changeList(list_t *list, int index, int new_data)
{
    node_t *node = findList(list, index);
    node->data = new_data;
}

int removeList(list_t *list, int index)
{
    node_t *previousnode = findList(list, index - 1);
    node_t *currentnode = findList(list, index);

    if (currentnode == NULL)
        return 0;
    
    if (index == 0)
    {
        list->start = currentnode->next;
    }

    else
    {
        previousnode->next = currentnode->next;
    }

    free(currentnode);
    return 1;
}

void printList(list_t *list)
{
    node_t *node = list->start;

    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}