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

#include "AST.h"

#include <vector>
#include <stack>
#include <map>
#include <cmath>

/** Constructor
* The AST data structure will take the tokenized object as a
* postfix-structured expression and use it to build the tree.
*/
AST::AST(vector<Token>& postfix)
{
	buildTree(postfix);
}
/** Destructor
* Used to destroy object and free memory
*/
AST::~AST() { }

/** Method for simplifying expression // EDIT?
* @param Address to expression/value
* @pre Expression/value stored in variables
* @post Method traverses the AST, making simplifications
*		by sub. expressions/values in the tree
* @returns new AST
*/
void AST::simplify(map<string, Token>& variables)
{
	//cout << "Attempting simplify\n";
	simplifyRecursive(variables, root_);
}

/** Method for returning string that is the infix
*	version of the AST
* @pre Input expressions
* @post A string that is the infix version of the AST
* @returns infix version of AST
*/
string AST::toInfix()
{
	Node* temp = root_;
	return this->inorderTraversal(temp);
}

/** Method used to check if prefix is an expression
* @pre Expression/value stored in variables
* @post If successful, returns TRUE if string value is
*		an expression or FALSE if string value is a digit
* @returns if FALSE, value is stored as a digit
*/
bool AST::isExpression()
{
	return !isDigits(toInfix());
}

/** Method used to check if characters inside of string
	*	is a digit
	* @param String input
	* @pre Expression/value stored in variables
	* @post If successful, when character is a digit returns TRUE
	*		or FALSE if character is a non-digit
	*/
bool AST::isDigits(string str)
{
	for (char const& c : str)
	{
		if (isdigit(c) == 0)
			return false;
	}
	return true;
}

/** Method for simplifying expression // EDIT?
* @param Address to expression/value
* @pre Expression/value stored in variables
* @post Method traverses the AST, making simplifications
*		by sub. expressions/values in the tree
* @returns new AST
*/
void AST::simplifyRecursive(map<string, Token>& variables, Node* root)
{
	//cout << "Attempting recursive...\n";
	if (root != nullptr) {
		simplifyRecursive(variables, root->getLeft());
		simplifyRecursive(variables, root->getRight());
		if (root->getToken().getType() == variable) {
			string variable_name = root->getToken().getValue();
			// find the variable
		//	cout << "Looking for variable..." << root->getToken().getValue() << "\n";
			if (variables.find(variable_name) != variables.end())
			{
				//cout << "Found variable..." << variable_name << "\n";
				//cout << "Setting node to [" << variables[variable_name].getValue() << "]:[" << variables[variable_name].getType() << "]" << endl;
				root->setToken(Token(variables[variable_name].getType(), variables[variable_name].getValue()));
			} //else	
				//cout << "NOT Found variable..." << root->getToken().getValue() << "\n";
		}
		root = evaluateNode(root);
	}
	//cout << "Oops! root is nullptr\n";
}

/** Method for evaluating tree nodes
* @param traveling node
* @post If successful, evaluates value of tree nodes
* @returns node 
*/
Node* AST::evaluateNode(Node* node)
{
	if (node->getLeft() != nullptr && node->getRight() != nullptr && node->getLeft()->getToken().getType() == number && node->getRight()->getToken().getType() == number)
	{
		int left_value = stoi(node->getLeft()->getToken().getValue());
		int right_value = stoi(node->getRight()->getToken().getValue());
		int result = this->eval(left_value, right_value, node->getToken().getType());
		//cout << "Result: " << result << endl;
		node->setToken(Token(number, to_string(result)));
		node->setRight(nullptr);
		node->setLeft(nullptr);
	}
	return node;
}

/** Method used to evaluate expression
* @param int left side of expression, int right side of expression
*		type of operator
* @pre Expression/value stored in variables
* @post If successful, returns result of operation conducted on the
		left and right side
* @return int result from operation
*/
int AST::eval(int left, int right, Type op)
{
	switch (op)
	{
	case addop:
		return left + right;
	case minop:
		return left - right;
	case mulop:
		return left * right;
	case divop:
		return left / right;
	case powop:
		return pow(left, right);
	}
}

/** Method used to perform inorder traversal on the binary tree
* @param Temporary node
* @pre Valid binary tree
* @returns In order string of the tree
*/
string AST::inorderTraversal(Node* temp)
{
	string expression = "";
	if (temp != nullptr)
	{
		expression = inorderTraversal(temp->getLeft()) +
			temp->getToken().getValue() +
			inorderTraversal(temp->getRight());
	}
	return expression;
}

/** Method used to build binary tree
* @param Tokenized object as postfix-structures expression
* @pre Tokenized object
* @post If successful, binary tree structure
*/
void AST::buildTree(vector<Token>& postfix)
{
	root_ = nullptr;
	stack<Node*> operands;
	stack<Token> operators;
	for (int k = 0; k < postfix.size(); k++)
	{
		if (postfix.at(k).isOperator())
		{
			//cout << "operator '" << postfix.at(k).getValue() << "'" << endl;
			if (!operands.empty())
			{
				Node* node = new Node(postfix.at(k));
				node->setRight(operands.top());
				operands.pop();
				node->setLeft(operands.top());
				operands.pop();
				operands.push(node);
				root_ = node;
				continue;
			}
			operators.push(postfix.at(k));
		}
		else
		{
			Node* node = new Node(postfix.at(k));
			operands.push(node);
			root_ = node;
		}
	}
}
