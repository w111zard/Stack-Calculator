#include <stdio.h>
#include <stdlib.h>

#include "stack_numbers.h"

double stack_numbers[STACK_NUMBERS_MAX_SIZE];
size_t stack_numbers_size = 0;

void stack_numbers_push(double number) {
  if (stack_numbers_size + 1 <= STACK_NUMBERS_MAX_SIZE) {
    stack_numbers[stack_numbers_size++] = number;
  }
  else {
    dprintf(2, "[!] Program has stoped! Can't add the number '%f'. Stack with numbers is full!\n", number);
    exit(EXIT_FAILURE);
  }
}

double stack_numbers_pop() {
  if (stack_numbers_size > 0) {
    return stack_numbers[--stack_numbers_size];
  }
  else {
    dprintf(2, "[!] Program has stoped! Can't return a element from stack with numbers. Stack is empty!\n");
    exit(EXIT_FAILURE);
  }
}
