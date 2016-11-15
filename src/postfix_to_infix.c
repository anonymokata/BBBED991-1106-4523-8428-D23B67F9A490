#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "validate_postfix.h"

struct node {
  char element;
  struct node *previous;
  struct node *next;
} *stack[3];

typedef struct node node;
int stackIndex = 0;
char *array;
int indexLocation = 0;
node *firstMostNode;
node *lastMostNode;
node *link;

void push_to_stack(node *link) {
  stack[stackIndex] = link;
  stackIndex++;
}

node *pop() {
  node *lastLink;
  lastLink = stack[stackIndex - 1];
  stackIndex--;
  return lastLink;
}

void set_last_node(node *link) {
  if (link -> next != NULL) {
    set_last_node(link -> next);
  } else {
    lastMostNode = link;
  }
}

void set_first_node(node *link) {
  if (link -> previous != NULL) {
    set_first_node(link -> previous);
  } else {
    firstMostNode = link;
  }
}

char *recurse_list(node *chain) {
  if (chain -> next) {
    array[indexLocation] = chain -> element;
    indexLocation++;
    recurse_list(chain -> next);
  } else {
    array[indexLocation] = chain -> element;
    array[indexLocation + 1] = '\0';
  }
  return array;
}

node *create_link(char value) {
  link = (node *) malloc(sizeof(node));
  link -> element = value;
  link -> next = NULL;
  link -> previous = NULL;
  return link;
}

char *get_string(node *chain, int arraySize) {
  array = malloc(arraySize *sizeof(char));
  return recurse_list(chain);
}

void prepend_to_list(node *link) {
  firstMostNode -> previous = link;
  link -> next = firstMostNode;
}

void append_to_list(node *link) {
  lastMostNode -> next = link;
  link -> previous = lastMostNode;
}

node *add_parenthesis(node *link) {
  set_first_node(link);
  set_last_node(link);

  node *open = create_link('(');
  node *close = create_link(')');

  prepend_to_list(open);
  append_to_list(close);
  return firstMostNode;
}

char *convert_to_infix(char *postfixArray) {
  validate_postfix(postfixArray);

  node *operand1;
  node *operand2;
  int position = 0;

  while (postfixArray[position] != '\0') {
    char currentElement = postfixArray[position];

    if (isalnum(currentElement)) {
      push_to_stack(create_link(currentElement));
    } else {
      operand1 = pop();
      operand2 = pop();

      set_first_node(operand1);
      set_last_node(operand2);

      create_link(currentElement);

      prepend_to_list(link);
      append_to_list(link);

      push_to_stack(add_parenthesis(link));
    }
    position++;
  }
  set_first_node(pop());
  char *stringArray = get_string(firstMostNode, sizeof(postfixArray));
  free(operand1);
  free(operand2);
  return stringArray;
};