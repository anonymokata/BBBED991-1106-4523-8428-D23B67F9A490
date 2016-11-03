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

START_TEST (should_pass_validation_if_array_has_3_or_characters)
{
  int valid_infix = validate_infix("a+b");

  ck_assert_int_eq(valid_infix, 0);
}
END_TEST


START_TEST (should_fail_infix_validation_if_parenthesis_are_not_balanced)
{
  int valid_infix = validate_infix("(a+b");

  ck_assert_int_eq(valid_infix, 1);
}
END_TEST

START_TEST (should_pass_infix_validation_if_parenthesis_are_balanced)
{
  int valid_infix = validate_infix("(a+b)");

  ck_assert_int_eq(valid_infix, 0);
}
END_TEST

START_TEST (should_fail_infix_validation_if_operand_is_not_sourounded_by_two_operators)
{
  int valid_infix = validate_infix("(ab+)");

  ck_assert_int_eq(valid_infix, 1);
}
END_TEST

START_TEST (should_fail_infix_validation_if_operand_is_preceded_by_an_open_parenthesis)
{
  int valid_infix = validate_infix("a(+b)");

  ck_assert_int_eq(valid_infix, 1);
}
END_TEST

START_TEST (should_fail_infix_validation_if_array_length_is_less_than_3_regardless_of_parentheses)
{
  int valid_infix = validate_infix("((()))");

  ck_assert_int_eq(valid_infix, 1);
}
END_TEST

START_TEST (should_fail_infix_validation_if_parenthesis_has_no_content)

{
  int valid_infix = validate_infix("()(a+b)()");

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
  tcase_add_test(tc_validate_infix, should_pass_validation_if_array_has_3_or_characters);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_parenthesis_are_not_balanced);
  tcase_add_test(tc_validate_infix, should_pass_infix_validation_if_parenthesis_are_balanced);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_operand_is_not_sourounded_by_two_operators);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_operand_is_preceded_by_an_open_parenthesis);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_array_length_is_less_than_3_regardless_of_parentheses);
  tcase_add_test(tc_validate_infix, should_fail_infix_validation_if_parenthesis_has_no_content);


  suite_add_tcase(s, tc_validate_infix);

  return s;
}
