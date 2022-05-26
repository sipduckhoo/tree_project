#include "tree_header.h"

int main() {
	treesys s;
	s.inputdata(s.getvalue(), 8);
	s.inputdata(s.getvalue(), 3);
	s.inputdata(s.getvalue(), 6);
	s.inputdata(s.getvalue(), 10);
	s.inputdata(s.getvalue(), 1);
	s.inputdata(s.getvalue(), 5);
	s.inputdata(s.getvalue(), 9);
	s.inputdata(s.getvalue(), 4);
	s.inputdata(s.getvalue(), 2);
	s.inputdata(s.getvalue(), 7);
	
	if (s.search_exist(5))
		cout << 5 << " is in the tree." << endl;
	else
		cout << 5 << "That isn`t in the tree." << endl;
	
	if (s.search_exist(11))
		cout << 11 << " is in the tree." << endl;
	else
		cout << 11 << " isn`t in the tree." << endl;
	s.preorder(s.getvalue());
	cout << endl;
	s.order(s.getvalue());
	cout << endl;
	s.aftorder(s.getvalue());
	cout << endl;
	s.deletedata(2);
	s.deletedata(5);
	s.deletedata(1);
	s.deletedata(7);
	s.deletedata(10);
	s.preorder(s.getvalue());
	return 0;
}