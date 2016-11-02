#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "postfix_to_infix_test.h"
#include "infix_to_postfix_test.h"
#include "validate_postfix_test.h"
#include "validate_infix_test.h"

int main (void)
{
  int number_failed;
  Suite *postfix_to_infix;
  Suite *infix_to_postfix;
  Suite *validate_postfix;
  Suite *validate_infix;
  SRunner *sr;

  postfix_to_infix=postfix_to_infix_suite();
  infix_to_postfix=infix_to_postfix_suite();
  validate_postfix=validate_postfix_suite();
  validate_infix=validate_infix_suite();

  sr = srunner_create(infix_to_postfix);
  srunner_add_suite(sr, postfix_to_infix);
  srunner_add_suite(sr, validate_postfix);
  srunner_add_suite(sr, validate_infix);

  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
