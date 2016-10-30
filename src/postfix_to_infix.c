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

char* getString(node* chain)
{
  array = malloc(200);

  array[0] = chain->element;
  array[1] = chain->next->element;
  array[2] = chain->next->next->element;
  array[3] = chain->next->next->next->element;
  node *c_node = chain->next->next->next->next;
  array[4] = c_node->element;
  printf("this is array[4] %c\n", array[4]);
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
