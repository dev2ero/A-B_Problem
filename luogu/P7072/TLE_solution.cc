#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    int p = 0;
    vector<int> scores;
    for(int i = 0; i < n; ++i) {
	int cur;
	cin >> cur;
	p += 1;
	scores.push_back(cur);
	sort(scores.rbegin(), scores.rend());
	cout << scores[ max(0, p * w / 100 - 1) ] << " ";
    }

    cout << endl;
    return 0;
}
