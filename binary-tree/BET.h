#ifndef BET_H
#define BET_H

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

class BET {
	// struct : node in which trees are assembled, have right and left to indicate binary tree
	struct Node {
		string data;
		Node *ln;
		Node *rn;
		Node(const string & d = string {}, Node *l = nullptr, Node *r = nullptr) : data{d}, ln{l}, rn{r} 
	};
	
	public:
		BET(); // default constructor
		BET(const string postfix); // constructor that builds BET based on postfix expression
		BET(const BET&); // copy constructor
		~BET(); // destructor
		
		// functions
		bool build(const string& postfix); // build BET tree based on postfix expression
		void printInfix(); // print infix form
		void printPostfix(); // print postfix form
		bool empty();
		
		size_t size();
		size_t leafNodes();
		
		// operators
		const BET & operator=(const BET &);
	
	private:
		void printInfix(Node *node);
		void printPostfix(Node *node);
		void clear(Node* &node);
		Node * clone(Node *node) const;
		
		size_t size(Node *node);
		size_t leafNodes(Node *node);
		Node *start;
};

#include "BET.cpp"
#endif
