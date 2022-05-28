#ifndef __STACK_OPERATIONS_H__
#define __STACK_OPERATIONS_H__

enum {
  STACK_OPERATIONS_MAX_SIZE = 100
};

extern char stack_operations[STACK_OPERATIONS_MAX_SIZE];
extern size_t stack_operations_size;

void stack_operations_push(char operation);
char stack_operations_pop();

#endif /* #ifndef __STACK_OPERATIONS_H__ */
