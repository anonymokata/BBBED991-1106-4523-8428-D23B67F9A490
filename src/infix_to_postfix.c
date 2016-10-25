#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char* postfixArray;
char* stack;

char* convert_to_postfix(char* infixArray)
{
  int size = sizeof(infixArray)/sizeof(infixArray[0]);
  postfixArray = malloc(size);
  stack = malloc(size);

  int array = 0;
  int position = 0;
  int stackPosition = 0;
  while (infixArray[position] != '\0')
  {
    if (isalnum(infixArray[position])) 
    {
      postfixArray[array] = infixArray[position];
      array++;  
    } else {
      stack[stackPosition] = infixArray[position];
      stackPosition++;
    }
    position++;
  
  }

  while( stackPosition > 0)
  {
    postfixArray[array] = stack[stackPosition -1];
    array++;
    stackPosition--;
  } 
  
  return postfixArray;
}
