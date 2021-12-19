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


#include "SymbolicAlgebraCalculator.h"
#include "IO.h"
#include "Tokenizer.h"
#include "ExpresionConverter.h"
#include "AST.h"

#include <map>
#include <set>

/* Method reads and run line of expression through symbolic calculator
* @pre Expression/value input
* @post If sucessful, passes string line of expression through the symbolic calculator
*/
void SymbolicAlgebraCalculator::run()
{
	string line;
	while (true)
	{
		line = io.read();
		if (line == ".")
			break;
		this->runCalculator(line);
	}
}


/** Method to run calculator by checking if expression is valid and simplifying it
* @param String line input
* @pre Expression/value input
* @post If successful, line expression is solved
*/
void SymbolicAlgebraCalculator::runCalculator(string line) 
{
	vector<Token> tokens = tokenizer_.tokenize(line);
	//cout << "Tokens:\n";
	if (tokenizer_.isValid()) 
	{
		if (tokenizer_.isAssigned()) 
		{
			if (find(variables.begin(), variables.end(), tokenizer_.getVariableName()) == variables.end()) {
				variableStore[tokenizer_.getVariableName()] = Token(variable, tokenizer_.getVariableName());
				variables.push_back(tokenizer_.getVariableName());
			}
		}
		if (tokens.size() > 0) 
		{
			if (tokenizer_.isAssigned())
				tokens.erase(tokens.begin());
			postFix = converter_.toPostFix(tokens);
			//cout << "Postfix:\n";
			AST ast(postFix);
			ast.simplify(variableStore);
			if (tokenizer_.isAssigned()) 
			{
				variableStore[tokenizer_.getVariableName()] = Token(ast.isExpression() ? expr : number, ast.toInfix());
			}
			io.displayOutput(ast.toInfix());
		}
		else 
		{
			if (variableStore[tokenizer_.getVariableName()].getType() == expr) 
			{
				tokens = tokenizer_.tokenize(variableStore[tokenizer_.getVariableName()].getValue());
				//cout << "Tokenization complete\n";
				postFix = converter_.toPostFix(tokens);
				//cout << "Postfixing complete\n";
				AST ast(postFix);
				ast.simplify(variableStore);
				//cout << "Simplifying complete\n";
				io.displayOutput(ast.toInfix());
			}
			else {
				cout << "Variable not an expression\n";
				io.displayOutput(variableStore[tokenizer_.getVariableName()].getValue());
			}
		}
	}
	else {
		io.displayOutput("Invalid expression");
	}
}
