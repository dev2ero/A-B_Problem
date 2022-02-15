#include <iostream>

using namespace std;

int a[40000];

int main() {
    int n, t;

    cin >> n >> t;
    for(int i = 1; i <= n - 1; ++i) cin >> a[i];

    int step = 1;
    while(step < t) step += a[step];

    if(step == t)
	cout << "YES" << endl;
    else
	cout << "NO" << endl;

    return 0;
}
