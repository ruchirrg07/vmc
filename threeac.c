//Write a program to generate 3 address codes along with quadruples, triples, and indirect triples 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Quadruple {
    char op;
    char arg1[10];
    char arg2[10];
    char result[10];
} Quadruple;

typedef struct Triple {
    char op;
    char arg1[10];
    char arg2[10];
} Triple;

typedef struct IndirectTriple {
    char op;
    int arg1_index;
    int arg2_index;
} IndirectTriple;

Quadruple quadruples[MAX_SIZE];
Triple triples[MAX_SIZE];
IndirectTriple indirectTriples[MAX_SIZE];

int quadIndex = 0;
int tripleIndex = 0;
int indirectIndex = 0;

void generateQuadruple(char op, char arg1[], char arg2[], char result[]) {
    quadruples[quadIndex].op = op;
    strcpy(quadruples[quadIndex].arg1, arg1);
    strcpy(quadruples[quadIndex].arg2, arg2);
    strcpy(quadruples[quadIndex].result, result);
    quadIndex++;
}

void generateTriple(char op, char arg1[], char arg2[]) {
    triples[tripleIndex].op = op;
    strcpy(triples[tripleIndex].arg1, arg1);
    strcpy(triples[tripleIndex].arg2, arg2);
    tripleIndex++;
}

void generateIndirectTriple(char op, int arg1_index, int arg2_index) {
    indirectTriples[indirectIndex].op = op;
    indirectTriples[indirectIndex].arg1_index = arg1_index;
    indirectTriples[indirectIndex].arg2_index = arg2_index;
    indirectIndex++;
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter a simple arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    char *token = strtok(expression, " ");
    char operand[MAX_SIZE], arg1[MAX_SIZE], arg2[MAX_SIZE], result[MAX_SIZE];

    while (token != NULL) {
        if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
            operand[0] = *token;
            operand[1] = '\0';
            token = strtok(NULL, " ");
            strcpy(arg1, token);
            token = strtok(NULL, " ");
            strcpy(arg2, token);
            sprintf(result, "t%d", quadIndex + 1);

            generateQuadruple(operand[0], arg1, arg2, result);
            generateTriple(operand[0], arg1, arg2);
            generateIndirectTriple(operand[0], tripleIndex - 1, tripleIndex - 2);
        }
        token = strtok(NULL, " ");
    }

    printf("\nThree Address Code:\n");
    for (int i = 0; i < quadIndex; i++) {
        printf("%s = %s %c %s\n", quadruples[i].result, quadruples[i].arg1, quadruples[i].op, quadruples[i].arg2);
    }

    printf("\nTriples:\n");
    for (int i = 0; i < tripleIndex; i++) {
        printf("(%c, %s, %s)\n", triples[i].op, triples[i].arg1, triples[i].arg2);
    }

    printf("\nIndirect Triples:\n");
    for (int i = 0; i < indirectIndex; i++) {
        printf("(%c, %d, %d)\n", indirectTriples[i].op, indirectTriples[i].arg1_index, indirectTriples[i].arg2_index);
    }

    return 0;
}
