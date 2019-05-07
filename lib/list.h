#ifndef LIST
#define LIST

typedef struct node
{
    int data;
    struct node* next;
}node_t;

typedef struct
{
    node_t* start;
    node_t* end;
    int size;
}list_t;

list_t *initList();
void addList(list_t *list, int data);
int getList(list_t *list, int index);
int removeList(list_t *list, int index);

#endif