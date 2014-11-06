// 11-8

#include "Node.h"
#include <iostream>
#include <ostream>

template <class T> class List_beta {
public:
	typedef Node<T>* iterator;
	typedef const Node<T>* const_iterator;
	typedef unsigned size_type;

	List_beta() { from = to = NULL; }
	explicit List_beta(size_type, const T& v = T());
	List_beta(const_iterator iter1, const_iterator iter2);
	
	// copy constructor
	List_beta(const List_beta& v) {
		const_iterator iter1 = v.begin();
		const_iterator iter2 = v.end();
		from = to = create_list(iter1, iter2);
		for(; iter1 != iter2; iter1 = iter1->next, to = to->next)		
			;
	}
	
	// destructor
	~List_beta() { uncreate(); }
	
	// assignment operator
	List_beta& operator=(const List_beta& rhs) {
		if(&rhs != this) {
			uncreate();
			// same as copy constructor
			const_iterator iter1 = rhs.begin();
			const_iterator iter2 = rhs.end();
			from = to = create_list(iter1, iter2);
			for(; iter1 != iter2; iter1 = iter1->next, to = to->next)		
				;
		}
		return *this;
	}
	
	size_type size() {
		int i = 0;
		for(iterator it = from; it != to; it = it->next, ++i)
			;
		return i;
	}
	
	// iterators
	iterator begin() { return from; }
	iterator end() { return to; }
	const_iterator begin() const { return from; }
	const_iterator end() const { return to; }

	// modifiers
	iterator insert(iterator pos, const T& val);

	// iterator check 
	bool iter_valid(const_iterator it);
private:
	iterator from;
	iterator to;
	
	void uncreate();
	iterator create_node(const T&);
	iterator create_list(size_type, const T&);
	iterator create_list(const_iterator, const_iterator);
};

template <class T> List_beta<T>::List_beta(size_type n, const T& v)
{
	from = to = create_list(n, v);
	for(int i = 0; i != n; ++i)
		to = to->next;
}

template <class T> List_beta<T>::List_beta(const_iterator iter1, const_iterator iter2)
{
	from = to = create_list(iter1, iter2);
	for(; iter1 != iter2; iter1 = iter1->next, to = to->next)		
		;
}

template <class T> 
typename List_beta<T>::iterator List_beta<T>::create_node(const T& v) 
{
	return new Node<T>(v);
}

template <class T> 
typename List_beta<T>::iterator List_beta<T>::create_list(size_type n, const T& v)
{
	if(n == 0)
		return NULL;
	iterator ret = create_node(v);
	ret->next = create_list(n-1, v);
	return ret;
}


template <class T> 
typename List_beta<T>::iterator List_beta<T>::create_list(const_iterator iter1, const_iterator iter2)
{
	if(iter1 == iter2)
		return NULL;
	iterator ret = create_node(iter1->val);
	ret->next = create_list(iter1->next, iter2);
	return ret;
}

template <class T> 
void List_beta<T>::uncreate()
{
	iterator it = from;
	for(; from != to; it = from) {
		from = from->next;
		delete it;
	}
	from = to = NULL;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const List_beta<T>& list) 
{
	for(typename List_beta<T>::const_iterator it = list.begin(); it != list.end(); it = it->next)
		os << it->val << " ";
	os << std::endl;
	return os;
}

template <class T>
typename List_beta<T>::iterator List_beta<T>::insert(iterator pos, const T& val)
{
	iterator node = create_node(val);
	node->next = pos;

	if(pos == from) {
		from = node;
		return from;
	}
		
	// else, there should be more than 1 element in the list before insert
	// find the previous node
	iterator prev = from;
	for(; prev->next != pos; prev = prev->next)
		;

	prev->next = node;
	return node;
}

// check if a iterator is in a valid range: [from, to)
template <class T>
bool List_beta<T>::iter_valid(const_iterator it)
{
	for(iterator temp = from; temp != to; temp = temp->next)
		if(temp == it)
			return true;
	return false;
}




















