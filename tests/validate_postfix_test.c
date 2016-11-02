#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/validate_postfix.h"
#include "validate_postfix_test.h"


START_TEST (should_validate_ab_plus_as_valid_postfix)
{
  int valid_postfix = validate_postfix("ab+");

  ck_assert_int_eq(valid_postfix, 0);
}
END_TEST

Suite *validate_postfix_suite(void)
{
  Suite *s;
  TCase *tc_validate_postfix;

  s = suite_create("postfix validator");

  tc_validate_postfix= tcase_create("validate postfix array");

  tcase_add_test(tc_validate_postfix, should_validate_ab_plus_as_valid_postfix);

  suite_add_tcase(s, tc_validate_postfix);

  return s;
}
