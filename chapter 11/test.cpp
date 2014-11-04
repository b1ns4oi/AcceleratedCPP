
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
	for(List_beta<string>::iterator it = list.begin(); it != list.end(); it = it->next)
		cout << it->val << endl;
}

