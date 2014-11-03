// 11-8

template <class T> class List_beta {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef int size_type;

	List_beta() { i = j = 0; }
	explicit List_beta(size_type n, const T& v = T());

private:
	iterator i;
	iterator j;

};

template <class T> List_beta<T>::List_beta(size_type n, const T& v)
{
	//
}