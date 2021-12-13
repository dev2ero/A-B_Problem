#include <iostream>

int main() {
	const std::string s = "hello world";
	// char & const 
	for(auto &c : s) std::cout << c;
}
