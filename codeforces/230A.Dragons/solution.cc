#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


int main() {
	int s, n;
	cin >> s >> n;

	vector<pair<int, int>> v;

	while(n--) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	
	sort(v.begin() ,v.end(), [](pair<int, int> a, pair<int, int> b){ return a.first < b.first; });

	for(auto p : v) {
		if(s <= p.first) {
			cout << "NO" << endl;
			return 0;
		} else {
			s += p.second;
		}
	}

	cout << "YES" << endl;
	return 0;
}
