// #include <string>
// #include <istream>
// #include <algorithm>
// //#include "Grad.h"

// using std::string;
// using std::istream;
// using std::min;

// // Grad::Grad() : thesis(0) { }
// // Grad::Grad(istream& in) { read(in); }

// istream& Grad::read(istream& in)
// {
// 	Core::read_common(in);
// 	in >> thesis;
// 	read_hw(in, Core::homework);
// 	return in;
// }

// double Grad::grade() const
// {
// 	return min(Core::grade(), thesis);
// }