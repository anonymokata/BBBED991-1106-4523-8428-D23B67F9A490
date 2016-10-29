#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* infixArray;

char* convert_to_infix(char* postfixArray){
  infixArray = malloc(100);
  infixArray[0] =postfixArray[0];
  infixArray[1] = postfixArray[2];
  infixArray[2] = postfixArray[1];

  return infixArray;
};
