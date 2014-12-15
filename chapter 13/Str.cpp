// 'Str' class implementation using the 'Ptr' class
// compile this program with : g++ -o a Str.cpp Core.cpp

#include "Ptr.h"
#include <vector>
#include <istream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Str {
	friend std::istream& operator>>(std::istream&, Str&);
public:
	Str& operator+=(const Str& s) {
		data.make_unique();
		std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
		return *this;
	}

	typedef vector<char>::size_type size_type;

	Str(): data(new vector<char>) { }
	Str(const char *cp): data(new vector<char>) {
		std::copy(cp, cp+std::strlen(cp), std::back_inserter(*data));
	}
	Str(size_type n, char c): data(new vector<char>(n, c)) { }

	char & operator[](size_type i) {
		data.make_unique();
		return (*data)[i];
	}
	const char& operator[](size_type i) const { return (*data)[i]; }

	size_type size() const { return data->size(); }
	
private:
	// using 'Ptr<vector<char> >' instead of 'vector<char>'
	Ptr<vector<char> > data;
}; 

std::ostream& operator<<(std::ostream& os, const Str& s)
{
	for(Str::size_type i = 0; i < s.size(); ++i)
		os << s[i];
	return os;
}

Str operator+(const Str& s1, const Str& s2)
{
	Str ret = s1;
	ret += s2;
	return ret;
}

int main()
{
	Str s = "hi";
	Str s2 = "binz";
	std::cout << (s + s2) << std::endl;
}

















