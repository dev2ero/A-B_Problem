#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> v(m);
	for(int i = 0; i < m; ++i) cin >> v[i];

	int sum = 0;
	int cur = 1;
	for(int next : v) {
		sum += (next - cur) % 4;
		cur = next;
	}

	cout << sum << endl;
}
