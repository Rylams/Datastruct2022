#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

#include <time.h>

struct node
{
    char name[11];
    int rg;
    struct node *next;
};

struct list
{
    Node *head;
    Node *tail;
};

Node *createnode(char *name, int rg);

Node *createnode(char *name, int rg)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        return NULL;
    }
    strcpy(newNode->name, name);
    newNode->rg = rg;
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
        printf("%s\n %d\n", current->name, current->rg);
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
}

void push(List *list, char *name, int rg)
{
    Node *current = NULL;
    if (list->head == NULL)
    {
        list->head = createnode(name, rg);
        list->tail = list->head;
    }
    else
    {
        current = list->tail;
        current->next = createnode(name, rg);
        current = current->next;
        list->tail = current;
    }
}
/*----------------------------------b------------------------------*/

void pushfirstnode(List *list, char *name, int rg)
{
    int c = 0;
    int m = 0;
    clock_t t;
    t = clock();
    Node *current = NULL;
    Node *last = NULL;

    c++;
    if (list->head == NULL)
    {
        list->head = createnode(name, rg);
    }
    else
    {
        last = createnode(name, rg);
        current = list->head;
        last->next = current;
        list->head = last;
        m += 4;
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
    printf("lista encadeada C(n) = %d\n", c);
    printf("lista encadeada M(n)= %d\n", m);
}

/*----------------------------------------------------------------*/

void pushatn(List *list, char *name, int rg, int n)
{
    clock_t t;
    t = clock();
    int c = 0;
    int m = 0;

    Node *current = NULL;
    Node *last = NULL;

    c++;
    if (list->head == NULL)
    {
        list->head = createnode(name, rg);
        m++;
    }
    else
    {
        current = list->head;
        m++;
        for (int i = 0; i < n - 1; i++)
        {
            current = current->next;
            m++;
        }
        last = current;
        last->next = createnode(name, rg);
        last = last->next;
        m+=3;
        c++;
        if (last->next != NULL)
        {
            last->next = current;
            m++;
        }
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
    printf("lista encadeada C(n) = %d\n", c);
    printf("lista encadeada M(n)= %d\n", m);
}

void removefirst(List *list)
{
    clock_t t;
    t = clock();
    int c = 0;
    int m = 0;
    Node *current = NULL;
    Node *last = NULL;

    c++;

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
        m+= 4;
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
    printf("lista encadeada C(n) = %d\n", c);
    printf("lista encadeada M(n)= %d\n", m);
}

void removelast(List *list, int n)
{
    clock_t t;
    t = clock();
    Node *current = NULL;
    int c = 0;
    int m = 0;

    c++;
    if (list->head == NULL)
    {
        return;
    }
    else
    {
        current = list->head;
        m++;
        while (current->next != list->tail){
            current = current->next;
            m++;
        }
        current->next = NULL;
        m++;
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("lista encadeada %f secs para executar \n", time_taken);
    printf("lista encadeada C(n) = %d\n", c);
    printf("lista encadeada M(n)= %d\n", m);
}

void removeatn(List *list, int n)
{
    clock_t t;
    t = clock();
    Node *current = NULL;
    Node *last = NULL;
    int c = 0;
    int m = 0;

    c++;
    if (list->head == NULL)
    {
        return;
    }
    else
    {
        m++;
        current = list->head;
        for (int i = 0; i < n - 1; i++)
        {
            current = current->next;
            m++;
        }
        last = current;
        current = current->next;
        last->next = current->next;
        m += 3;
    }
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("lista encadeada %f secs para executar \n", time_taken);
    printf("lista encadeada C(n) = %d\n", c);
    printf("lista encadeada M(n)= %d\n", m);
}

void searchrg(List *list, int rg)
{
    Node *current = NULL;
    int c = 0;
    int m = 0;
    int z = 0;
    c++;
    if (list->head == NULL)
    {
        return;
    }
    else
    {
        current = list->head;
        m++;
        while (current->rg != rg)
        {
            current = current->next;
            z++;
            m++;
        }
        printf("Nome: %s\n", current->name);
        printf("RG: %d\n", current->rg);
        printf("Posição %d\n", z);
    }
    printf("lista encadeada C(n) = %d\n", c);
    printf("lista encadeada M(n)= %d\n", m);
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
