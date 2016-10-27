#include <stdlib.h>
#include <check.h>
#include <stdio.h>
#include "../src/infix_to_postfix.h"
#include "infix_to_postfix_test.h"

static char* infix_to_postfix[12][2] = {
  {"a+b", "ab+"},
  {"a-b", "ab-"},
  {"a*b", "ab*"},
  {"a/b", "ab/"},
  {"a^b", "ab^"},
  {"a+b-c", "abc-+"},
  {"a*b+c", "ab*c+"},
  {"a*b+c/d", "ab*cd/+"},
  {"a^b+c", "ab^c+"},
  {"l/m^n*o-p", "lmn^/o*p-"},
  {"(a+b)-c", "ab+c-"},
  {"((v/w)^x)*(y-z)", "vw/x^yz-*"}
};

START_TEST (convert_infix_to_postfix_loop)
{
  char* postfix = convert_to_postfix(infix_to_postfix[_i][0]);

  ck_assert_str_eq(postfix, infix_to_postfix[_i][1]);
}
END_TEST

Suite *infix_to_postfix_suite(void)
{
  Suite *s;
  TCase *tc_convert_to_postfix;

  s = suite_create("infix to postfix converter");

  tc_convert_to_postfix = tcase_create("Convert to postfix");

  tcase_add_loop_test(tc_convert_to_postfix, convert_infix_to_postfix_loop, 0, 12);

  suite_add_tcase(s, tc_convert_to_postfix);

  return s;
}
