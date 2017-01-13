#ifndef ERROR_MESSAGES_H
#define ERROR_MESSAGES_H


void exit_print_error(int);

typedef struct {
	int num;
	char *error;
} error_messages;

static const error_messages number_to_message[] = {
  {.num = 20, .error = "EMPTY_PARENTHSIS"},
  {.num = 21, .error = "UNBALANCED_PARENTHESIS" },
  {.num = 22, .error = "INPUT_TOO_SHORT" },
  {.num = 23, .error = "MISORDERED_PARENTHESIS" },
  {.num = 24, .error = "INVALID_INFIX" }
};

#endif
