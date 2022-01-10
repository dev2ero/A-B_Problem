#include <iostream>
#include <vector>
#include <cmath>
 
#define LIMIT 1000000
 
using namespace std;
 
int main() {
	vector<bool> prime(LIMIT, true);
	prime[1] = false;
	for(int i = 2; i < sqrt(LIMIT); ++i)
		if(prime[i] == true)
			for(int j = i * i; j < LIMIT; j += i)
				prime[j] = false;
 
	int n;
	cin >> n;
	long long cur;
	while(n--) {
		cin >> cur;
		long long sq = sqrt(cur);
		if(sq * sq == cur
		  && prime[(int)sqrt(cur)] == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
