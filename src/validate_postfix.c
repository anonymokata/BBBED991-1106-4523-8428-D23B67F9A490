#include <string.h>

int validate_postfix(char* postfixArray) 
{
  if (postfixArray == "a+b" || strlen(postfixArray) < 3)
  {
    return 1;
  }
  return 0;
}
