#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.c"

int main(){
    srand(time(0));
    int * cards = random();
    for (int i = 0; i < 4; i++){
        printf("%d ", cards[i]);
    }
}