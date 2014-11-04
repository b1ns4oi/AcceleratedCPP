
#include <iostream>
#include <iterator>
#include <string>
#include "List_beta.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	List_beta<string> list(10, "binz");
	
	List_beta<string> list2 = list;
	
	cout << list.size() << endl;
	for(List_beta<string>::iterator it = list2.begin(); it != list2.end(); it = it->next)
		cout << it->val << endl;
		
	cout << endl;
	
	for(List_beta<string>::iterator it = list.begin(); it != list.end(); it = it->next)
		cout << it->val << endl;
	cout << list2.size() << endl;
}

