#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int validate_postfix(char *postfixArray) {
  int counter = 0;

  for (int i = 0; i < strlen(postfixArray); i++) {
    if (isalnum(postfixArray[i])) {
      counter++;
    } else {
      if (counter < 2) {
        return 24;
      }
      counter -= 2;
      counter++;
    }
  }

  if (counter != 1 || strlen(postfixArray) < 3) {
    return 22;
  }
  exit(EXIT_SUCCESS);
}
