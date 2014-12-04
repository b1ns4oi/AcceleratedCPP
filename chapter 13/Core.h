// contains both Core and Grad class definition

#include <string>
#include <istream>
#include <vector>

class Core {
public:
	Core(): midterm(0), final(0) { }
	Core(std::istream& in)  { read(in); }

	std::string name() const;

	virtual std::istream& read(std::istream&);
	virtual double grade() const;

protected:
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
private:
	double thesis;
};

bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);
std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double, double, const std::vector<double>&);


