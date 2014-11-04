// 11-8

#include "Node.h"

template <class T> class List_beta {
public:
	typedef Node<T>* iterator;
	typedef const Node<T>* const_iterator;
	typedef unsigned size_type;

	List_beta() { from = to = NULL; }
	explicit List_beta(size_type, const T& v = T());
	
	
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

private:
	iterator from;
	iterator to;
	
	iterator create_node(const T&);
	iterator create_list(size_type, const T&);
};

template <class T> List_beta<T>::List_beta(size_type n, const T& v)
{
	from = to = create_list(n, v);
	for(int i = 0; i != n; ++i)
		to = to->next;
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












