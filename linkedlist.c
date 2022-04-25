#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

#include <time.h>

struct node
{
    char name[11];
    char rg[8];
    struct node *next;
};

struct list
{
    Node *head;
};

Node *createnode(char *name, char *rg);

Node *createnode(char *name, char *rg)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        return NULL;
    }
    strcpy(newNode->name, name);
    strcpy(newNode->rg, rg);
    newNode->next = NULL;
    return newNode;
}

List *makelist(int rows)
{
    List *list = (List *)calloc(rows, sizeof(List));
    if (!list)
    {
        return NULL;
    }
    list->head = NULL;
    return list;
}

void print_list(List *list)
{
    clock_t t;
    t = clock();
    Node *current = list->head;
    if (list->head == NULL)
        return;

    for (; current->next != NULL; current = current->next)
    {
        printf("%s\n %s\n", current->name, current->rg);
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
}

void push(List *list, char *name, char *rg)
{
    clock_t t;
    t = clock();
    Node *current = NULL;
    if (list->head == NULL)
    {
        list->head = createnode(name, rg);
    }
    else
    {
        current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = createnode(name, rg);
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
}
/*----------------------------------------------------------------*/

void pushfirstnode(List *list, char *name, char *rg)
{
    clock_t t;
    t = clock();
    Node *current = NULL;
    if (list->head == NULL)
    {
        list->head = createnode(name, rg);
    }
    else
    {
        current = createnode(name, rg);
        current->next = list->head;
        list->head = current;
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
}

/*----------------------------------------------------------------*/

void pushatn(List *list, char *name, char *rg, int n)
{
    clock_t t;
    t = clock();
    Node *current = NULL;
    Node *last = NULL;
    if (list->head == NULL)
    {
        list->head = createnode(name, rg);
    }
    else
    {
        current = list->head;
        for (int i = 0; i < n - 1; i++)
        {
            current = current->next;
        }
        last = current;
        current = current->next;
        last->next = createnode(name, rg);
        last = last->next;
        last->next = current;
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
}

void removefirst(List *list)
{
    clock_t t;
    t = clock();
    Node *current = NULL;
    Node *last = NULL;
    if (list->head == NULL)
    {
        return;
    }
    else
    {
        last = list->head;
        current = last->next;
        list->head = current;
        last = NULL;
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
}

void removelast(List *list, int n)
{
    clock_t t;
    t = clock();
    Node *current = NULL;
    if (list->head == NULL)
    {
        return;
    }
    else
    {
        current = list->head;
        for (int i = 0; i < n - 1; i++)
        {
            current = current->next;
        }
        current->next = NULL;
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
}

void removeatn(List *list, int n)
{
    clock_t t;
    t = clock();
    Node *current = NULL;
    Node *last = NULL;
    if (list->head == NULL)
    {
        return;
    }
    else
    {
        current = list->head;
        for (int i = 0; i < n - 1; i++)
        {
            current = current->next;
        }
        last = current;
        current = current->next;
        last->next = current->next;
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
}

void searchrg(List *list, char *rg)
{
    Node *current = NULL;
    int z = 0;
    if (list->head == NULL)
    {
        return;
    }
    else
    {
        current = list->head;
        while (strcmp(current->rg, rg) != -7)
        {
            current = current->next;
            z++;
        }
        printf("Nome: %s\n", current->name);
        printf("RG: %s\n", current->rg);
        printf("Posição %d\n", z);
    }
}

void closelist(List *list)
{
    Node *current = list->head;
    Node *next = current;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
