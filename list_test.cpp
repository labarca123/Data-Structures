#include <list_char.h>
#include <iostream>

int main() {
	c_list_char yope;
	int i,j,k;
	char first, last;
	/*char l = 'a';

	i = yope.push_front(l);
	j = yope.push_front(l);

	if( yope.find(l) )
		std::cout << "i found it\n";

	k = yope.pop_front();

	if( !yope.find(l) )
		std::cout << "i didn't found it\n" ;

	if( yope.empty() )
		std::cout << "empty\n";

	std::cout << i << " i\t" << j << " j\t" << k << " k\n";
	*/

	/*char first ;
	char last ;

	first = yope.get_first();
	std::cout << first << "\n";

	last = yope.get_last();
	std::cout << last << "\n";

	yope.pop_front();

	first = yope.get_first();
	std::cout << first << "\n";

	last = yope.get_last();
	std::cout << last << "\n";*/

	char a = 'a';
	char b = 'b';
	char c = 'c';

	i = yope.push_back(a);
	j = yope.push_back(b);
	yope.push_back(c);
	/*
	yope.pop_front();

	yope.pop_back();
	*/

	std::cout << "my size is: " << yope.size() << "\n";

	yope.erase(b);

	std::cout << "my size is: " << yope.size() << "\n";

	if( yope.find(b) )
		std::cout << "i found it\n";
	else
		std::cout << "i didn't found it\n";
	

	return 0;
}