#include "queuelinked.h"
#include "equation.h"

char ops[] = {'+', '-', '*', '/'};

float res(float a, float b, char c){
    if (c == '+'){
        return a + b;
    } else if (c == '-'){
        return a - b;
    } else if (c == '*'){
        return a * b;
    } else {
        return a / b;
    }
}

int eval(Queue * q, int * set, char c1, char c2, char c3, int count){
    float res1 = res(set[0], set[1], c1);   // a + b
    float res2 = res(set[1], set[2], c2);   // b + c
    float res3 = res(set[2], set[3], c3);   // c + d
    float res4 = res(res1, set[2], c2);     // (a + b) + c
    float res5 = res(set[0], res2, c1);     // a + (b + c)
    float res6 = res(res2, set[3], c3);     // (b + c) + d
    float res7 = res(set[1], res3, c2);     // b + (c + d)

    Equation eq;

    // (a + b) + (c + d)
    if (res(res1,res3,c2) == 24.00){
        setEquation(&eq, 1, set, c1, c2, c3);
        enqueue(q, eq);
        count++;
    }
    // ((a + b) + c) + d
    if (res(res4,set[3],c3) == 24.00){
        setEquation(&eq, 2, set, c1, c2, c3);
        enqueue(q, eq);        
        count++;
    }
    // (a + (b + c)) + d
    if (res(res5,set[3],c3) == 24.00){
        setEquation(&eq, 3, set, c1, c2, c3);
        enqueue(q, eq);        
        count++;
    }
    // a + ((b + c) + d)
    if (res(set[0],res6,c1) == 24.00){
        setEquation(&eq, 4, set, c1, c2, c3);
        enqueue(q, eq);        
        count++;
    }
    // a + (b + (c + d))
    if (res(set[0],res7,c1) == 24.00){
        setEquation(&eq, 5, set, c1, c2, c3);
        enqueue(q, eq);        
        count++;
    }
    return count;
}