// contains both Core and Grad class definition
#ifndef GUARD_Core_h
#define GUARD_Core_h


#include <string>
#include <istream>
#include <vector>

class Core {
	friend class Student_info;
public:
	Core(): midterm(0), final(0) { }
	Core(std::istream& in)  { read(in); }
	~Core() { }

	std::string name() const;

	virtual std::istream& read(std::istream&);
	virtual double grade() const;

protected:
	virtual Core* clone() const { return new Core(*this); }
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;

private:
	std::string n;
};

class Grad : public Core {
public:
	Grad() : thesis(0) { }
	Grad(std::istream& in) { read(in); }
	double grade() const;
	std::istream& read(std::istream&);

protected:
	Grad* clone() const { return new Grad(*this); }

private:
	double thesis;
};

bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);
std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double, double, const std::vector<double>&);

#endif
