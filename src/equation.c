#include <stdlib.h>
#include "equation.h"

void setEquation(Equation * Eq, int T, int * set, char a, char b, char c){
    type(*Eq) = T;
    cards(*Eq) = set;
    c1(*Eq) = a;
    c2(*Eq) = b;
    c3(*Eq) = c; 
}

void displayEquation(Equation Eq){
    switch (Eq.type) {
    case 1:
        printf("(%d %c %d) %c (%d %c %d) = 24\n", Eq.cards[0], Eq.c1, Eq.cards[1], Eq.c2, Eq.cards[2], Eq.c3, Eq.cards[3]);
        break;
    
    case 2:
        printf("((%d %c %d) %c %d) %c %d = 24\n", Eq.cards[0], Eq.c1, Eq.cards[1], Eq.c2, Eq.cards[2], Eq.c3, Eq.cards[3]);
        break;

    case 3:
        printf("(%d %c (%d %c %d)) %c %d = 24\n", Eq.cards[0], Eq.c1, Eq.cards[1], Eq.c2, Eq.cards[2], Eq.c3, Eq.cards[3]);
        break;

    case 4:
        printf("%d %c ((%d %c %d) %c %d) = 24\n", Eq.cards[0], Eq.c1, Eq.cards[1], Eq.c2, Eq.cards[2], Eq.c3, Eq.cards[3]);
        break;

    case 5:
        printf("%d %c (%d %c (%d %c %d)) = 24\n", Eq.cards[0], Eq.c1, Eq.cards[1], Eq.c2, Eq.cards[2], Eq.c3, Eq.cards[3]);
        break;

    default:
        break;
    }
}