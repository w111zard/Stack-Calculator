#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

enum {
  NUMBER,
  OPERATION,
  OPENNING_BRACKET,
  CLOSING_BRACKET
};

double calculate(char *expression);

#endif /* #ifndef __CALCULATOR_H__ */
