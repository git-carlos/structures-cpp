#ifndef DL_LIST_H
#define DL_LIST_H
#include <iostream>
#include <initializer_list>

namespace cop4530 {
	template <typename T> class List {
		
		private:
			struct Node {
				T data;
				Node *left;
				Node *right;
			
				Node(const T & node_data = T{}, Node *ln = nullptr, Node *rn = nullptr) : data{node_data}, left{ln}, right{rn} {}
			
				Node(T && node_data, Node *ln = nullptr, Node *rn = nullptr) : data{std::move(node_data)}, left{ln}, right{rn} {}
			};
		
		public:
		class const_iterator {
			public:
				const_iterator();
				const T & operator*() const;
				
				const_iterator & operator++();
				const_iterator operator++(int);
				const_iterator & operator--();
				const_iterator operator--(int);
				
				bool operator==(const const_iterator &right) const;
				bool operator!=(const const_iterator &right) const;
			
			protected:
				Node *token;
				T & retrieve() const;
				const_iterator(Node *sample);
				
				friend class List<T>;
		};
		
		class iterator : public const_iterator {
			public:
				iterator();
				T & operator*();
				const T & operator*() const;
				
				iterator & operator++();
				iterator operator++(int);
				iterator & operator--();
				iterator operator--(int);
				
			protected:
				iterator(Node *token);
				friend class List<T>;
		};
		
		public:
			List();
			List(const List &right);
			List(List && right);
			
			explicit List(int elmts, const T& val = T{});
			
			List(const_iterator start, const_iterator end);
			List(std::initializer_list<T> init);
			~List();
			
			// operators
			const List& operator=(const List &right);
			List & operator=(List && right);
			List & operator=(std::initializer_list<T> init);
			
			// functions
			int size() const;
			bool empty();
			void clear();
			void reverse();
			
			T& front();
			const T& front() const;
			
			T& back();
			const T& back() const;
			
			void push_front(const T & val);
			void push_front(T && val);
			void push_back(const T & val);
			void push_back(T && val);
			void pop_front();
			void pop_back();
			void remove(const T &val);
			
			template <typename PREDICATE>
			void remove_if(PREDICATE pr);
			
			void print(std::ostream& os, char delim = ' ') const;
			
			iterator begin();
			const_iterator begin() const;
			
			iterator end();
			const_iterator end() const;
			
			iterator insert(iterator itr, const T& val);
			iterator insert(iterator itr, T && val);
			iterator erase(iterator itr);
			iterator erase(iterator start, iterator end);
			
			private:
				int amount;
				Node *head;
				Node *tail;
				
				void init();
	};
	
	template <typename T>
	bool operator==(const List<T> & left, const List<T> & right);
	
	template <typename T>
	bool operator!=(const List<T> & left, const List<T> & right);
	
	template <typename T>
	std::ostream & operator<<(std::ostream &os, const List<T> & lst);
	
#include "list.cpp"
}

#endif
