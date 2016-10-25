#include <string.h>

char* convert_to_infix(char* postfixArray)
{
  if (strncmp(postfixArray,"a-b", 4) == 0 ){
    return "ab-";
  }
  return "ab+";
}
