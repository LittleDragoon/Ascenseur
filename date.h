#ifndef DATE
#define DATE

typedef struct _Date
{
    int jour;
    int mois;
    int annees;
} Date;

Date *create_date(int day, int month, int year);
void print_date(Date *date);
#endif
