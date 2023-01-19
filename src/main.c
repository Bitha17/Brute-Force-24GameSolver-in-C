#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.c"
#include "evaluator.c"
#include "swap.c"

int permutations[24][4];
int pcount = 0;

void permute(int * card, int l){
    if (l == 4){
        for (int i = 0; i < 4; i++){
            permutations[pcount][i] = card[i];
        }
        pcount++;
    } else {
        for (int i = l; i < 4; i++){
            int duplicate = 0;
            for (int j = l; j < i; j++){
                if (card[i] == card[j]){
                    duplicate = 1;
                }
            }
            if (!duplicate){
                swap(card + l, card + i);
                permute(card, l + 1);
                swap(card + l, card + i);
            }
        }
    }
}

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

    char ops[] = {'+', '-', '*', '/'};

    int count = 0;
    int m = 0;
    permute(cards, 0);
    while (m < pcount){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                for (int k = 0; k < 4; k++){
                    count = eval(permutations[m], ops[i], ops[j], ops[k], count);
                }
            }
        }
        m++;
    }

    printf("count: %d\n", count);
}