#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.c"
#include "evaluator.c"

int main(){
    srand(time(0));
    printf("How would you like to input the cards?\n  1. Manually from the keyboard\n  2. Use the random generator\n\ninput choice number: ");
    int choice;
    scanf("%d", &choice);
    int * cards;
    switch (choice){
    case 1:
        printf("Enter 4 cards\n");
        break;
    case 2:
        cards = random();
        break;
    default:
        break;
    }
    for (int i = 0; i < 4; i++){
        printf("card numbers: %d\n", cards[i]);
    }

    char ops[] = {'+', '-', '*', '/'};

    int count = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                count = eval(cards, ops[i], ops[j], ops[k], count);
            }
        }
    }
    printf("count: %d\n", count);
}