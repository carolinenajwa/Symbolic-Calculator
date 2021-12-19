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


#pragma once
#include "Token.h"
#include <algorithm>
#include <vector>

class Tokenizer
{
private:

	/** Method used to check if location has been assigned
	* @pre Expression/value input
	* @return TRUE if location has been assigned or FALSE if location has
	*		not been assigned
	*/

	bool assigned;

  /** Method used to check if input is valid
  * @pre Expression/value input
  * @return TRUE if input is valid or FALSE if input is not valid
  */
	bool valid;

	// Stores string variable name
	string variableName_;

public:

	/** Constructor
	* Declares isAssigned and valid bool methods
	*/
	Tokenizer();

	/** Method used to check if input is valid by accessing bool valid
* @pre bool valid is declared
* @return TRUE if input is valid or FALSE if input is not valid
*/
	bool isValid();

	/** Method used to check if input is valid by accessing bool valid
* @pre bool valid is declared
* @return TRUE if input is valid or FALSE if input is not valid
*/
	bool isAssigned();

  /** Method used to retrieve variable name
  * @pre Expression/value input
  * @post If variable has been assigned, returns variable name
  * @return string variable name
  */
	string getVariableName(); 
  
	/** Method used to break down input stream into a stream of tokens
	@param string input
	@post If successful, checks for valid input and tokenizes string input
	@return input string into tokenized stream
*/
	vector<Token> tokenize(string input);

};
