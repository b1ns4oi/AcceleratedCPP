// // 'Ptr' class in Chapter 14
// #ifndef _GUARD_PTR_H_
// #define _GUARD_PTR_H_

// #include <cstddef>
// #include <stdexcept>
// #include <vector>
// #include "Core.h"

// template <class T>
// class Ptr {
// public:
// 	Ptr() : p(0), refptr(new std::size_t(1)) { }
// 	Ptr(T* t) : p(t), refptr(new std::size_t(1)) {  }
// 	Ptr(const Ptr&);

// 	Ptr& operator=(const Ptr&);
// 	~Ptr();

// 	operator bool() const { return p; }
// 	T& operator*() const {
// 		if(p)
// 			return *p;
// 		throw std::runtime_error("unbound Ptr");
// 	}
// 	T* operator->() const {
// 		if(p)
// 			return p;
// 		throw std::runtime_error("unbound Ptr");
// 	}

// 	void make_unique() {
// 		if(*refptr != 1) {
// 			p = p ? clone(p) : 0;
// 			--*refptr;
// 			refptr = new std::size_t(1);
// 		}
// 	}

// private:
// 	T* p;
// 	std::size_t* refptr;
// };

// template <class T>
// Ptr<T>::Ptr(const Ptr& s)
// {
// 	p = s.p;
// 	refptr = s.refptr;
// 	++*refptr;
// }

// template <class T>
// Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
// {
// 	// no need for self-checking
// 	++*rhs.refptr;
// 	if(--*refptr == 0) {
// 		delete p;
// 		delete refptr;
// 	}
// 	p = rhs.p;
// 	refptr = rhs.refptr;
// 	return *this;
// }

// template <class T>
// Ptr<T>::~Ptr() 
// {
// 	if(--*refptr == 0) {
// 		delete p;
// 		delete refptr;
// 	}
// }

// int compare_Core_handles(const Ptr<Core>& h1, const Ptr<Core>& h2)
// {
//   return h1->name() < h2->name();
// }

// template <class T>
// T* clone(const T* tp)
// {
// 	return tp->clone();
// }

// /******* template specialization ********/
// template<>
// std::vector<char>* clone(const std::vector<char>* tp)
// {
// 	return new std::vector<char>(*tp);
// }

// #endif



// 'Ptr' class in Chapter 14 implemented with 'Ref_Counter'
#ifndef _GUARD_PTR_H_
#define _GUARD_PTR_H_

#include <cstddef>
#include <stdexcept>
#include <vector>
#include "Core.h"
#include "Ref_Counter.h"

template <class T>
class Ptr {
public:
	Ptr() : p(0), ct(1) { }
	Ptr(T* t) : p(t), ct(1) {  }
	Ptr(const Ptr&);

	Ptr& operator=(const Ptr&);
	~Ptr();

	operator bool() const { return p; }
	T& operator*() const {
		if(p)
			return *p;
		throw std::runtime_error("unbound Ptr");
	}
	T* operator->() const {
		if(p)
			return p;
		throw std::runtime_error("unbound Ptr");
	}

	void make_unique() {
		if(ct.number() != 1) {
			p = p ? clone(p) : 0;
			ct = 1;
		}
	}

private:
	T* p;
	Ref_Counter ct;
};

template <class T>
Ptr<T>::Ptr(const Ptr& s) : p(s.p), ct(s.ct) { }

template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
	// no need for self-checking
	if(ct.number() == 1)
		delete p;
	ct = rhs.ct;
	p = rhs.p;
	return *this;
}

template <class T>
Ptr<T>::~Ptr() 
{
	// if(--*refptr == 0) {
	// 	delete p;
	// 	delete refptr;
	// }
	if(ct.number() == 1) {
		delete p;
	}
}

int compare_Core_handles(const Ptr<Core>& h1, const Ptr<Core>& h2)
{
  return h1->name() < h2->name();
}

template <class T>
T* clone(const T* tp)
{
	return tp->clone();
}

/******* template specialization ********/
template<>
std::vector<char>* clone(const std::vector<char>* tp)
{
	return new std::vector<char>(*tp);
}

#endif





