#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
	for(int i = 5; i <= 1000000; ++i) {
		auto v = new vector<int>(i/2-1);
		iota(v->begin(), v->end(), 2);
		if(none_of(v->begin(), v->end(), [i](int j){return i % j == 0;}))
			cout << i << endl;
		delete v;
	}
}
