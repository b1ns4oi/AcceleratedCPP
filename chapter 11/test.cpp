#include "Vec.h"
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;

int main()
{
	Vec<char> vec;

	vec.push_back('a');
	vec.push_back('b');
	vec.push_back('c');
	cout << "hi world" << endl;

	std::copy(vec.begin(), vec.end(), std::ostream_iterator<char>(cout, ", "));
}

