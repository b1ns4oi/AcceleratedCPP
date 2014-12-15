
#include "Core.h"
#include <string>
#include <istream>
#include <stdexcept>
// #include "Handle.h"
#include "Ptr.h"


// class Student_info {
// public:
// 	Student_info() : cp(0) { }
// 	Student_info(std::istream& is) : cp(0) { read(is); }
// 	Student_info(const Student_info&);
// 	Student_info& operator=(const Student_info&);
// 	~Student_info() { delete cp; }

// 	std::istream& read(std::istream&);

// 	std::string name() const 
// 	{
// 		if(cp) return cp->name();
// 		else throw std::runtime_error("uninitialized student");
// 	}

// 	double grade() const 
// 	{
// 		if(cp) return cp->grade();
// 		else throw std::runtime_error("uninitialized student");
// 	}

// 	static bool compare(const Student_info& s1, const Student_info& s2) 
// 	{
// 		return s1.name() < s2.name();
// 	}
// 	// 13-2
// 	bool valid() const
// 	{
// 		return cp->valid();
// 	}

// private:
// 	Core *cp;
// };

// Student_info::Student_info(const Student_info& s1) : cp(0)
// {
// 	if(s1.cp)
// 		cp = s1.cp->clone();
// }

// Student_info& Student_info::operator=(const Student_info& rhs) 
// {
// 	if(this != &rhs) {
// 		delete cp;
// 		if(rhs.cp)
// 			cp = rhs.cp->clone();
// 		else
// 			cp = 0;
// 	}
// 	return *this;
// } 

// std::istream& Student_info::read(std::istream& in)
// {
// 	delete cp;

// 	if(in) {
// 		char ch;
// 		in >> ch;
// 		if(ch == 'U')
// 			cp = new Core(in);
// 		else
// 			cp = new Grad(in);
// 	}
// 	return in;
// }




//======== Student_info in Chapter 14 =========
// it uses one of the handle class in Chapter 14 to deal with the underlying pointer management

class Student_info {
public:
	Student_info() { }
	Student_info(std::istream& is) { read(is); }

	std::istream& read(std::istream&);

	std::string name() const 
	{
		if(cp) return cp->name();
		else throw std::runtime_error("uninitialized student");
	}

	double grade() const 
	{
		if(cp) return cp->grade();
		else throw std::runtime_error("uninitialized student");
	}

	static bool compare(const Student_info& s1, const Student_info& s2) 
	{
		return s1.name() < s2.name();
	}
	// 13-2
	bool valid() const
	{
		return cp->valid();
	}

private:
	Ptr<Core> cp;
};

std::istream& Student_info::read(std::istream& is)
{
	char ch;
	is >> ch;
	if(ch == 'U') 
		cp = new Core(is);
	else
		cp = new Grad(is);
	return is;
}




















