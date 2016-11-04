#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

struct node
{
  char element;
  struct node *previous;
  struct node *next;
} *stack[110];

typedef struct node node;
int stackIndex = 0;
char* array;
int indexLocation = 0;
node *first_most_node;
node *last_most_node;
node *link;

void push_to_stack(node *link)
{
  stack[stackIndex] = link;
  stackIndex++;
}

node* pop()
{
  node *lastLink;
  lastLink = stack[stackIndex - 1];
  stackIndex--;
  return lastLink;
}

void set_last_node(node *link)
{
  if (link->next != NULL)
  {
    set_last_node(link->next);
  } else {
    last_most_node = link; 
  }
}

void set_first_node(node *link)
{
  if (link->previous != NULL)
  {
    set_first_node(link->previous);
  } else {
    first_most_node = link;
  }
}

char* recurseList(node* chain)
{
  if (chain->next)
  {
    array[indexLocation] = chain->element;
    indexLocation++;
    recurseList(chain->next);
  } else {
    array[indexLocation] = chain->element;
    array[indexLocation + 1] = '\0';
  }
  // free up chain memory
  return array;
}

node* createNode(char value) {
  link = (node*)malloc(sizeof(node));
  link -> element = value;
  link -> next = NULL;
  link -> previous  = NULL;
  return link;
}

char* getString(node* chain, int arraySize)
{
  array = malloc(arraySize * sizeof(char));
  return recurseList(chain);
}

void prependToList(node* link){
  first_most_node->previous = link;
  link->next = first_most_node;
}

void appendToList(node* link){
  last_most_node->next = link;
  link->previous = last_most_node;
}

node* add_parenthesis(node *link) {
  set_first_node(link);
  set_last_node(link);

  node* open = createNode('(');
  node* close = createNode(')');

  prependToList(open);
  appendToList(close);
  return first_most_node;
}

char* convert_to_infix(char* postfixArray){
  node *operand1;
  node *operand2;
  int position = 0;

  while (postfixArray[position] != '\0')
  {
        char currentElement =postfixArray[position];
    if (isalnum(currentElement))
    {
      push_to_stack(createNode(currentElement));
    } else {
      operand1 = pop();
      operand2 = pop();

      set_first_node(operand1);
      set_last_node(operand2);

      createNode(currentElement);

      prependToList(link);
      appendToList(link);

      push_to_stack(add_parenthesis(link));
    }
    position++;
  }
  set_first_node(pop());
  return getString(first_most_node, sizeof(postfixArray));
};
