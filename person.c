#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "person.h"

Person* createPerson(int src, int dest)
{
    Person* res = malloc(sizeof(Person));
    res->src = src;
    res->dest = dest;
    return res;
}

PersonList* insert(Person* p, PersonList* list)
{
    PersonList* new = malloc(sizeof(PersonList));
    // PersonList *tmp = list;

    new->person = p;
    new->next = list;
    return new;
    // if (list == NULL)
    //     return new;
    // while (tmp && tmp->next != NULL)
    //     tmp = tmp->next;
    // tmp->next = new;

    // return list;
}


PersonList* emptyList() {
    PersonList* res = malloc(sizeof(PersonList));
    res->next = NULL;
    res->person = NULL;
    return res;
}

