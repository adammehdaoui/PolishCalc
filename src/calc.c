#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "../include/stack.h"
#include "../include/operation.h"

int main(int argc, char *argv[]){
    char *value = "";
    char del[] = " ";
    char *token;
    BinaryOperation* calculator = enregistreBin();

    value = readline(">>> ");
    add_history(value);

    while(strcmp(value, "q") != 0){
        if(strcmp(value, "p") == 0){
            fprintf(stderr, "Tête de pile : %d\n", head());
        }
        else if(strcmp(value, "c") == 0){
            fprintf(stderr, "Vidage de la pile \n");
            clean();
        }
        else if(strcmp(value, "a") == 0){
            print();
        }
        else if(strcmp(value, "r") == 0){
            reverse();
        }
        else{
            for(token = strtok(value, del); token != NULL; token = strtok(NULL, del)){
                if(token[0] >= '0' && token[0] <= '9') {
                    push(atoi(token));
                }
                else {
                    if(size() < 2){
                        break;
                    }
                    else {
                        push(calculator[(int)token[0]](pop(), pop()));
                    }
                }
            }
        }    

        value = readline(">>> ");
        add_history(value);   
    }

    return EXIT_SUCCESS;
}