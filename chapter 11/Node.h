
#include <cstddef>  // for 'NULL'

template <class T> struct Node {
	T val;
	Node* next;

	Node() { val = T(); next = NULL; }
	Node(const T& v) { val = v; next = NULL; }
};