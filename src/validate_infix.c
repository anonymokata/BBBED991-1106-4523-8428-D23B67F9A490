/*
 * check valid parenthesis:
 * initialize counter, 
 * open parens++;
 * close parens--;
 * if parens value ever less than 0, invalid
 * if parens == 0 therefore valid, 
 *
 * this will only work if you limit the shortest array to be 3 (without including parenthesis)
 *
 * validate operands:
 * only two situations: either is is between parenthesis or oparators.
 * the parenthesis on eitherside cant be the same type.
 */

#include <string.h>
#include <ctype.h>
int validate_infix(char* infixArray)
{
  int counter= 0;
  int length = 0;
  for (int i =0; i < strlen(infixArray); i++)
  {
    if (infixArray[i] == '(')
    {
      counter++;
        if (infixArray[i + 1] == ')') { return 1; };

    }
    else if (infixArray[i] == ')')
    {
      if (counter <= 0) { return 1;  };
      counter--;
    }
    else if (!isalnum(infixArray[i]))
    {
        length++;
        if (infixArray[i - 1] == '(' || infixArray[i + 1] == ')') { return 1; };
    }
    else
    {
      length++;
        if (infixArray[i - 1] == ')' || infixArray[i + 1] == '(') { return 1; };
    }
  }
  if (length < 3 || counter != 0 ) 
  {
    return 1;
  }
  return 0;
}
