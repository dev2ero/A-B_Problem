#include <iostream>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    if( a * m >= b )
	cout << n / m * b + min(n % m * a, b) << endl;
    else
	cout << n * a << endl;
}
