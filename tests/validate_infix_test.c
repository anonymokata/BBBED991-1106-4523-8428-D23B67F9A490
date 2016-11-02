#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/validate_infix.h"
#include "validate_infix_test.h"



START_TEST (should_fail_validation_if_array_is_less_than_3_characters)
{
  int valid_infix = validate_infix("a+");

  ck_assert_int_eq(valid_infix, 1);
}
END_TEST

Suite *validate_infix_suite(void)
{
  Suite *s;
  TCase *tc_validate_infix;

  s = suite_create("infix validator");

  tc_validate_infix= tcase_create("validate infix array");

  tcase_add_test(tc_validate_infix, should_fail_validation_if_array_is_less_than_3_characters);

  suite_add_tcase(s, tc_validate_infix);

  return s;
}
