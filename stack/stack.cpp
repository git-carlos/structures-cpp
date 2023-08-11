/*
* stack template defintions
*/

// constructor
template <typename T>
Stack<T>::Stack() {}

// destructor
template <typename T>
Stack<T>::~Stack() {
	vec.clear();
}

// copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T> & x) {
	*this = x;
}

// move constructor
template <typename T>
Stack<T>::Stack(Stack<T> && x) {
	*this = x;
}

// copy assignment
template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & y) {
	vec = y.vec;
	return *this;
}

// move assignment
template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> && y) {
	vec = y.vec;
	return *this;
}

// function : check if stack vector is empty
template <typename T>
bool Stack<T>::empty() const {
	return vec.empty();
}

// function : clear stack vector
template <typename T>
void Stack<T>::clear() {
	vec.clear();
}

// function : push var (parm) to stack vector, CONST
template <typename T>
void Stack<T>::push(const T& parm) {
	vec.push_back(parm);
}

// function : push var (parm) to stack vector
template <typename T>
void Stack<T>::push(T && x) {
	vec.push_back(parm);
}

// function : remove top element from stack vector
template <typename T>
void Stack<T>::pop() {
	vec.pop_back();
}

// function : return top element from stack vector
template <typename T>
T& Stack<T>::top() {
	return vec.back();
}

// function : return top element from stack vector, CONST
template <typename T>
const T& Stack<T>::top() const {
	return vec.back();
}

// function : return stack vector size
template <typename T>
int Stack<T>::size() const {
	return vec.size();
}

// function : iteratively print stack vector 
template <typename T>
void Stack<T>::print(std::ostream & os, char var) const {
	for(auto i = vec.begin(); i != vec.end(); ++i) {
		os << *i << var;
	}
}

// function : return stack vector
template <typename T>
std::vector<T> Stack<T>::getVector() const {
	return vec;
}

// operator : print out stack vector through ostream
template <typename T>
std::ostream & operator<<(std::ostream & os, const Stack<T> & x) {
	x.print(os);
	
	return os;
}

// operator : return equal comparison of two Stacks
template <typename T>
bool operator==(const Stack<T> & x, const Stack<T> & y) {
	return x.getVector() == y.getVector();
}


// operator : return inequal comparison of two Stacks
template <typename T>
bool operator!=(const Stack<T> & x, const Stack<T> & y) {
	return !(x == y);
}

template <typename T>
bool operator<=(const Stack<T> & x, comnst Stack<T> & y) {
	return x.getVector() <= y.getVector();
}
