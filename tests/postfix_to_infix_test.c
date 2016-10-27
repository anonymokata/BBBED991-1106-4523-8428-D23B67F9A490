#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/postfix_to_infix.h"
#include "postfix_to_infix_test.h"



START_TEST (convert_postfix_to_infix)
{
  char* postfix = convert_to_infix("ab+");

  ck_assert_str_eq(postfix, "a+b");
}
END_TEST

START_TEST (convert_a_b_minus_to_a_subtract_b)
{
  char* postfix = convert_to_infix("ab-");

  ck_assert_str_eq(postfix, "a-b");
}
END_TEST

Suite *postfix_to_infix_suite(void)
{
  Suite *s;
  TCase *tc_convert_to_infix;

  s = suite_create("postfix to infix converter");

  tc_convert_to_infix = tcase_create("Convert to infix");

  tcase_add_test(tc_convert_to_infix, convert_postfix_to_infix);
  tcase_add_test(tc_convert_to_infix, convert_a_b_minus_to_a_subtract_b);

  suite_add_tcase(s, tc_convert_to_infix);

  return s;
}
