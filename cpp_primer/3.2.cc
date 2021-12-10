#include <iostream>

int main() {
	std::string a;
	for(;;) {
		// cin >> a;
		getline(std::cin, a);
		std::cout << a << std::endl;
	}
}
