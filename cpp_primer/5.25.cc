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
	try {
		c = dev(a, b);
	} catch(runtime_error err) {
		cout << err.what() << endl;
		cout << "do not fuxxing dev 0!" << endl;
	}
}
