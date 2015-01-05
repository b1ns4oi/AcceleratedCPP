// // 'Ptr' class in Chapter 14
 #ifndef _GUARD_PTR_H_
 #define _GUARD_PTR_H_

 #include <cstddef>
 #include <stdexcept>
 #include <vector>

 template <class T>
 class Ptr {
 public:
 	Ptr() : p(0), refptr(new std::size_t(1)) { }
 	Ptr(T* t) : p(t), refptr(new std::size_t(1)) {  }
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
 		if(*refptr != 1) {
 			p = p ? clone(p) : 0;
 			--*refptr;
 			refptr = new std::size_t(1);
 		}
 	}

 private:
 	T* p;
 	std::size_t* refptr;
 };

 template <class T>
 Ptr<T>::Ptr(const Ptr& s)
 {
 	p = s.p;
 	refptr = s.refptr;
 	++*refptr;
 }

 template <class T>
 Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
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
 Ptr<T>::~Ptr() 
 {
 	if(--*refptr == 0) {
 		delete p;
 		delete refptr;
 	}
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
