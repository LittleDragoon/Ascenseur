#ifndef PERSONNE
#define PERSONNE

typedef struct _Person Person;
struct _Person
{
    char *fname;
    char *name;
    Date *birth;
};

Person *creer_personne(char prenom[], char nom[], int jour, int mois, int annee);
void print_person(Person *person);

#endif