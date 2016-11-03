#include <string.h>
#include <ctype.h>

int validate_infix(char* infixArray)
{
  int counter= 0;
  int arrayLength = 0;

  for (int i =0; i < strlen(infixArray); i++)
  {
    char currentElement = infixArray[i];
    if (currentElement == '(')
    {
      if (infixArray[i + 1] == ')') { return 1; };
      counter++;
    }
    else if (currentElement == ')')
    {
      if (counter <= 0) { return 1; };
      counter--;
    }
    else if (!isalnum(currentElement))
    {
      arrayLength++;
      if (infixArray[i - 1] == '(' || infixArray[i + 1] == ')') { return 1; };
    }
    else
    {
      arrayLength++;
      if (infixArray[i - 1] == ')' || infixArray[i + 1] == '(') { return 1; };
    }
  }
  if (arrayLength < 3 || counter != 0 ) 
  {
    return 1;
  }
  return 0;
}
