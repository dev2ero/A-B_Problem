#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, s, c;

int main() {
    cin >> m >> s >> c;
    vector<int> v(c);

    if(m >= c) {
	cout << c << endl;
	return 0;
    }

    for(int i = 0; i < c; i++) cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> dis;
    for(int i = 0; i < c-1; i++)
	dis.push_back(v[i+1] - v[i] - 1);
    sort(dis.rbegin(), dis.rend());

    int board_num = 1;
    int ans = v[v.size()-1] - v[0] + 1;
    vector<int>::iterator it = dis.begin();
    while(board_num != m) {
	ans -= *it;
	it++;
	board_num++;
    }

    cout << ans << endl;
}
