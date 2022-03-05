#include <iostream>

using namespace std;

int bucket[601];

int main() {
    int n, w;
    cin >> n >> w;

    for(int i = 1; i <= n; ++i) {
	int cur;
	cin >> cur;
	bucket[cur]++;
	int line = max(1, i * w / 100);
	int sum = 0;
	for(int x = 600; x >= 0; --x) {
	    if(bucket[x]) {
		sum += bucket[x];
		if(sum >= line) {
		    cout << x << " ";
		    break;
		}
	    }
	}
    }

    return 0;
}
