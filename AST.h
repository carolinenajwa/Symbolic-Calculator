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
 AST Class:
 The AST data structure will take the tokenized object as a postfix-structured expression
 and use it to build the tree. It will also make use of the Expression Converter to interchange
 formats between infix and postfix
*/

#pragma once
#include "Token.h"
#include "Node.h"

#include <vector>
#include <stack>
#include <map>
#include <cmath>


class AST
{
public: 
	/** Constructor
	* The AST data structure will take the tokenized object as a
	* postfix-structured expression and use it to build the tree.
	*/
	AST(vector<Token>& postfix);

	/** Destructor
	* Used to destroy object and free memory
	*/
	~AST();

	/** Method for simplifying expression // EDIT?
	* @param Address to expression/value
	* @pre Expression/value stored in variables
	* @post Method traverses the AST, making simplifications
	*		by sub. expressions/values in the tree
	* @returns new AST
	*/
	void simplify(map<string, Token>& variables);

	/** Method for returning string that is the infix
	*	version of the AST
	* @pre Input expressions
	* @post A string that is the infix version of the AST
	* @returns infix version of AST
	*/
	string toInfix();

	/** Method used to check if prefix is an expression
	* @pre Expression/value stored in variables
	* @post If successful, returns TRUE if string value is
	*		an expression or FALSE if string value is a digit
	* @returns if FALSE, value is stored as a digit
	*/
	bool isExpression();

private: 
	// Pointer to root node
	Node* root_;

	/** Method used to check if characters inside of string
	*	is a digit
	* @param String input
	* @pre Expression/value stored in variables
	* @post If successful, when character is a digit returns TRUE
	*		or FALSE if character is a non-digit
	*/
	bool isDigits(string str);


	/** Method for simplifying expression // EDIT?
	* @param Address to expression/value
	* @pre Expression/value stored in variables
	* @post Method traverses the AST, making simplifications
	*		by sub. expressions/values in the tree
	* @returns new AST
	*/
	void simplifyRecursive(map<string, Token>& variables, Node* root);

	/** Method for evaluating left and right nodes
	*
	*
	*/
	Node* evaluateNode(Node* node);

	/** Method used to evaluate expression
	* @param int left side of expression, int right side of expression
	*		type of operator
	* @pre Expression/value stored in variables
	* @post If successful, returns result of operation conducted on the
	left and right side
	* @return int result from operation
	*/
	int eval(int left, int right, Type op);

	/** Method used to perform inorder traversal on the binary tree
	* @param Temporary node
	* @pre Valid binary tree
	* @returns In order string of the tree
	*/
	string inorderTraversal(Node* temp);

	/** Method used to build binary tree
	* @param Tokenized object as postfix-structures expression
	* @pre Tokenized object
	* @post If successful, binary tree structure
	*/
	void buildTree(vector<Token>& postfix);

};
