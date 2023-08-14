/*
*	const_iterator definitions
*/

template <class T>
List<T>::const_iterator::const_iterator() {
	token = nullptr;
}

template <class T>
const T & List<T>::const_iterator::operator*() const {
	return retrieve();
}

// top tier c++ nested class syntax moment

template <class T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++() {
	token = token->right;
	
	return(*this);
}

template <class T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int) {
	const_iterator shift = *this;
	++(*this);
	
	return shift;
}

template <class T>
typename List<T>::const_iterator & List<T>::const_iterator::operator--() {
	token = token->left;
	
	return(*this);
}

template <class T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int) {
	const_iterator shift = *this;
	--(*this);
	
	return shift;
}

template <class T>
bool List<T>::const_iterator::operator==(const const_iterator &right) const {
	return(token == right.token);
}

template <class T>
bool List<T>::const_iterator::operator!=(const const_iterator &right) const {
	return(token != right.token);
}

template <class T>
T & List<T>::const_iterator::retrieve() const {
	return(token->data);
}

template <class T>
List<T>::const_iterator::const_iterator(Node *sample) {
	token = sample;
}

/*
* iterator defintions
*/

template <class T>
List<T>::iterator::iterator() {
	init();
}

template <class T>
T & List<T>::iterator::operator*() {
	return(const_iterator::retrieve());
}

template <class T>
const T & List<T>::iterator::operator*() const {
	return(const_iterator::operator*());
}

template <class T>
typename List<T>::iterator & List<T>::iterator::operator++() {
	this->token = this->token->right;
	
	return(*this);
}

template <class T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
	iterator shift = *this;
	++(*this);
	
	return shift;
}

template <class T>
typename List<T>::iterator & List<T>::iterator::operator--() {
	this->token = this->token->left;
	
	return *this;
}

template <class T>
typename List<T>::iterator List<T>::iterator::operator--(int) {
	iterator shift = *this;
	--(*this);
	
	return shift;
}

template <class T>
List<T>::iterator::iterator(Node *sample) {
	this->token = sample;
}

/*
* list defintions
*/

template <class T>
List<T>::List() {
	init();
}

template <class T>
List<T>::List(const List &right) {
	init();
	
	auto itr = right.begin();
	for(int i = 0; i < right.size(); i++) {
		push_back(*itr);
		itr++;
	}
}

template <class T>
List<T>::List(List && right) {
	amount = right.amount;
	head = right.head;
	tail = right.tail;
	
	right.amount = 0;
	right.head = nullptr;
	right.tail = nullptr;
}

template <class T>
List<T>::List(int elmts, const T& val) {
	init();
	
	for(int i = 0; i < elmts; i++) {
		push_back(val);
	}
}

template <class T>
List<T>::List(const_iterator start, const_iterator end) {
	init();
	
	auto itr = start;
	do {
		push_back(*itr);
		itr++;
	} while(itr != end);
}

template <class T>
List<T>::List(std::initializer_list<T> init_list) {
	init();
	
	for(T item : init_list)
		push_back(item);
}

template <class T>
List<T>::~List() {
	if(empty() == false) {
		clear();
	}
	
	delete head;
	delete tail;
}

template <class T>
const List<T>& List<T>::operator=(const List &right) {
	clear();
	
	auto itr = right.begin();
	for(int i = 0; i < right.size(); i++) {
		push_back(itr.retrieve());
		
		itr++;
	}
	
	return *this;
}

template <class T>
List<T>& List<T>::operator=(List && right) {
	std::swap(amount, right.amount);
	std::swap(head, right.head);
	std::swap(tail, right.tail);
}

template <class T>
List<T>& List<T>::operator=(std::initializer_list<T> init_list) {
	init();
	
	for(T i : init_list) {
		push_back(i);
	}
}

template <class T>
int List<T>::size() const {
	return amount;
}

template <class T>
int List<T>::empty() const {
	if(amount > 0) {
		return false;
	} else {
		return true;
	}
}

