#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int capacity;
    char *string;
    int top;
}Stack;

#define CAPACITY 100

Stack *create_stack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->string = (char *)malloc(capacity * sizeof(char));
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

int is_full(Stack *stack) {
    return stack->capacity == stack->top + 1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char c) {
    if (is_full(stack)) {
        printf("Pilha cheia.");
        return;
    }
    stack->top += 1;
    stack->string[stack->top] = c;
}

Stack *string_to_stack(char *string, int capacity) {
    Stack *stack = create_stack(capacity);

    int i = 0;
    while (string[i] != '\0') {
        push(stack, string[i]);
        i++;
    }

    return stack;
}

int find_wrong_parentheses(Stack *stack) {
    int top = stack->top;

    int left_parentheses = 0;
    int right_parentheses = 0;
    for (int i = 0; i <= top; i++) {
        if (stack->string[i] == '(')
            left_parentheses++;
        else if (stack->string[i] == ')')
            right_parentheses++;

        if (right_parentheses > left_parentheses) {
            return i;
        }
    }

    if (left_parentheses == right_parentheses) {
        return -1;
    };

    for (int j = top; j >= 0; j--) {
        if (stack->string[j] == '(')
            left_parentheses++;
        else if (stack->string[j] == ')')
            right_parentheses++;

        if (left_parentheses > right_parentheses) {
            return j;
        }
    }
}

int main() {
    char *string = malloc(CAPACITY * sizeof(char));
    scanf("%[^\n]", string);

    Stack *stack = string_to_stack(string, CAPACITY);
    printf("%d", find_wrong_parentheses(stack));
}

// ())