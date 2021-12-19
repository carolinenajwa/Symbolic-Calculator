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
IO Class:
A separate I/O class that addresses input and output using cin and cout in the
designated specifications to eliminate code repetition.
*/

#include "IO.h"
#include <iostream>
#include <string>

using namespace std;


/** Method used to display string output
* @param string output
* @pre Expression/value input
* @post If successful, displays output
*/
void IO::display(string output)
{
	cout << output;
}

/** Constructor
* Declares taskNumber_
*/
IO::IO()
{
	this->taskNumber_ = 1;
}


/** Method used to read input and display it with task number
* @pre Expression/value input
* @post If successful, reads expression and displays expression with
*		corresponding task number
* @return Input expression
*/
string IO::read()
{
	string input;
	this->display("in [" + to_string(this->taskNumber_) + "]: ");
	getline(cin, input);
	return input;
}

/** Method used to display input evaluation
* @pre Expression/Value input
* @post If successful, displays evaluated expression
*/
void IO::displayOutput(string output)
{
	cout << "out [" + to_string(taskNumber_) + "]: " << output << endl;
	taskNumber_++;
}
