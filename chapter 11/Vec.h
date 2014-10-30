
#include <memory>


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

private:
	iterator data;
	iterator avail;
	iterator limit;	
	
	allocator<T> alloc;
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);
	
	void uncreate();
	
	void grow();
	void unchecked_append(const T&);
};
















