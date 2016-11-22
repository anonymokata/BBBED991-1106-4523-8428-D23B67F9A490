#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "validate_infix.h"

char *postfixArray;
char *stack;

int postfixArrayPosition = 0;
int stackPosition = 0;
int infixStringPosition = 0;

int get_precedence(char element) {
  switch (element) {
  case '+':
    return 1;
  case '-':
    return 1;
  case '*':
    return 2;
  case '/':
    return 2;
  case '^':
    return 3;
  }
  return 0;
}

void push(int position, char element) {
  postfixArray[position] = element;
  postfixArrayPosition++;
}

void dump_stack() {
  while (stackPosition > 0) {
    push(postfixArrayPosition, stack[stackPosition - 1]);
    stackPosition--;
  }
}

void push_stack(char element) {
  stack[stackPosition] = element;
  stackPosition++;
}

void build_postfix(char element) {
  if (isalnum(element)) {
    push(postfixArrayPosition, element);
  } else {
    if (get_precedence(element) < get_precedence(stack[stackPosition - 1])) {
      dump_stack();
    }
    push_stack(element);
  }
}

char *convert_to_postfix(char *infixString) {
  validate_infix(infixString);

  postfixArray = malloc(sizeof(char) * strlen(infixString));
  stack = malloc(sizeof(char) * strlen(infixString));

  while (infixString[infixStringPosition] != '\0') {
    if (infixString[infixStringPosition] == '(') {
      push_stack(infixString[infixStringPosition]);
      infixStringPosition++;
    } else if (infixString[infixStringPosition] == ')') {
      infixStringPosition++;
      while (stack[stackPosition - 1] != '(') {
        push(postfixArrayPosition, stack[stackPosition - 1]);
        stackPosition--;
      }
      stackPosition--;
    } else {
      build_postfix(infixString[infixStringPosition]);
      infixStringPosition++;
    }
  }

  dump_stack();
  free(stack);
  push(infixStringPosition, '\0');

  return postfixArray;
}
