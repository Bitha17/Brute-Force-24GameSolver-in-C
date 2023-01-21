#ifndef EQUATION_H
#define EQUATION_H

typedef struct {
    int type;
    int * cards;
    char c1;
    char c2;
    char c3;
} Equation;

#define type(E) (E).type
#define cards(E) (E).cards
#define c1(E) (E).c1
#define c2(E) (E).c2
#define c3(E) (E).c3

void setEquation(Equation * Eq, int T, int * set, char a, char b, char c);

void displayEquation(Equation Eq);

void writeEqToFile(FILE * f, Equation Eq);

#endif