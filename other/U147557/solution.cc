#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int a, b, c;
	char op;
	cin >> a >> b >> op;

	switch(op) {
	case '&':
		c = a & b;
		break;
	case '|':
		c = a | b;
		break;
	case '^':
		c = a ^ b;
		break;
	}

	cout << bitset<32>(a) << endl;
	cout << bitset<32>(b) << endl;
	cout << string(32, '-') << endl;
	cout << bitset<32>(c) << endl;
	return 0;
}
