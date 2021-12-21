#include <iostream>
#include <stdexcept>

using namespace std;

int dev(int a, int b) {
	if(b == 0) throw runtime_error("can not dev 0");
	return a/b;
}

int main() {
	int a, b;
	cin >> a >> b;
	int c;
	{
		c = dev(a, b);
	}
}
