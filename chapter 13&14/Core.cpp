// contains both Core and Grad class implementation


#include <string>
#include <istream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Core.h"

using std::string;
using std::istream;
using std::vector;
using std::min;

// Core::Core() : midterm(0), final(0) { }
// Core::Core(istream& in) { read(in); }

string Core::name() const { return n; }

double Core::grade() const
{
	return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in)
{
	in >> n >> midterm >> final;
	return in;
}

istream& Core::read(istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}

bool Core::valid() const
{
	return !homework.empty();
}


// non-class functions
bool compare(const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
	return compare(*cp1, *cp2);
}


istream& read_hw(istream& in, vector<double>& hw)
{
	if(in) {
		hw.clear();
		double x;
		while(in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
	return 100;
}



// ============
istream& Grad::read(istream& in)
{
	Core::read_common(in);
	in >> thesis;
	read_hw(in, Core::homework);
	return in;
}

double Grad::grade() const
{
	return min(Core::grade(), thesis);
}





















