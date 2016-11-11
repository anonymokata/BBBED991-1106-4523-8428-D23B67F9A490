#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "validate_infix.h"

char* postfixArray;
char* stack;

int postfixArrayPosition = 0;
int stackPosition = 0;
int infixArrayPosition = 0;

int get_presidence(char element) 
{
  switch(element)
  {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
  }
  return 0;
}

void push(int position, char element)
{
  postfixArray[position] = element;
  postfixArrayPosition++;
}

void dump_stack()
{
  while( stackPosition > 0)
  {
    push(postfixArrayPosition, stack[stackPosition -1]);
    stackPosition--;
  } 
}

void push_stack(char element)
{
  stack[stackPosition] = element;
  stackPosition++;
}

void build_postfix(char element)
{
  if (isalnum(element))
  {
    push(postfixArrayPosition, element);
  } else 
  {
    if (get_presidence(element) < get_presidence(stack[stackPosition -1])){
      dump_stack();
    }
    push_stack(element);
   }
}

char* convert_to_postfix(char* infixArray)
{
  validate_infix(infixArray);

  postfixArray = malloc(sizeof(char) * sizeof(infixArray));
  stack = malloc(sizeof(char) * sizeof(infixArray));
  
  while (infixArray[infixArrayPosition] != '\0')
  {
    if (infixArray[infixArrayPosition] == '(')
    {
      push_stack(infixArray[infixArrayPosition]);
      infixArrayPosition++;
    }
    else if (infixArray[infixArrayPosition] == ')')
    {
      infixArrayPosition++;
      while(stack[stackPosition-1] != '(')
      {
        push(postfixArrayPosition, stack[stackPosition-1]);
        stackPosition--;
      }
        stackPosition--;
    } else {
    build_postfix(infixArray[infixArrayPosition]);
    infixArrayPosition++;
    }
  }

  dump_stack(); 
  free(stack);
  push(infixArrayPosition, '\0');

  return postfixArray;
}
