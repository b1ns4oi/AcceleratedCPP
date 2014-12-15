// 'Ref_Counter' class deals with reference count

#ifndef _GUARD_REF_COUNTER_H_
#define _GUARD_REF_COUNTER_H_

#include <cstddef>
#include <stdexcept>

class Ref_Counter {
public:
	Ref_Counter(std::size_t n) : p(new std::size_t(n)) { }

	Ref_Counter(const Ref_Counter& rhs) {
		p = rhs.p;
		++*p;
	}

	Ref_Counter& operator=(const Ref_Counter& rhs) {
		if(this != &rhs) {
			if(--*p == 0)
				delete p;
			p = rhs.p;
			++*p;
		}
		return *this;
	}

	~Ref_Counter() {
		if(--*p == 0)
			delete p;
	}

	std::size_t number() { 
		if(p) 
			return *p;
		throw std::runtime_error("unbound Ref_Counter");
	}

	// void increment() {
	// 	if(p)
	// 		++*p;
	// 	else
	// 		throw std::runtime_error("unbound Ref_Counter");
	// }

	// void decrement() {
	// 	if(p)
	// 		--*p;
	// 	else
	// 		throw std::runtime_error("unbound Ref_Counter");
	// }

private:
	std::size_t *p;
};

#endif













