#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> v;

	v.push_back(a+b+c);
	v.push_back(a*b+c);
	v.push_back(a+b*c);
	v.push_back(a*b*c);
	v.push_back(a*(b+c));
	v.push_back((a+b)*c);

	sort(v.begin(), v.end());
	cout << *(v.end()-1) << endl;
}
