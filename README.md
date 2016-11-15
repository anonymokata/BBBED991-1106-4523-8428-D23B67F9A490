# Reverse Polish Notation

**To run the the program/tests:**

```make test```


# Library API

**infix\_to\_postfix.h**

```char* convert_to_postfix(char* infixArray);```

This function takes an infix string of any length and returns a char array consisting of the equivalent postfix expression

**postfix\_to\_infix.h**

```char* convert_to_infix(char* postfixArray);```

This function takes a postfix string of any length and returns a char array consisting of the equivalent infix expression

**validate\_postfix.h**

```void validate_postfix(char*);```

This function exits with a status 1 if invalid postfix is entered as an argument.

**validate\_infix.h**

```void validate_infix(char*);```

This function exits with a status 1 if invalid infix is entered as an argument


# Logic

**Infix-to-Postfix Conversion**

1. Validate infix expression entered by user

2. Iterate through Infix expression

3. If the current element is an open parenthesis, push it on to the stack

4. If the element is an alpha numeric, push the element on to the output array

5. If the element is an operator and its precedence is less than that of the last operator on the stack, dump the entire stack onto the output array else add it on to the stack and continue iterating.

6. If the element is a closed parenthesis, push everything that is in the stack on to the output array until the first open parenthesis and delete that from the stack.

7. repeat steps 1-6 until the end of the infix expression. Once at the end, dump all remaining elements from the stack into the output array.

**Postfix-to-Infix Conversion**

1. Validate postfix expression entered by user

2. Iterate through input postfix expression

3. If the element is an alpha numeric, push it on to the stack

4. If the element is an operand then pop the last 2 operands from the stack (n &amp; n-1).

a. prepend operator n to the current operand and append operator n-1 to the current operand

b. surround expression with parenthesis

c. then push all three on to the stack as a single object.

5. Repeat until end of input array.


# Acknowledgments

Although this kata was completed in a test driven manner, there was a significant amount of refactoring done in the process which in hindsight created opportunities for additional unit tests to be written to test out the extracted functions. For this iteration of the kata, these opportunities were not taken advantage of and will be something to be considered in the future.

Additionally, as part of the convert\_to\_infix function, a structure called node was created as well as a pointer to a stack array with a fixed size of 3. This is not the most flexible solution as it is hard coded putting the program in danger of returning an incorrect solution if a stack larger than three is required. This is obviously not ideal and should be allocated on compilation and would be a potential bug fix for a future refactor.
