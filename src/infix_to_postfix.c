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

  while (infixArray[position] != '\0')
  {
    if (isalnum(infixArray[position])) 
    {
      postfixArray[array] = infixArray[position];
      array++;  
    } else {
      stack[0] = infixArray[position];
    }
    position++;
  
  }

  postfixArray[array] = stack[0];
  
  return postfixArray;
}
