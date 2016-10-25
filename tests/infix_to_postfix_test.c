#include <stdlib.h>
#include <check.h>
#include <stdio.h>
#include "../src/infix_to_postfix.h"
#include "infix_to_postfix_test.h"

START_TEST (a_plus_b_should_return_a_b_plus)
{
  char* postfix = convert_to_infix("a+b");

  ck_assert_str_eq(postfix, "ab+");
}
END_TEST


Suite *infix_to_postfix_suite(void)
{
  Suite *s;
  TCase *tc_convert_to_postfix;

  s = suite_create("infix to postfix converter");

  tc_convert_to_postfix = tcase_create("Convert to postfix");

  tcase_add_test(tc_convert_to_postfix, a_plus_b_should_return_a_b_plus);

  suite_add_tcase(s, tc_convert_to_postfix);

  return s;
}

int main (void)
{
  int number_failed;
  Suite *infix_to_postfix;
  SRunner *sr;

  infix_to_postfix = infix_to_postfix_suite();

  sr = srunner_create(infix_to_postfix);

  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
