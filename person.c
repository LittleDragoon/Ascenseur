#include <stdlib.h>
#include <stdio.h>
#include "date.h"
#include "person.h"

int main()
{
    char prenom[] = "Benjamin";
    char nom[] = "ZHU";
    int jour = 20;
    int mois = 2;
    int annee = 2000;
    Person *moi = creer_personne(prenom, nom, jour, mois, annee);
    print_person(moi);
    return 0;
}

Person *creer_personne(char prenom[], char nom[], int jour, int mois, int annee)
{
    Person *res = malloc(sizeof(Person));
    res->fname = prenom;
    res->name = nom;
    res->birth = create_date(jour, mois, annee);
    return res;
}

void print_person(Person *person)
{
    printf("%s %s est né le ", person->fname, person->name);
    print_date(person->birth);
}