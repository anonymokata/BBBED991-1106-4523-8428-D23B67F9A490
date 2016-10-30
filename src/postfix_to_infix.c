#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int stackIndex = 0;
static char* array;
static int location;
struct node
{
  char element;
  struct node *previous;
  struct node *next;
} *stack[10000000];

typedef struct node node;

node *first_most_node;
node *last_right_node;
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

void get_last_node(node *link)
{
  if (link -> next != NULL)
  {
    get_last_node(link->next);
  }
  else
  {
    last_right_node = link; 
  }
}

void get_first_node(node *link)
{
  if (link -> previous != NULL)
  {
    get_first_node(link->previous);
  }
  else
  {
    first_most_node = link;
  }
}
static int status = 0;
static int locate = 0;
char* recurseList(node* chain)
{
  if (chain->next)
  {
    array[locate] = chain->element;
    locate++;
    recurseList(chain->next);
  }else {
    array[locate] = chain->element;
  }
  return array;
}

char* getString(node* chain)
{
  array = malloc(22300);
  location = 0;
  return recurseList(chain);
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

      link = (node*)malloc(sizeof(node));
      link->element = postfixArray[position];
      get_first_node(operand1);
      node *lastLink = first_most_node;
      link->next = lastLink;
      lastLink->previous = link;
      get_last_node(operand2);
      node *firstLink = last_right_node;
      link->previous  = firstLink;
      firstLink->next = link;

      push_to_stack(link);

    }
    position++;
  }
  get_first_node(pop());
  return getString(first_most_node);
};
