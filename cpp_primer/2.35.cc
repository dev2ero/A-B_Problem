#include <iostream>

int main() {
	const int i = 42;
	auto j = i; // const int
	const auto &k = i; // const int &
	auto *p = &i; // int * const
	// ?
}
