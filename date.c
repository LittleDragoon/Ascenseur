#include <stdio.h>
#include <stdlib.h>
#include "date.h"

// Fonction qui renvoie un pointeur qui pointe vers Date
Date *create_date(int day, int month, int year)
{

    Date *res = malloc(sizeof(Date));
    res->jour = day;
    res->mois = month;
    res->annees = year;
    return res;
}

void print_date(Date *date)
{

    printf("[%d/%d/%d]\n", date->jour, date->mois, date->annees);
}
