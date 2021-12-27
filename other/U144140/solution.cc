#include <iostream>
#include <vector>

using namespace std;

unsigned int sum_sub(const vector<int> &v, int i, int j, int t);
unsigned int closest(const vector<int> &v, int t);

int main() {
	int n, q;
	cin >> n >> q;

	vector<int> list(n);
	for(int i = 0; i < n; ++i) cin >> list[i];

	while(q--) {
		int target;
		cin >> target;
		cout << closest(list, target) << endl;
	}
}

unsigned int closest(const vector<int> &v, int t) {
	unsigned int min = UINT32_MAX;
	for(int i = 0; i < v.size(); ++i)
		for(int j = 0; j < v.size(); ++j)
			sum_sub(v, i, j, t) < min ? min = sum_sub(v, i, j, t) : 0;
	return min;
}

unsigned int sum_sub(const vector<int> &v, int i, int j, int t) {
	int sum = 0;
	for(int x = i; x <= j; ++x)
		sum += v[x];
	return abs(sum - t);
}
