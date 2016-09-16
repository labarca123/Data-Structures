#include <list.h>
#include <iostream>

int main() {
	c_list<char> yope;
	std::cout << yope.size() << std::endl;
	std::string joder;

	yope.push_back('a');
	std::cout << yope.size() << std::endl;

	return 0;
}