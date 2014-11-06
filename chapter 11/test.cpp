
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
	list2.push_back("binz,");
	list2.push_back("how");
	list2.push_back("are");
	list2.push_back("you ?");
	list2.push_back("and");
	list2.push_back("me");

	cout << list2 << endl;
	
	List_beta<string>::iterator pos1 = list2.begin();
	pos1 = pos1->next->next;
	List_beta<string>::iterator pos2 = pos1->next->next->next->next->next;
	List_beta<string>::iterator ret = list2.erase(pos1, pos2);

	cout << list2 << endl;
	cout << list2.size() << endl;

	if(ret == NULL)
		cout <<"ret is null" << endl;
	else cout << ret->val << endl;
}

