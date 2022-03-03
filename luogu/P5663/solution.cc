#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, q;
vector<int> v[100010];
int odd[100010], even[100010];

void bfs() {
    memset(odd, 0x3f, sizeof(odd));
    memset(even, 0x3f, sizeof(even));
    queue< pair<int, int> > q;
    for(int i : v[1]) {
	odd[i] = 1;
	q.push(make_pair(i, 1));
    }
    while(q.size()) {
	int x = q.front().first, y = q.front().second;
	for(int i : v[x]) {
	    if(y % 2 == 1) {
		if(y + 1 < even[i]) {
		    even[i] = y + 1;
		    q.push(make_pair(i, y + 1));
		}
	    } else {
		if(y + 1 < odd[i]) {
		    odd[i] = y + 1;
		    q.push(make_pair(i, y + 1));
		}
	    }
	}
	q.pop();
    }
}

int main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i) {
	int x, y;
	cin >> x >> y;
	v[x].push_back(y);
	v[y].push_back(x);
    }

    bfs();

    while(q--) {
	int a, L;
	cin >> a >> L;
	if(L % 2 == 0) 
	    even[a] <= L ? puts("Yes") : puts("No");
	else 
	    odd[a]  <= L ? puts("Yes") : puts("No");
    }
    return 0;
}
