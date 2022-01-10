#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned int n, m;
	cin >> n >> m;
	
	vector<unsigned int> v(m);
	for(int i = 0; i < m; ++i) cin >> v[i];

	unsigned int sum = 0;
	unsigned int cur = 1;
	for(auto next : v) {
		sum += (next - cur) % n;
		cur = next;
	}

	cout << sum << endl;
}
