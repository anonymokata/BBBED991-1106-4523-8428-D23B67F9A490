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

int validate_infix(char* infixArray)
{
  int counter= 0;
  for (int i =0; i < strlen(infixArray); i++)
  {
        if (infixArray[i] == '(')
        {
          counter++;
        }
        else if (infixArray[i] == ')')
        {
          counter--;
        }
  }
  if (strlen(infixArray) < 3 || counter != 0 ) 
  {
    return 1;
  }
  return 0;
}
