#include <stdio.h>

#include "../include/stack.h"

static int stack[256];
static int current = 0;

void push(int value){
    stack[current++] = value;
}

int pop(){
    return stack[--current];
}

int size(){
    return current;
}

int clean(){
    current = 0;
}

void print(){
    int i;
    for(i = 0; i < current; i++){
        fprintf(stdout, "%d\n", stack[i]);
    }
}

void reverse(){
    int tmp = stack[current-1];
    stack[current-1] = stack[current-2];
    stack[current-2] = tmp;
}

int head(){
    return stack[current-1];
}
