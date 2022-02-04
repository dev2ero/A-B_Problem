#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v = {0};
    for(int i = 1; i <= n; ++i) {
	int temp; cin >> temp;
	v.push_back(v[i-1] + temp);
    }

    int minn = INT_MAX;
    int idx = -1;
    for(int i = k; i <=n; ++i) {
	if(v[i] - v[i-k] < minn) {
	    minn = v[i] - v[i-k];
	    idx = i - k + 1;
	}
    }

    cout << idx << endl;
    return 0;
}
