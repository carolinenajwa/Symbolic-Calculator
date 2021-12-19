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

#pragma once
#include <iostream>
#include <string>

using namespace std;

// Type of tokens
enum Type { assignop, addop, mulop, divop, minop, powop, variable, number, lparen, rparen, expr };

class Token
{
private:
	// Variable store type and string values
	Type        mType_;
	string      mText_;
public:
	// Constructor
	Token();

	/** Method used to implement operator order precedence and place them in 3 categories
	*   to ease comparison of precedence among operators
	* @pre Expression/value input
	* @post Applies operator order precedence to expression
	* @returns Operators placed in 3 categories
	*/
	int getPrecedence();

	/** Method used to check that operator is valid
	* @pre Expression/value input
	* @return TRUE if operator is valid or FALSE if operator is not valid
	*/
	bool isOperator();

	/** Method used to check if opening parenthesis is valid
	* @pre Expression/value input
	* @return TRUE if opening parenthesis or FALSE if not.
	*/
	bool openingParenthesis();

	/** Method used to check if closing parenthesis is valid
	* @pre Expression/value input
	* @return TRUE if closing parenthesis or FALSE if not.
	*/
	bool closingParenthesis();

	/** Method used to create token from txt with initialization list
	* @param Type of token
	* @param String text
	* @post Initialized token
	*/
	Token(Type t, const string& txt) : mType_(t), mText_(txt) {}
	
	/** Overloaded output operator
	* @param output stream object
	* @param Object in form of token
	* @return display output stream
	*/
	friend ostream& operator<<(ostream& os, const Token& o);
	
	// Method used retrieve type
	Type getType();

	// Method used to set type
	void setType(Type type);

	// Method used to retrieve string value
	string getValue();

	/** Method used to set value
	* @param string value to set
	* @post sets value to mText
	*/
	void setValue(string value);

};
