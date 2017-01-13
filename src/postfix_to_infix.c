#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "validate_postfix.h"
#include "error_messages.h"

struct node {
  char element;
  struct node *previous;
  struct node *next;
} *stack;

typedef struct node node;
node *firstMostNode;
node *lastMostNode;
node *link;

void push_to_stack(node *link, int index) {
  stack[index] = *link;
  index++;
}

node *pop(int index) {
  node *lastLink;
  lastLink = &stack[index - 1];
  index--;
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

char *recurse_list(node *chain, int index, char *finalArray) {
  if (chain -> next) {
    finalArray[index] = chain -> element;
    index++;
    recurse_list(chain -> next, index, finalArray);
  } else {
    finalArray[index] = chain -> element;
    finalArray[index + 1] = '\0';
  }
  return finalArray;
}

node *create_link(char value) {
  link = (node *) malloc(sizeof(node));
  link -> element = value;
  link -> next = NULL;
  link -> previous = NULL;
  return link;
}

char *get_string(node *chain, int arraySize, int index) {
  char array;
  return recurse_list(chain, index, &array);
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

char *convert_to_infix(char *postfixString) {

  int success = validate_postfix(postfixString);
  if (success != 0) {
    exit_print_error(success);
  };

  node *operand1;
  node *operand2;
  int indexLocation = 0;
  int position = 0;
  int stackIndex = 0;

  while (postfixString[position] != '\0') {
    char currentElement = postfixString[position];

    if (isalnum(currentElement)) {
      push_to_stack(create_link(currentElement), stackIndex);
    } else {
      operand1 = pop(stackIndex);
      operand2 = pop(stackIndex);

      set_first_node(operand1);
      set_last_node(operand2);

      create_link(currentElement);

      prepend_to_list(link);
      append_to_list(link);

      push_to_stack(add_parenthesis(link), stackIndex);
    }
    position++;
  }
  set_first_node(pop(stackIndex));
  char *stringArray = get_string(firstMostNode, sizeof(postfixString), indexLocation);
  free(operand1);
  free(operand2);
  return stringArray;
};
