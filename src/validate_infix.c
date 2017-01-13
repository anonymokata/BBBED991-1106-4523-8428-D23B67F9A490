#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int arrayLength = 0;

int validate_operator_or_operand(char *infixArray, int index) {
  char currentElement = infixArray[index];

  if (!isalnum(currentElement)) {
    arrayLength++;
    if (infixArray[index - 1] == '(' || infixArray[index + 1] == ')') {
      return 23;
    };
  } else {
    arrayLength++;
    if (infixArray[index - 1] == ')' || infixArray[index + 1] == '(') {
      return 23;
    };
  }
  return 0;
}

int validate_infix(char *infixArray) {
  int counter = 0;

  for (int index = 0; index < strlen(infixArray); index++) {
    char currentElement = infixArray[index];

    switch (currentElement) {
    case '(':
      if (infixArray[index + 1] == ')') {
        return 20;
      };
      counter++;
      break;
    case ')':
      if (counter <= 0) {
        return 21;
      };
      counter--;
      break;
    default:
      if (validate_operator_or_operand(infixArray, index) != 0) {
        return 23;
      };
    }
  }
  if (arrayLength < 3 || counter != 0) {
    return 22;
  }
  exit(EXIT_SUCCESS);
}
