#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	vector<int> z(n);

	for(int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];

	accumulate(x.begin(), x.end(), 0) == 0 &&
	accumulate(y.begin(), y.end(), 0) == 0 &&
	accumulate(z.begin(), z.end(), 0) == 0 ?
		cout << "YES" << endl : cout << "NO" << endl;
}
