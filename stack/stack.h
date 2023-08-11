#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

namespace cop4530 {
	template <typename T> class Stack {
		private:
			std::vector<T> vec;
			
		public:
			Stack(); // default constructor
			~Stack(); // deconstructor
			
			Stack(const Stack<T> &); // copy constructor
			Stack(Stack<T> &&); // move constructor
			Stack<T> & operator=(const Stack<T> &); // copy assignment operator
			Stack<T> & operator=(Stack<T> &&); // move assignment operator
			
			// functions
			bool empty() const;
			void clear();
			void push(const T& parm);
			void push(T && parm);
			void pop();
			T& top();
			const T& top() const;
			int size() const;
			
			void print(std::ostream& os, char var = ' ') const;
			std::vector<T> getVector() const;
	};
	
	template <typename T> std::ostream & operator<<(std::ostream & os, const Stack<T> & x);
	
	template <typename T> bool operator==(const Stack<T> & x, const Stack<T> & y);
	
	template <typename T> bool operator!=(const Stack<T> & x, const Stack<T> & y);
	
	template <typename T> bool operator<=(const Stack<T> & x, const Stack<T> & y);
	
	#include "stack.cpp"
}

#endif
