/**
 Caroline El Jazmi
 UW ID: 1942686
 CSS 501
 Program 4 - A Symbolic Algebra Calculator
*/

/**
This program implements a symbolic algebra calculator, which is a more complex calculator than the standard calculators.
The following are some of the key features of the symbolic calculator:
• It can use variables
• It stores the structure of the expressions entered
• It can evaluate expressions and sub-expressions by substituting the variables with their associated values
• It can perform transformations on expressions
The program will read algebraic expressions and attempt to solve them. Objectives to this program includes:
• To have an in-depth understanding of the tree data structures and their respective algorithms
• To understand and make use of basic input parsing by use of tokens
Driver:
Symbolic Algebra Calculator user interface wont promp user,
but it will echo its input. Each input expression will display on a single line.
The Symbolic Algebra Calculator will read from an user input
*/

#include "SymbolicAlgebraCalculator.h"

// User interface
int main()
{
	SymbolicAlgebraCalculator calc;
	calc.run();
	return 0;
};
