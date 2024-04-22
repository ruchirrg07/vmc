//Implement LR parser
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 30

char stack[MAX_STACK_SIZE];
int top = -1;

void push(char c) {
    if (top < MAX_STACK_SIZE - 1) {
        top++;
        stack[top] = c;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop() {
    if (top != -1) {
        char c = stack[top];
        top--;
        return c;
    }
    return 'x';
}

void printStack() {
    printf("\n\t\t\t$");
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);
}

int main() {
    char input[20];
    printf("\n\n\t\t LR PARSING");
    printf("\n\t\t ENTER THE EXPRESSION: ");
    scanf("%s", input);

    int length = strlen(input);

    printf("\n\t\t $");
    for (int i = 0; i < length; i++) {
        if (input[i] == 'i' && input[i + 1] == 'd') {
            input[i] = ' ';
            input[i + 1] = 'E';
            printStack();
            printf("id");
            push('E');
            printStack();
            i++; // Skip the next character as it's already processed
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == 'd') {
            push(input[i]);
            printStack();
        }
    }

    // Pop remaining elements and check
    while (top != -1) {
        char ch1 = pop();
        if (ch1 == '+' || ch1 == '-' || ch1 == '*' || ch1 == '/') {
            char ch2 = pop();
            if (ch2 != 'E') {
                printf("Error\n");
                return 1;
            } else {
                push('E');
                printStack();
            }
        }
    }

    printf("\n");
    return 0;
}
