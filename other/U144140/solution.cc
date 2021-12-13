#include <iostream>
#include <vector>

using namespace std;

int closest(const vector<int> &v, int t);

int main() {
	int n, q;
	int list[n];
	vector<int> list(n);

	cin >> n >> q;
	for(int i = 0; i < n; ++i) cin >> list[i];

	while(q--) {
		int target;
		cin >> target;
		cout << closest(list, target) << endl;
	}
}

int closest(const vector<int> &v, int t) {
	// TODO
	return 0;
}
