
template <class T> struct Node {
	T val;
	T* next;

	Node() { val = T(); next = NULL; }
	Node(const T& v) { val = v; next = NULL; }
};