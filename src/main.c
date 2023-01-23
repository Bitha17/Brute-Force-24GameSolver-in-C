/* File : main.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "boolean.h" 
#include "queuelinked.c"
#include "equation.c"
#include "util.c"
#include "evaluator.c"

int permutations[24][4];
int pcount = 0;
char ten[2] = {'1','0'};

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
    clock_t start, end;
    boolean valid = false;
    int choice;
    Queue q;
    CreateQueue(&q);
    while (!valid){
        printf("How would you like to input the cards?\n  1. Manually from the keyboard\n  2. Use the random generator\n\nInput choice number: ");
        scanf("%d", &choice);
        if (choice == 1 || choice == 2){
            valid = true;
        }
    }
    int * cards;
    switch (choice){
    case 1:
        char temp[2];
        int i = 0;
        boolean invalid = false;
        while (i < 4){
            scanf("%s", &temp);
            boolean found = false;
            for (int j = 0; j < 13; j++){
                if (j == 9){
                    if (strcmp(temp,ten) == 0){
                        cards[i] = 10;
                        found = true;
                        break;
                    }
                } else if (temp[0] == cardlist[j] && strlen(temp) == 1){
                    cards[i] = j + 1;
                    found = true;
                    break;
                }
            }
            i++;
            if (!found){
                invalid = true;
            } 
            if (i == 4){
                if (invalid){
                    printf("Card Invalid Found! Please re-enter 4 cards!\n");
                    i = 0;
                    invalid = false;
                }
            }     
        }        
        break;
    case 2:
        cards = random();
        break;
    default:
        break;
    }

    char ops[] = {'+', '-', '*', '/'};

    start = clock();
    int count = 0;
    int m = 0;
    permute(cards, 0);
    while (m < pcount){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                for (int k = 0; k < 4; k++){
                    count = eval(&q,permutations[m], ops[i], ops[j], ops[k], count);
                }
            }
        }
        m++;
    }
    end = clock();

    printf("There are %d solution(s)\n", count);
    DisplayQueue(q);

    // Execution time
    double exec_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", exec_time);

    // Save to file
    int choice2;
    boolean valid2 = false;
    while (!valid2){
        printf("Would you like to safe to file?\n  1. Yes\n  2. No\n\nInput choice number: ");
        scanf("%d", &choice2);
        if (choice2 == 1 || choice2 == 2){
            valid2 = true;
        }
    }

    switch (choice2) {
    case 1:
        boolean fvalid = false;
        char file[50];
        while (!fvalid){
            printf("Name of file with extension (.txt): ");
            scanf("%s", &file);
            int l = strlen(file);
            if (l > 4 && file[l - 4] == '.' && file[l - 3] == 't' && file[l - 2] == 'x' && file[l - 1] == 't'){
                fvalid = true;
            }
        }
        char path[100] = "../test/";
        for (int i = 0; i < strlen(file); i++){
            path[8+i] = file[i];
        }
        FILE *fptr;
        fptr = fopen(path, "w");
        if (fptr == NULL){
            printf("Error!\n");
        } else {
            fprintf(fptr, "Cards: ");
            for (int i = 0; i < 4; i++){
                if (cards[i] == 10){
                    fprintf(fptr, "10 ");
                } else{
                    fprintf(fptr, "%c ", cardlist[cards[i] - 1]);
                }
            }
            fprintf(fptr, "\nThere are %d solution(s)\n", count);
            if (!isEmpty(q)){
                Address p = ADDR_HEAD(q);
                while (NEXT(p) != NULL){
                    writeEqToFile(fptr, p->Eq);
                    p = NEXT(p);
                }
                writeEqToFile(fptr, p->Eq);
            }
        }
        fclose(fptr);
        break;
    
    default:
        break;
    }
}