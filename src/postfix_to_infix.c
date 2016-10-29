#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stackIndex = 0;
char* array;
int location;
struct node
{
  char element;
  struct node *previous;
  struct node *next;

} *stack[10000000];
typedef struct node node;

void push_to_stack(node *link)
{
  stack[stackIndex] = link;
  stackIndex++;
}

node *pop()
{
  node *lastLink;
  lastLink = stack[stackIndex - 1];
  stackIndex--;
  return lastLink;
}

char* getString(node* chain)
{
  array = malloc(10);
  array[0] = chain->previous->element;
    array[1] = chain->element;
    array[2] = chain->next->element;
    array[3] = '\0';
  return array;
}

char* convert_to_infix(char* postfixArray){
  node *operand1;
  node *operand2;
  node *link;
  int position = 0;
  while (postfixArray[position] != '\0')

  {
    if (isalnum(postfixArray[position]))
    {
      link = (node*)malloc(sizeof(node));
      link -> element = postfixArray[position];
      link -> next = NULL;
      link -> previous  = NULL;

      push_to_stack(link);
    } else
    {
      operand1 = pop();
      operand2 = pop();

      printf("should be BBBBB %c\n", operand1->element);
      printf("should be AAAAAA %c\n", operand2->element);
      link = (node*)malloc(sizeof(node));
      link->element = postfixArray[position];
      link->next = operand1;
      link->previous  = operand2;

      push_to_stack(link);

    }
    position++;
  }

  return getString(pop());
};
