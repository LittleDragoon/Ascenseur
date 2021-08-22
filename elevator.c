#include "elevator.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Elevator* create_elevator(int capacity, int currentFloor, PersonList* persons)
{
    Elevator* res = malloc(sizeof(Elevator));

    res->capacity = capacity;
    res->currentFloor = currentFloor;
    res->persons = persons;

    return res;
}

Building* create_building(int nbFloor, Elevator* elevator, PersonList** waitingLists)
{
    Building* res = malloc(sizeof(Building));

    res->nbFloor = nbFloor;
    res->elevator = elevator;
    res->waitingLists = waitingLists;

    return res;
}

PersonList* exitElevator(Elevator* e)
{


    PersonList* res = emptyList();

    PersonList* tmp = e->persons;

    while (tmp && tmp->person) {

        if (tmp->person->dest == e->currentFloor) {
            //La personne sort et on retire 1 au nombre de personnes dans l'ascenseur
            e->currentNumber -= 1;
        }
        else
        {
            // On ajoute la personne qui reste dans l'ascenseur
            res = insert(tmp->person, res);
        }
        tmp = tmp->next;
    }
    //Je renvoie la liste des personnes qui restent dans l'ascenseur
    return res;
}

PersonList* enterElevator(Elevator* e, PersonList* list)
{

    PersonList* res = e->persons;

    while (e->currentNumber < e->capacity && list->person) {
        res = insert(list->person, res);
        e->currentNumber += 1;
        if (list->next != NULL) {
            *list = *(list->next);
        }
        else
        {
            *list = *emptyList();
        }

    }
    return res;
}

void stepElevator(Building* b)
{
    Elevator* elev = b->elevator;
    if (elev->currentFloor == elev->targetFloor) {
        elev->persons = exitElevator(elev);
        //elev->persons = enterElevator(elev, b->waitingLists[b->elevator->currentFloor]);
    }
    else {
        if (elev->currentFloor > elev->targetFloor) {
            (elev->currentFloor) -= 1;
        }
        else {
            (elev->currentFloor) += 1;
        }
    }
}
