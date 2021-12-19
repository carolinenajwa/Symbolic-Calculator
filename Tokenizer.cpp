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
Tokenizer Class:
This component will create tokens from strings (sequence of characters) read in from standard input.
*/


#include "Tokenizer.h"
#include "Token.h"
#include <algorithm>
#include <vector>

/** Constructor
* Declares isAssigned and valid bool methods
*/
Tokenizer::Tokenizer()
{
	this->assigned = false;
	this->valid = false;
}

/** Method used to check if input is valid by accessing bool valid
* @pre bool valid is declared
* @return TRUE if input is valid or FALSE if input is not valid
*/
bool Tokenizer::isValid()
{
	return this->valid;
}

/** Method used to check if input is valid by accessing bool valid
* @pre bool valid is declared
* @return TRUE if input is valid or FALSE if input is not valid
*/
bool Tokenizer::isAssigned()
{
	return this->assigned;
}

/** Method used to retrieve variable name
* @pre Expression/value input
* @post If variable has been assigned, returns variable name
* @return string variable name
*/
string Tokenizer::getVariableName()
{
	return this->assigned ? this->variableName_ : "";
}


/** Method used to break down input stream into a stream of tokens
* @param string input
* @post If successful, checks for valid input and tokenizes string input
* @return input string into tokenized stream
*/
vector<Token> Tokenizer::tokenize(string input)
{
	string variable_name = "";
	this->assigned = false;
	this->valid = true;

	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	// vector of string to save tokens
	vector<Token> result;

	if (input.length() == 1 && !isdigit(input[0]))
	{
		this->assigned = true;
		this->variableName_ = input;
		return result;
	}

	for (auto curr = begin(input); curr != end(input); ++curr)
	{
		switch (*curr) {
		case '+':
			result.emplace_back(addop, "+");
			break;
		case '^':
			result.emplace_back(powop, "^");
			break;
		case '-':
			result.emplace_back(minop, "-");
			break;
		case '*':
			result.emplace_back(mulop, "*");
			break;
		case '/':
			result.emplace_back(divop, "/");
			break;
		case '(':
			result.emplace_back(lparen, "(");
			break;
		case ')':
			result.emplace_back(rparen, ")");
			break;
		case ':':
			curr++;

			if (*curr == '=') { // assignment operator 
				this->assigned = true;
				this->variableName_ = variable_name;
			}
			else
			{
				this->valid = false;
				result.clear();
				return result;
			}
			break;

		default:
			// variable
			char c = *curr;
			if (!isdigit(c))
			{
				auto first_semicolon = find_if(curr, end(input), [](auto c)
					{
						return !isalpha(c);
					});
				variable_name = string(curr, first_semicolon);
				result.emplace_back(variable, variable_name);
				curr = --first_semicolon;
				//cout << "Variable: " << this->variable_name << endl;
			}
			else
			{
				// number
				auto first_not_digit = find_if(curr, end(input), [](auto c)
					{
						return !isdigit(c);
					});
				string integer = string(curr, first_not_digit);
				result.emplace_back(number, integer);
				curr = --first_not_digit;
				//cout << "Number: " << integer << endl;
			}
		}
	}
	return result;
}
