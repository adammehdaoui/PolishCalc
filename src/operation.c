#include <stdlib.h>

#include "../include/operation.h"

int addition(int a, int b){
    return a + b;
}

int soustraction(int a, int b){
    return a - b;
}

int multiplication(int a, int b){
    return a * b;
}

int division(int a, int b){
    return a / b;
}

int modulo(int a, int b){
    return a % b;
}

int factorielle(int a){
    if(a == 0){
        return 1;
    }

    return factorielle(a - 1) * a;
}

int puissance(int a, int b){
    if(a == 0){
        return 1;
    }

    return puissance(a, b - 1) * a;
}

BinaryOperation* enregistreBin(){
    BinaryOperation* calculator = malloc(sizeof(BinaryOperation)*64);
    calculator['+'] = addition;
    calculator['-'] = soustraction;
    calculator['*'] = multiplication;
    calculator['/'] = division;
    calculator['%'] = modulo;
    calculator['^'] = puissance;
    return calculator;
}

UnaryOperation* enregistreUna(){
    UnaryOperation* calculator = malloc(sizeof(UnaryOperation)*4096);
    calculator['!'] = factorielle;
    return calculator;
}