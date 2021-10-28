#include <iostream>

int main() {
	int num, sum = 0;
	while( std::cin >> num )
		sum += num;
	std::cout << sum << std::endl;
	return 0;
}
