#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void validate_postfix(char *postfixArray) {
  int counter = 0;

  for (int i = 0; i < strlen(postfixArray); i++) {
    if (isalnum(postfixArray[i])) {
      counter++;
    } else {
      if (counter < 2) {
        exit(EXIT_FAILURE);
      }
      counter -= 2;
      counter++;
    }
  }

  if (counter != 1 || strlen(postfixArray) < 3) {
    exit(EXIT_FAILURE);
  }
}