#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if(n % 2 == 1) {
	cout << -1 << endl;
	return 0;
    }

    vector<long long> pow2;
    pow2.push_back(1);
    for(int i = 1; i <= 26; ++i) 
	pow2.push_back(2 * pow2[i-1]);

    vector<long long> elems;
    for(auto i = pow2.rbegin(); i != pow2.rend(); ++i) {
	if(n < *i) continue;
	n -= *i;
	elems.push_back(*i);
	if(n == 0) {
	    for(long long j : elems) cout << j << " ";
	    return 0;
	}
    }

    cout << -1 << endl;
    return 0;
}
