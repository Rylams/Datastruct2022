#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct node Node;

typedef struct list List;

List * makelist(int rows);
void print_list(List * list);
void push(List *list, char *name, char *rg);
void closelist(List * list);

#endif