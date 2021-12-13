#include <iostream>

int main() {
	std::string s = "hello world";
	for(char &c : s) {
		c = 'X';
	}
	std::cout << s << std::endl;
}
