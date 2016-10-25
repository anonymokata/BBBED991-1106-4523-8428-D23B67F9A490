#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char* postfixArray;
char* stack;

int postfixArrayPosition = 0;

void push (int position, char element){
  postfixArray[position] = element;
  postfixArrayPosition++;
}

char* convert_to_postfix(char* infixArray)
{
  int size = sizeof(infixArray)/sizeof(infixArray[0]);
  postfixArray = malloc(size);
  stack = malloc(size);

  int infixArrayPosition = 0;
  int stackPosition = 0;

  while (infixArray[infixArrayPosition] != '\0')
  {
    if (isalnum(infixArray[infixArrayPosition])) 
    {
      push(postfixArrayPosition, infixArray[infixArrayPosition]);
    } else {
      stack[stackPosition] = infixArray[infixArrayPosition];
      stackPosition++;
    }
    infixArrayPosition++;
  
  }

  while( stackPosition > 0)
  {
    push(postfixArrayPosition, stack[stackPosition -1]);
    stackPosition--;
  } 
  
  return postfixArray;
}
