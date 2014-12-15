// 'Ref_handle' class in Chapter 14
#ifndef _GUARD_REF_HANDLE_H_
#define _GUARD_REF_HANDLE_H_

#include <cstddef>
#include <stdexcept>
#include <iostream>

template <class T>
class Ref_handle {
public:
	Ref_handle() : p(0), refptr(new std::size_t(1)) { }
	Ref_handle(T* t) : p(t), refptr(new std::size_t(1)) { }
	Ref_handle(const Ref_handle&);

	Ref_handle& operator=(const Ref_handle&);
	~Ref_handle();

	operator bool() const { return p; }
	T& operator*() const {
		if(p)
			return *p;
		throw std::runtime_error("unbound Ref_handle");
	}
	T* operator->() const {
		if(p)
			return p;
		throw std::runtime_error("unbound Ref_handle");
	}

private:
	T* p;
	std::size_t* refptr;
};

template <class T>
Ref_handle<T>::Ref_handle(const Ref_handle& rhs)
{
	p = rhs.p;
	refptr = rhs.refptr;
	++*refptr;
}

template <class T>
Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs)
{
	// no need for self-checking
	++*rhs.refptr;
	if(--*refptr == 0) {
		delete p;
		delete refptr;
	}
	p = rhs.p;
	refptr = rhs.refptr;
	return *this;
}

template <class T>
Ref_handle<T>::~Ref_handle() 
{
	if(--*refptr == 0) {
		delete p;
		delete refptr;
	}
}



#endif
























