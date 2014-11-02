#ifndef VEC_H
#define VEC_H

#include <memory>
#include <cstddef>
#include <algorithm>

using std::max;


template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef std::ptrdiff_t difference_type;

	// interface
	Vec() { create(); }
	explicit Vec(size_type n, const T& val = T()) { create(n, val); }

	// index and size
	T& operator[](size_type i) { return data[i]; }
	const T& operator[] (size_type i) const { return data[i]; }
	size_type size() const { return avail - data; }

	// operations that return iterators
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	// copy control
	Vec(const Vec& v) {
		create(v.begin(), v.end());
	}

	// assignment
	Vec& operator=(const Vec& v) {
		if(&v != this) {
			uncreate();
			create(v.begin(), v.end());
		}
		return *this;
	}

	// destructor
	~Vec() { uncreate(); }

	// push back
	void push_back(const T& t) {
		if(avail == limit) 
			grow();
		unchecked_append(t);
	}

	// 11-6
	iterator erase(iterator it);
	void clear();

private:
	iterator data;
	iterator avail;
	iterator limit;	
	
	std::allocator<T> alloc;
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);
	
	void uncreate();
	
	void grow();
	void unchecked_append(const T&);
};

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
	int new_size = max(2*(limit-data), ptrdiff_t(1));   // 'ptrdiff_t' is from <cstddef>
	iterator ptr_new = alloc.allocate(new_size);
	iterator avail_new = std::uninitialized_copy(data, avail, ptr_new);
	
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

// 11-6
template<class T> 
typename Vec<T>::iterator Vec<T>::erase(iterator it) {
	if(it >= avail)
		return it;
	iterator ret = it;
	for (++it; it != avail; ++it) 
		*(it-1) = *it;
	--avail;
	return ret;
}

template<class T> void Vec<T>::clear() {
	uncreate();
}

#endif














