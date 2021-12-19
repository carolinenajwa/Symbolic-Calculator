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
Token class:
The tokens will include a member which will indicate the type of data that it holds and the string value of it
*/

#include "Token.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor 
Token::Token() {}

/** Method used to implement operator order precedence and place them in 3 categories
*   to ease comparison of precedence among operators
* @pre Expression/value input
* @post Applies operator order precedence to expression
* @returns Operators placed in 3 categories
*/
int Token::getPrecedence()
{
	switch (this->mType_)
	{
	case mulop:
	case divop:
		return 3;
	case addop:
	case minop:
		return 2;
	case powop:
		return 1;
	}
}

/** Method used to check that operator is valid
* @pre Expression/value input
* @return TRUE if operator is valid or FALSE if operator is not valid
*/
bool Token::isOperator()
{
	return this->mType_ == addop || this->mType_ == minop || this->mType_ == mulop || this->mType_ == divop || this->mType_ == powop;
}

/** Method used to check if opening parenthesis is valid
	* @pre Expression/value input
	* @return TRUE if opening parenthesis or FALSE if not.
	*/
bool Token::openingParenthesis()
{
	return this->mType_ == lparen;
}

/** Method used to check if closing parenthesis is valid
	* @pre Expression/value input
	* @return TRUE if closing parenthesis or FALSE if not.
	*/
bool Token::closingParenthesis()
{
	return this->mType_ == rparen;
}

/** Overloaded output operator 
* @param output stream object
* @param Object in form of token
* @return display output stream
*/
ostream& operator<<(ostream& os, const Token& o)
{
	return os << o.mText_;
}

// Method used retrieve type
Type Token::getType() 
{
	return this->mType_;
}

// Method used to set type
void Token::setType(Type type) 
{
	this->mType_ = type;
}

// Method used to retrieve string value
string Token::getValue() 
{
	return this->mText_;
}

/** Method used to set value
* @param string value to set
* @post sets value to mText
*/
void Token::setValue(string value) 
{
	this->mText_ = value;
}
