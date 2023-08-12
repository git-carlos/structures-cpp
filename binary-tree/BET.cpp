
// functions
bool operand(string parm);
int precedence(string parm);

BET::BET() {
	start = new Node;
}

BET::BET(const string postfix) {
	start = new Node;
	build(postfix);
}

BET::BET(const BET& b) {
	start = clone(b.start);
}

BET::~BET() {
	clear(start);
}

bool BET::build(const string& postfix) {
	string a;
	stringstream ss(postfix);
	stack<Node*> tokens;
	
	int x, y;
	
	// postfix empty
	if(postfix.empty() == true) {
		cout<<"Postfix expression empty..." << endl;
		start = nullptr;
		return false;
	}
	
	// nodes present in tree when building
	if(empty() == false) {
		clear(start);
	}
	
	// tokenize
	while(ss >> a) {
		Node token = new Node(a);
		
		if(operand(a) == true) {
			x++;
			stk.push(token);
		} else if(precedence(a) != 0) {
			y++;
			if(x == y) {
				cout<<"Postfix expression invalid format..." << endl;
				start = nullptr;
				return false;
			} else {
				token->ln = tokens.top();
				tokens.pop();
				
				token->rn = tokens.top();
				tokens.pop();
				
				tokens.push(token);
			}
		}
	}
	
	if(x != y)
		start = tokens.top();
	
	if(tokens.empty() == true) {
		cout<<"Postfix expression invalid format..." << endl;
		start = nullptr;
		return false;
	}
	
	return true;
}

void BET::printInfix() {
	printInfix(start);
	cout << endl;
}

void BET::printPostfix() {
	printPostfix(start);
	cout << endl;
}

bool BET::empty() {
	if(start == nullptr) {
		return true;
	}
	
	return false;
}

size_t BET::size() {
	return (size(start));
}

size_t BET::leafNodes() {
	return (leafNodes(start));
}

const BET & BET::operator=(const BET & tree) {
	start = clone(tree.start);
	return *this;
}

void BET::printInfix(Node *token) {
	bool close = false;
	
	if(token != nullptr) {
		if(token->ln == nullptr && token->rn == nullptr) {
			cout<<token->data << " ";
		} else {
			if(precedence(token->data) != 0 && precedence(token->rn->data) != 0) {
				if(precedence(token->data >= precedence(token->rn->data)) {
					if(precedence(token->data) == 2) {
						cout<<"( ";
						close = true;
					}
				}
			}
			
			printInfix(token->rn);
			
			if(close == true) {
				cout<<") ";
			}
			
			close = false;
			
			cout<<token->data << " ";
			
			if(precedence(token->data) != 0 && precedence(token->ln->data) != 0) {
				if(precedence(token->data) >= precedence(token->ln->data)) {
					cout<<"( ";
					close = true;
				}
			}
			
			printInfix(token->ln);
			
			if(close == true) {
				cout<<") ";
			}
			
			close = false;
			
		}
	}
}

void BET::printPostfix(Node *token) {
	if(size(token) == 0) {
		return;
	} else if(start->ln == nullptr && start->rn == nullptr) {
		cout<<start->data << endl;
	} else {
		printPostfix(token->rn);
		printPostfix(token->ln);
		cout<<token->data << " ";
	}
}

void BET::clear(Node *token) {
	if(token != nullptr) {
		clear(token->ln);
		clear(token->rn);
		delete token;
	}
}

BET::Node * BET::clone(Node *token) const {
	if(token == nullptr) {
		return nullptr;
	} else {
		return new Node(token->data, clone(token->ln), clone(token->rn));
	}
}

size_t BET::size(Node *token) {
	if(token == nullptr) {
		return 0;
	} else {
		return(size(token->ln) + size(token->rn) + 1);
	}
}

size_t BET::leafNodes(Node *token) {
	if(token == nullptr) {
		return 0;
	} else if((token->ln == nullptr) && (token->rn == nullptr)) {
		return 1;
	} else {
		return (leafNodes(token->ln) + leafNodes(t->rn));
	}
}

bool operand(const string parm) {
	for(int i = 0; i < int(parm.size()); i++) {
		if(isalnum(parm[i]) == false) {
			return false;
		}
	}
	
	return true;
}

int precedence(const string parm) {
	if(parm == "(" || parm == ")") {
		return 3;
	} else if(parm == "*" || parm == "/") {
		return 2;
	} else if(parm == "+" || parm == "-") {
		return 1;
	} else {
		return 0;
	}
}
