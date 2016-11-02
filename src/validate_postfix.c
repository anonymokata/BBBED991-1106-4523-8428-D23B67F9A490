#include <string.h>
#include <ctype.h>
#include <stdio.h>

int validate_postfix(char* postfixArray) 
{
  int counter = 0;

  for (int i =0; i < strlen(postfixArray); i++)
  {

    if (isalnum(postfixArray[i]))
    {
      counter++;
    }
    else {

      counter-=2;
      counter++;
    }
  }

  if (counter != 1 || strlen(postfixArray) < 3) { return 1; }

  return 0;
}
