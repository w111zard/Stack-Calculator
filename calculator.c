#include <stdio.h>
#include <stdlib.h>

#include "calculator.h"
#include "stack_numbers.h"
#include "stack_operations.h"

static int get_token_type(char *token);
static int get_priority(char operation);
static void apply_operation(char operation);
static char *get_next_token(char *expression);

static char *last_index = NULL; // for function get_next_token() 

static int get_token_type(char *token) {
  if ((*token >= '0') && (*token <= '9'))
    return NUMBER;
  if (*token == '(')
    return OPENNING_BRACKET;
  if (*token == ')')
    return CLOSING_BRACKET;
  else
    return OPERATION;
}

static int get_priority(char operation) {
  if ((operation == '+') || (operation == '-'))
    return 1;
  if ((operation == '*') || (operation == '/'))
    return 2;
  else
    return 0;
}

static void apply_operation(char operation) {
  double value_1 = stack_numbers_pop();
  double value_2 = stack_numbers_pop();
  
  switch (operation) {
  case '+':
    stack_numbers_push(value_2 + value_1);
    break;

  case '-':
    stack_numbers_push(value_2 - value_1);
    break;

  case '*':
    stack_numbers_push(value_2 * value_1);
    break;

  case '/':
    if (value_1 == 0) {
      dprintf(2, "[!] Program has stoped! Detected division by zero!\n");
      exit(EXIT_FAILURE);
    }
    stack_numbers_push(value_2 / value_1);
  }
}

static char *get_next_token(char *expression) {
  if (last_index == NULL)
    last_index = expression;

  if (*last_index == '\0')
    return NULL;

  while (*last_index == ' ') {
    ++last_index;
    if (*last_index == '\0')
      return NULL;
  }
  
  char *result = last_index;
  
  if (*last_index >= '0' && *last_index <= '9') {
    strtod(result, &last_index);
    return result;
  }
  else {
    ++last_index;
    return result;
  }
}

double calculate(char *expression) {
  char *token;
  token = get_next_token(expression);
  while (token != NULL) {
    int token_type = get_token_type(token);
    switch (token_type) {
    case NUMBER:
      // convert token from *char to double
      double value = strtod(token, NULL);
      stack_numbers_push(value);
      break;
      
    case OPERATION:
      if (stack_operations_size > 0) {
	char operation_from_stack = stack_operations_pop();
	while (get_priority(operation_from_stack) >= get_priority(*token)) {
	  apply_operation(operation_from_stack);
	  if (stack_operations_size == 0)
	    break;
	  operation_from_stack = stack_operations_pop();
	}
	if (get_priority(operation_from_stack) < get_priority(*token)) {
	  stack_operations_push(operation_from_stack);
	}
	stack_operations_push(*token);
      }
      else {
	stack_operations_push(*token);
      }
      break;
      
    case OPENNING_BRACKET:
      stack_operations_push(*token);
      break;
      
    case CLOSING_BRACKET:
      char operation_from_stack = stack_operations_pop();
      while (operation_from_stack != '(') {
	apply_operation(operation_from_stack);
	operation_from_stack = stack_operations_pop();
      }
      break;
    }

    token = get_next_token(expression);
  }

  while (stack_operations_size > 0) {
    char operation_from_stack = stack_operations_pop();
    apply_operation(operation_from_stack);
  }
  
  return stack_numbers_pop();
}
