// compile the students' grading program using : g++ -o a test.cpp Core.cpp
// you can also implement this program using 'Student_info' class, that way, you should 
// #include "Student_info.h" and uncomment the codes in 'main()'

#include <iostream>
#include <string>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <ios>
#include <iomanip>
#include <stdexcept>
#include "Core.h"
// #include "Student_info.h"
// #include "Handle.h"
//#include "Ref_handle.h"
#include "Ptr.h"

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
    //// students' grading programm using 'Student_info' class
    // vector<Student_info> students;
    // Student_info record;
    // // char ch;
    // string::size_type maxlen = 0;

    // while(record.read(cin)) {
    //     maxlen = max(maxlen, record.name().size());
    //     students.push_back(record);
    // }

    // sort(students.begin(), students.end(), Student_info::compare);

    // for(vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    //     cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
    //     try {
    //         double final_grade = students[i].grade();
    //         streamsize prec = cout.precision();
    //         cout << setprecision(3) << final_grade << setprecision(prec) << students[i].valid() << endl;
    //     } catch (domain_error e) {
    //         cout << e.what() << endl;
    //     }
    //     // delete students[i];
    // }

    // students' grading programm using 'Ptr' class
    // you can use either 'Handle' or 'Ref_handle' class to replace 'Ptr'
    vector<Ptr<Core> > students;
    Ptr<Core> record;
    char ch;
    string::size_type maxlen = 0;

    while(cin >> ch) {
        if(ch == 'U')
          record = new Core(cin);
        else
          record = new Grad(cin);
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_Core_handles);

    for(vector<Ptr<Core> >::size_type i = 0; i != students.size(); ++i) {
        cout << students[i]->name() << string(maxlen + 1 - students[i]->name().size(), ' ');
        try {
            double final_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
        // delete students[i];
    }
}










