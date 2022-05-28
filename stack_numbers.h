#ifndef __STACK_NUMBERS_H__
#define __STACK_NUMBERS_H__

enum {
  STACK_NUMBERS_MAX_SIZE = 100
};

extern double stack_numbers[STACK_NUMBERS_MAX_SIZE];
extern size_t stack_numbers_size;

void stack_numbers_push(double number);
double stack_numbers_pop();

#endif /* #ifndef __STACK_NUMBERS_H__ */
