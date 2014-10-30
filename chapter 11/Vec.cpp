
#include "Vec.h"

template <class T> void Vec<T>::create() {
	data = avail = limit = 0;
}



template <class T> void Vec<T>::create(size_type n, const T& v) {
	data = alloc.allocate(n);
	avail = limit = data + n;
	uninitialized_fill(data, avail, v);
}

template <class T> void Vec<T>::create(const_iterator b, const_iterator e) {
	data = alloc.allocate(e-b);
	avail = limit = data + e - b;
	uninitialized_copy(b, e, data);
}

template<class T> void Vec<T>::uncreate() {
	if(data) {
		for(iterator i = data; i != avail; ++i) {
			alloc.destroy(i);
		}
		alloc.deallocate(data, limit - data);
	}
	data = avail = limit = 0;
}

template<class T> void Vec<T>::grow() {
	int new_size = max(2*(limit-data), ptrdiff_t(1));
	iterator ptr_new = alloc.allocate(new_size);
	iterator avail_new = alloc.uninitialized_copy(data, avail, ptr_new);
	
	// destroy the old memory
	uncreate();
	
	// set the iterator variables
	data = ptr_new;
	avail = avail_new;
	limit = data + new_size;
}

template<class T> void Vec<T>::unchecked_append(const T& v) {
	alloc.construct(avail++, v);
}






























