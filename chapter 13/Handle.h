// Handle class from chapter 14
#ifndef _GRARD_HANDLE_H_
#define _GRARD_HANDLE_H_

#include <stdexcept>

template <class T>
class Handle {
public:
	Handle() : p(0) { }
	Handle(T* t) : p(t) { }
	Handle(const Handle& s) : p(0) { if(s.p) p = s.p->clone(); }

	Handle& operator=(const Handle&);
	~Handle() { delete p; }

	operator bool() const { return p; }
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
};

template <class T>
T& Handle<T>::operator*() const
{
	if(p) 
		return *p;
	else
		throw std::runtime_error("unbound Handle");
}

template <class T>
T* Handle<T>::operator->() const
{
	if(p)
		return p;
	else throw std::runtime_error("unbound Handle");
}

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
	if(this != &rhs) {
		delete p;
		if(rhs.p) 
			p = rhs.p->clone();
		else p = 0;
	}
	return *this;
}



#endif










