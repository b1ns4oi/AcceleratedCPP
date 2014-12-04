#include <iostream>
#include <string>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include "Core.h"
// #include "Grad.h"

using std::vector;
using std::cin; 
using std::cout;
using std::endl;
using std::string;
using std::min;
using std::max;
using std::sort;
using std::streamsize;
using std::setprecision;
using std::domain_error;


int main () 
{
    vector<Core*> students;
    Core *record;
    char ch;
    string::size_type maxlen = 0;

    while(cin >> ch) {
        if(ch == 'U')
          record = new Core;
        else
          record = new Grad;
        record->read(cin);
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_Core_ptrs);

    for(vector<Core*>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i]->name() << string(maxlen + 1 - students[i]->name().size(), ' ');
        try {
            double final_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
        delete students[i];
    }
}




// class Polygon {
//   protected:
//     int width, height;
//   public:
//     void set_values (int a, int b)
//       { width=a; height=b; }
//     virtual string area () { return "hi"; }
// };

// class Rectangle: public Polygon {
//   public:
//     void set_values (int a, int b)
//       { width=a; height = a+b; }
//     string area ()
//       { return "widthheight"; }
// };












