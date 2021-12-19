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
SymbolicAlgebraCalculator:
This class is used to run the symbolic calculator
*/

#pragma once
#include "IO.h"
#include "Tokenizer.h"
#include "ExpresionConverter.h"
#include "AST.h"

#include <map>
#include <set>

class SymbolicAlgebraCalculator
{
private:

	IO io;
	Tokenizer tokenizer_;
	ExpresionConverter converter_;
	// Initialize variable store
	map<string, Token> variableStore;
	// Initialize vectors
	vector<string> variables;
	vector<Token> postFix;

public:
	SymbolicAlgebraCalculator() { }

	/* Method reads and run line of expression through symbolic calculator
	* @pre Expression/value input
	* @post If sucessful, passes string line of expression through the symbolic calculator
	*/
	void run();

	/** Method to run calculator by checking if expression is valid and simplifying it
	* @param String line input
	* @pre Expression/value input
	* @post If successful, line expression is solved
	*/
	void runCalculator(string line);
};
