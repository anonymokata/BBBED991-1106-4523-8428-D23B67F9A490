#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "error_messages.h"
void exit_print_error(int err) {
  for (int j =0; j < 5; j++) {
    if(number_to_message[j].num == err) {
      printf("[DEBUG] Infix Validation Failed, Error: %s\n", number_to_message[j].error);
      exit(err);
    }
  }
}