template <class T>
void List<T>::clear() {
	auto itr = begin();
	
	while(itr.token != tail) {
		itr = erase(itr);
	}
}

template <class T>
void List<T>::reverse() {
	auto itr = end();
	List<T> reversed;
	
	itr--;
	for(int i = 0; i < amount; i++) {
		reversed.push_back(*itr);
		itr--;
	}
	
	*this = reversed;
}

template <class T>
T& List<T>::front() {
	return(head->right->data);
}

template <class T>
const T& List<T>::front() const {
	return(head->right->data);
}

template <class T>
T& List<T>::back() {
	return(tail->left->data);
}

template <class T>
const T& List<T>::back() const {
	return(tail->left->data);
}

template <class T>
void List<T>::push_front(const T & val) {
	insert(begin(), val);
}

template <class T>
void List<T>::push_front(T && val) {
	insert(begin(), std::move(val));
}

template <class T>
void List<T>::push_back(const T & val) {
	insert(end(), val);
}

template <class T>
void List<T>::push_back(T && val) {
	insert(end(), std::move(val));
}

template <class T>
void List<T>::pop_front() {
	erase(begin());
}

template <class T>
void List<T>::pop_back() {
	erase(end().token->left);
}

template <class T>
void List::remove(const T &val) {
	auto itr = begin();
	
	do {
		if(itr.retrieve() == val) {
			itr = erase(itr);
		} else {
			++itr;
		}
	} while(itr != end());
}

template <class T>
template<typename PREDICATE>
void List<T>::remove_if(PREDICATE pred) {
	auto itr = begin();
	
	do {
		if(pred(*itr) == true) {
			itr = erase(itr);
		} else {
			++itr;
		}
	}while(itr != end());
}

template <class T>
void List<T>::print(std::ostream& os, char delim) const {
	const_iterator itr = begin();
	
	for(int i = 0; i < amount - 1; i++) {
		os << itr.retrieve() << delim;
		itr++;
	}
	
	os << itr.retrieve();
}

template <class T>
typename List<T>::iterator List<T>::begin() {
	return iterator(head->right);
}

template <class T>
typename List<T>::const_iterator List<T>::begin() const {
	return const_iterator(head->right);
}

template <class T>
typename List<T>::iterator List<T>::end() {
	return iterator(tail);
}

template <class T>
typename List<T>::const_iterator List<T>::end() const {
	return const_iterator(tail);
}

template <class T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& val) {
	Node *sample = itr.token;
	++amount;
	
	return iterator(sample->left = sample->left->right = new Node{val, sample->left, sample});
}

template <class T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val) {
	Node *sample = itr.current;
	++amount;
	
	return(sample->left = sample->left->right = new Node{val, sample->left, sample});
}

template <class T>
typename List<T>::iterator List<T>::erase(iterator itr) {
	Node *sample = itr.token;
	iterator retcon(sample->right);
	sample->left->right = sample->right;
	sample->right->left = sample->left;
	
	delete sample;
	amount--;
	
	return retcon;
}

template <class T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end) {
	iterator itr = start;
	for(int i = 0; i < amount - 1; i++) {
		itr = erase(itr);
	}
}

template <class T>
void List<T>::init() {
	amount = 0;
	head = new Node;
	tail = new Node;
	
	head->right = tail;
	tail->left = head;
}

template <typename T>
bool oeprator==(const List<T> &left, const List<T> &right) {
	auto itr_left = left.begin();
	auto itr_right = right.begin();
	
	if(left.size() != right.size()) {
		return false;
	}
	
	do {
		if(*itr_left != *itr_right) {
			return false;
		}
		
		++itr_left;
		++itr_right;
	} while(itr_left != left.end());
	
	return true;
}

template <typename T>
bool operator !=(const List<T> &left, const List<T> &right) {
	return !(left = right);
}

template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &this_list) {
	this_list.print(os);
}
