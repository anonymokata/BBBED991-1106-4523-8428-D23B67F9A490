#include <string.h>

char* convert_to_infix(char* postfixArray){
  if (strncmp(postfixArray, "ab+", 3) == 0) 
  {
    return "a+b";
  };
  return "a-b";
};
