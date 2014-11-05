
#include <iostream>
#include <iterator>
#include <string>
#include <ostream>
#include "List_beta.h"


using std::cout;
using std::endl;
using std::string;

int main()
{
	List_beta<string> list(10, "wuwuwu");
	List_beta<string> list2(5, "hi");

	List_beta<string>::iterator pos = list2.begin();

	if (list.iter_valid(pos))
		List_beta<string>::iterator ret = list.insert(pos, "binz");
	else
		cout << "invalid pos" << endl;

}

