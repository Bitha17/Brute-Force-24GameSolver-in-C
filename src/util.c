/* File: util.c */

#include <stdio.h>
#include <stdlib.h>

char cardlist[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};

int * random(){
    static int card[4];
    printf("Your random cards are: \n");
    for (int i = 0; i < 4; i++){
        card[i] = rand() % 13 + 1;
        if (card[i] == 10){
            printf("10 ");
        } else{
            printf("%c ", cardlist[card[i] - 1]);
        }
    }
    printf("\n");
    return card;
}

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}