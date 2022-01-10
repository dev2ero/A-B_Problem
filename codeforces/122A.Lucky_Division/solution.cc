#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> s = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
	for(int i : s) {
		for(int x = 1;;++x) {
			if(i * x <= 1000) s.insert(i * x);
			else break;
		}
	}

	int input; cin >> input;
	s.find(input) != s.end() ? 
		cout << "YES" << endl :
		cout << "NO" << endl;
}
