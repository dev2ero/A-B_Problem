#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> num;
    for(int i = 0; i < n; ++i) {
	int temp;
	cin >> temp;
	num.insert(temp);
    }

    if(num.size() < 2) cout << -1 << endl;
    else cout << max(	*(------num.end()), 
			*(--num.end()) % *(----num.end())
		    ) << endl;

    return 0;
}
