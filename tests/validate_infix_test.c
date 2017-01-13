#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/validate_infix.h"
#include "validate_infix_test.h"

START_TEST(should_fail_validation_if_array_is_less_than_3_characters) {
  ck_assert_int_eq(validate_infix("a+"),22);
}
END_TEST

START_TEST(should_pass_validation_if_array_has_3_or_characters) {
    ck_assert_int_eq(validate_infix("a+b"),0);
}
END_TEST

START_TEST(should_fail_infix_validation_if_parenthesis_are_not_balanced) {
      ck_assert_int_eq(validate_infix("(a+b"),22);
}
END_TEST

START_TEST(should_pass_infix_validation_if_parenthesis_are_balanced) {
  ck_assert_int_eq(validate_infix("(a+b)"),0);
}
END_TEST

START_TEST(should_fail_infix_validation_if_operand_is_not_sourounded_by_two_operators) {
  ck_assert_int_eq(validate_infix("(ab+)"),23);
}
END_TEST

START_TEST(should_fail_infix_validation_if_operand_is_preceded_by_an_open_parenthesis) {
  ck_assert_int_eq(validate_infix("a(+b)"),23);
}
END_TEST

START_TEST(should_fail_infix_validation_if_array_length_is_less_than_3_regardless_of_parentheses) {
  ck_assert_int_eq(validate_infix("((()))"),20);
}

END_TEST

START_TEST(should_fail_infix_validation_if_parenthesis_has_no_content) {
  ck_assert_int_eq(validate_infix("()(a+b)()"),20);
}

END_TEST

START_TEST(should_fail_infix_validation_if_parenthesis_are_misordered) {
  ck_assert_int_eq(validate_infix("a)v+c-d(b"),21);
}

END_TEST

START_TEST(should_fail_infix_validation_if_operands_are_not_explicitly_expressed) {
  ck_assert_int_eq(validate_infix("a(v+c-d)b"),23);
}

END_TEST

START_TEST(should_raise_signal_upon_failure_of_validation) {
  ck_assert_int_eq(validate_infix("(ab+)"),23);
}
END_TEST

Suite *validate_infix_suite(void) {
  Suite *s;
  TCase *tc_validate_infix;

  s = suite_create("infix validator");

  tc_validate_infix = tcase_create("validate infix array");

  tcase_add_test(tc_validate_infix, should_fail_validation_if_array_is_less_than_3_characters);
  tcase_add_test(tc_validate_infix, should_pass_validation_if_array_has_3_or_characters);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_parenthesis_are_not_balanced);
  tcase_add_test(tc_validate_infix, should_pass_infix_validation_if_parenthesis_are_balanced);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_operand_is_not_sourounded_by_two_operators);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_operand_is_preceded_by_an_open_parenthesis);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_array_length_is_less_than_3_regardless_of_parentheses);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_parenthesis_has_no_content);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_parenthesis_are_misordered);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_operands_are_not_explicitly_expressed);
  tcase_add_test(tc_validate_infix, should_raise_signal_upon_failure_of_validation);

  suite_add_tcase(s, tc_validate_infix);

  return s;
}
