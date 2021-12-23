#include <iostream>
#include <vector>

using namespace std;

int add(int a, int b) {
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

int main() {
	vector<int (*)(int, int)> v;
	v.push_back(add);
	v.push_back(sub);
	cout << "2+1=" << (*v[0])(2,1) << endl;
	cout << "2-1=" << (*v[1])(2,1) << endl;
	return 0;
}
