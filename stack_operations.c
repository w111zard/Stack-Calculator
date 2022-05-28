#include <stdio.h>
#include <stdlib.h>

#include "stack_operations.h"

char stack_operations[STACK_OPERATIONS_MAX_SIZE];
size_t stack_operations_size = 0;

void stack_operations_push(char operation) {
  if (stack_operations_size + 1 <= STACK_OPERATIONS_MAX_SIZE) {
    stack_operations[stack_operations_size++] = operation;
  }
  else {
   dprintf(2, "[!] Program has stoped! Can't add the operation '%c'. Stack with operatons is full!\n", operation);
   exit(EXIT_FAILURE); 
  }
}

char stack_operations_pop() {
  if (stack_operations_size > 0) {
    return stack_operations[--stack_operations_size];
  }
  else {
    dprintf(2, "[!] Program has stoped! Can't return a element from stack with operations. Stack is empty!\n");
    exit(EXIT_FAILURE);
  }
}
