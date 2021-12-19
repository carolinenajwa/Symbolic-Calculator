/**
Caroline El Jazmi
UW ID: 1942686
CSS 501
Program 4 - A Symbolic Algebra Calculator
*/

/**
Program Description:
This program implements a symbolic algebra calculator, which is a more complex calculator than the standard calculators.
The following are some of the key features of the symbolic calculator:
• It can use variables
• It stores the structure of the expressions entered
• It can evaluate expressions and sub-expressions by substituting the variables with their associated values
• It can perform transformations on expressions
The program will read algebraic expressions and attempt to solve them. Objectives to this program includes:
• To have an in-depth understanding of the tree data structures and their respective algorithms
• To understand and make use of basic input parsing by use of tokens
ExpressionConverter Class:
This utility class will offer conversion functionality between infix and postfix expressions
*/

#pragma once
#include "Token.h"
#include <stack>
#include <vector>

class ExpressionConverter
{
public:
	/** Method used to convert infix expression to postfix
 * @param Vector of token
 * @pre Expression/value input
 * @post If successful, will convert infix to postfix
 * @return postfix expression
 */
	vector<Token> toPostFix(vector<Token> expression);

};
