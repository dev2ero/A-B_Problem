#include <iostream>

using namespace std;

int main() {
    int n, L, R;
    cin >> n >> L >> R;
    if(R - L >= n) 
	cout << n - 1 << endl;
    else {
	L %= n;
	R %= n;
	if(L > R)
	    cout << n - 1 << endl;
	else
	    cout << R << endl;
    }
}
