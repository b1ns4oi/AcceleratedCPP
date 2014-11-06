
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
	List_beta<string> list2;
	list2.push_back("hi");
	list2.push_back("binz");
	
	cout << list2 << endl;
	
	
	List_beta<string>::iterator ret = list2.erase(NULL);
	cout << list2 << endl;
	
	if(ret == NULL)
		cout <<"ret is null" << endl;
}

