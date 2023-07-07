#ifndef OPERATIONS_H
#define OPERATIONS_H

struct Header{
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

    int incMedHouse;
    int incPerCap;
    float incPerPerson;

    int pop2014;
};

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

    int incMedHouse;
    int incPerCap;
    float incPerPerson;

    int pop2014;
};

//Function Declarations
void displayCounty();


#endif