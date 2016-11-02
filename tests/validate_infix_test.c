#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/validate_infix.h"
#include "validate_infix_test.h"



START_TEST (foo)
{
  int valid_infix = validate_infix("foo");

  ck_assert_int_eq(valid_infix, 0);
}
END_TEST

Suite *validate_infix_suite(void)
{
  Suite *s;
  TCase *tc_validate_infix;

  s = suite_create("infix validator");

  tc_validate_infix= tcase_create("validate infix array");

  tcase_add_test(tc_validate_infix, foo);

  suite_add_tcase(s, tc_validate_infix);

  return s;
}
