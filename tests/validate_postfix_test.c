#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/validate_postfix.h"
#include "validate_postfix_test.h"

START_TEST(should_validate_ab_plus_as_valid_postfix) {
  ck_assert_int_eq(validate_postfix("ab+"), 0);
}
END_TEST

START_TEST(should_validate_a_plus_b_as_invalid_postfix) {
  ck_assert_int_eq(validate_postfix("a+b"), 24);
}
END_TEST

START_TEST(should_validate_a_as_invalid_postfix) {
  ck_assert_int_eq(validate_postfix("a"), 22);
}
END_TEST

START_TEST(should_validate_a_plus_b_minus_as_invalid_postfix) {
  ck_assert_int_eq(validate_postfix("a+b-"), 24);
}
END_TEST

START_TEST(should_exit_with_status_1_on_invalid_postfix) {
  ck_assert_int_eq(validate_postfix("a+b-"), 24);
}
END_TEST

START_TEST(should_validate_postfix_expression_with_multiple_operators_as_valid_postfix) {
  ck_assert_int_eq(validate_postfix("ag+ba-c+cedf^*+^*"), 0);
}
END_TEST

Suite *validate_postfix_suite(void) {
  Suite *s;
  TCase *tc_validate_postfix;

  s = suite_create("postfix validator");

  tc_validate_postfix = tcase_create("validate postfix array");

  tcase_add_test(tc_validate_postfix, should_validate_ab_plus_as_valid_postfix);
  tcase_add_test(tc_validate_postfix, should_validate_a_plus_b_as_invalid_postfix);
  tcase_add_test(tc_validate_postfix, should_validate_a_as_invalid_postfix);
  tcase_add_test(tc_validate_postfix, should_validate_a_plus_b_minus_as_invalid_postfix);
  tcase_add_test(tc_validate_postfix, should_validate_postfix_expression_with_multiple_operators_as_valid_postfix);
  tcase_add_test(tc_validate_postfix, should_exit_with_status_1_on_invalid_postfix);

  suite_add_tcase(s, tc_validate_postfix);

  return s;
}
