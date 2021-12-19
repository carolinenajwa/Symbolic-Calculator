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
Node Class:
ASTNode is a rooted tree data structure whose internal nodes each store a token
in the node’s left subtree and in rge right subtree
*/

#include "Node.h"
#include "Token.h"

using namespace std;

/**
* Sets variable and nodes
* to avoid memory leak
*/
Node::Node(Token token)
{
	this->tok_ = token;
	this->left_ = nullptr;
	this->right_ = nullptr;
}

/** Method used to set token from stream
* @param Token value to set
* @pre Expression/value input
* @post If successful, sets token in location
*/
void Node::setToken(Token token)
{
	this->tok_ = token;
}

/** Method used to retrieve token
* @pre Token has been set
* @post If successful, locates token and returns it
* @return Token
*/
Token Node::getToken()
{
	return this->tok_;
}

/** Method used to retrieve left child node
* @pre Left child node has been set
* @post If successful, locates left child node and returns it
* @returns Left child node
*/
Node* Node::getLeft()
{
	return this->left_;
}

/** Method used to retrieve right child node
* @pre Right child node has been set
* @post If successful, locates right child node and returns it
* @returns Left child node
*/
Node* Node::getRight()
{
	return this->right_;
}

/** Method used to set left child node
* @param Node to set
* @pre Expression/value input
* @post If successful, sets node as left child node
*/
void Node::setLeft(Node* left)
{
	this->left_ = left;
}

/** Method used to set right child node
* @param Node to set
* @pre Expression/value input
* @post If successful, sets node as right child node
*/
void Node::setRight(Node* right)
{
	this->right_ = right;
}
