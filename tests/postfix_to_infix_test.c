#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/postfix_to_infix.h"
#include "postfix_to_infix_test.h"

START_TEST(should_convert_postfix_expression_with_plus_operator) {

  char *result = convert_to_infix("ab+");
  ck_assert_str_eq(result, "(a+b)");
  free(result);
}
END_TEST

START_TEST(should_convert_postfix_expression_with_minus_operator) {

  char *result = convert_to_infix("ab-");
  ck_assert_str_eq(result, "(a-b)");
  free(result);
}
END_TEST

START_TEST(should_convert_postfix_expression_with_multiplication_operator) {

  char *result = convert_to_infix("ab*");
  ck_assert_str_eq(result, "(a*b)");
  free(result);
}
END_TEST

START_TEST(should_convert_postfix_expression_with_addiiton_and_subtraction_operators) {

  char *result = convert_to_infix("abc-+");
  ck_assert_str_eq(result, "(a+(b-c))");
  free(result);
}
END_TEST


START_TEST(should_convert_postfix_expression_with_division_operator) {

  char *result = convert_to_infix("ab/");
  ck_assert_str_eq(result, "(a/b)");
  free(result);
}
END_TEST

START_TEST(should_convert_postfix_expression_with_exponents_operators) {

  char *result = convert_to_infix("ab^");
  ck_assert_str_eq(result, "(a^b)");
  free(result);
}
END_TEST


START_TEST(should_convert_postfix_expression_with_respect_to_precedence) {

  char *result = convert_to_infix("ab*cd/+");
  ck_assert_str_eq(result, "((a*b)+(c/d))");
  free(result);
}
END_TEST

START_TEST(should_convert_postfix_expression_with_multiple_operators_and_operands) {

  char *result = convert_to_infix("ag+ba-c+cedf^*+^*");
  ck_assert_str_eq(result, "((a+g)*(((b-a)+c)^(c+(e*(d^f)))))");
  free(result);
}
END_TEST

START_TEST(should_exit_with_status_1_if_postfix_validation_fails) {
  convert_to_infix("a+b");
}
END_TEST

Suite *postfix_to_infix_suite(void) {
  Suite *s;
  TCase *tc_convert_to_infix;

  s = suite_create("postfix to infix converter");

  tc_convert_to_infix = tcase_create("Convert to infix");

  tcase_add_test(tc_convert_to_infix, should_convert_postfix_expression_with_plus_operator);
  tcase_add_test(tc_convert_to_infix, should_convert_postfix_expression_with_minus_operator);
  tcase_add_test(tc_convert_to_infix, should_convert_postfix_expression_with_multiplication_operator);
  tcase_add_test(tc_convert_to_infix, should_convert_postfix_expression_with_addiiton_and_subtraction_operators);
  tcase_add_test(tc_convert_to_infix, should_convert_postfix_expression_with_division_operator);
  tcase_add_test(tc_convert_to_infix, should_convert_postfix_expression_with_exponents_operators);
  tcase_add_test(tc_convert_to_infix, should_convert_postfix_expression_with_respect_to_precedence);
  tcase_add_test(tc_convert_to_infix, should_convert_postfix_expression_with_multiple_operators_and_operands);
  tcase_add_exit_test(tc_convert_to_infix, should_exit_with_status_1_if_postfix_validation_fails, 24);

  suite_add_tcase(s, tc_convert_to_infix);

  return s;
}
