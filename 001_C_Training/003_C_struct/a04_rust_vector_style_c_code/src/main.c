#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;       // Similar to Vec's pointer to heap memory
    size_t len;      // Similar to Vec::len()
    size_t capacity; // Similar to Vec::capacity()
} Stack;

// Similar to Vec::with_capacity(capacity)
Stack stack_new(size_t capacity) {
    Stack stack;

    stack.data = malloc(sizeof(int) * capacity);

    if (stack.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    stack.len = 0;
    stack.capacity = capacity;

    return stack;
}

// Similar to Vec::push()
void stack_push(Stack *stack, int value) {
    // Grow the vector if it is full
    if (stack->len == stack->capacity) {
        size_t new_capacity = stack->capacity * 2;

        int *new_data = realloc(stack->data, sizeof(int) * new_capacity);

        if (new_data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }

        stack->data = new_data;
        stack->capacity = new_capacity;
    }

    // Put the value at the end
    stack->data[stack->len] = value;

    printf("Value: %d | Address: %p\n", value,
           (void *)&stack->data[stack->len]);

    stack->len++;
}

// Similar to Vec::pop()
int stack_pop(Stack *stack, int *result) {
    if (stack->len == 0) {
        return 0; // false: nothing to pop
    }

    stack->len--;

    printf("Popped %d <- Memory Address: %p\n", stack->data[stack->len],
           (void *)&stack->data[stack->len]);

    *result = stack->data[stack->len];

    return 1; // true: successfully popped
}

// Similar to Rust's automatic Drop for Vec
void stack_free(Stack *stack) {
    free(stack->data);

    stack->data = NULL;
    stack->len = 0;
    stack->capacity = 0;
}

int main(void) {
    Stack stack = stack_new(5);

    printf("--- Pushing to Stack ---\n");

    stack_push(&stack, 10);
    stack_push(&stack, 20);
    stack_push(&stack, 30);

    printf("\n--- Popping from Stack ---\n");

    int value;

    if (stack_pop(&stack, &value)) {
        printf("Returned value: %d\n", value);
    }

    if (stack_pop(&stack, &value)) {
        printf("Returned value: %d\n", value);
    }

    // C requires us to free the memory manually.
    stack_free(&stack);

    return 0;
}
