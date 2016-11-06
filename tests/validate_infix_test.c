#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/validate_infix.h"
#include "validate_infix_test.h"



START_TEST (should_fail_validation_if_array_is_less_than_3_characters)
{
  validate_infix("a+");
}
END_TEST

START_TEST (should_pass_validation_if_array_has_3_or_characters)
{
  validate_infix("a+b");
}
END_TEST

START_TEST (should_fail_infix_validation_if_parenthesis_are_not_balanced)
{
  validate_infix("(a+b");
}
END_TEST

START_TEST (should_pass_infix_validation_if_parenthesis_are_balanced)
{
  validate_infix("(a+b)");
}
END_TEST

START_TEST (should_fail_infix_validation_if_operand_is_not_sourounded_by_two_operators)
{
  validate_infix("(ab+)");
}
END_TEST

START_TEST (should_fail_infix_validation_if_operand_is_preceded_by_an_open_parenthesis)
{
  validate_infix("a(+b)");

}
END_TEST

START_TEST (should_fail_infix_validation_if_array_length_is_less_than_3_regardless_of_parentheses)
{
  validate_infix("((()))");
}

END_TEST

START_TEST (should_fail_infix_validation_if_parenthesis_has_no_content)
{
  validate_infix("()(a+b)()");
}

END_TEST

START_TEST (should_fail_infix_validation_if_parenthesis_are_misordered)
{
  validate_infix("a)v+c-d(b");
}

END_TEST

START_TEST (should_fail_infix_validation_if_operands_are_not_explicitly_expressed)
{
  validate_infix("a(v+c-d)b");
}

END_TEST

START_TEST (should_raise_signal_upon_failure_of_validation)
{
  validate_infix("(ab+)");
}
END_TEST

Suite *validate_infix_suite(void)
{
  Suite *s;
  TCase *tc_validate_infix;

  s = suite_create("infix validator");

  tc_validate_infix= tcase_create("validate infix array");

  tcase_add_exit_test(tc_validate_infix, should_fail_validation_if_array_is_less_than_3_characters,1 );
  tcase_add_exit_test(tc_validate_infix, should_pass_validation_if_array_has_3_or_characters, 0);
  tcase_add_exit_test(tc_validate_infix, should_fail_infix_validation_if_parenthesis_are_not_balanced, 1);
  tcase_add_exit_test(tc_validate_infix, should_pass_infix_validation_if_parenthesis_are_balanced, 0);
  tcase_add_exit_test(tc_validate_infix, should_fail_infix_validation_if_operand_is_not_sourounded_by_two_operators, 1);
  tcase_add_exit_test(tc_validate_infix, should_fail_infix_validation_if_operand_is_preceded_by_an_open_parenthesis, 1);
  tcase_add_exit_test(tc_validate_infix, should_fail_infix_validation_if_array_length_is_less_than_3_regardless_of_parentheses, 1);
  tcase_add_exit_test(tc_validate_infix, should_fail_infix_validation_if_parenthesis_has_no_content, 1);
  tcase_add_exit_test(tc_validate_infix, should_fail_infix_validation_if_parenthesis_are_misordered, 1);
  tcase_add_exit_test(tc_validate_infix, should_fail_infix_validation_if_operands_are_not_explicitly_expressed, 1);
  tcase_add_exit_test(tc_validate_infix, should_raise_signal_upon_failure_of_validation, 1);


  suite_add_tcase(s, tc_validate_infix);

  return s;
}
