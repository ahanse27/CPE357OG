#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entry{
    char* county;
    char* state;

    float eduBach;
    float eduHigh;

    float ethniAmerInd;
    float ethniAsian;
    float ethniBlack;
    float ethniHisp;
    float ethniPacif;
    float ethniTwoorMore;
    float ethniWhite;
    float ethniWhiteNoHisp;

    int incomeMedHouse;
    int incomePerCap;
    float incomePerPerson;

    int pop2014;
};

//Function Declarations
void displayCounty();
struct Entry *createEntry(int);


#endif
