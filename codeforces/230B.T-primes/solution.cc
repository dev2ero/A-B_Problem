#include <iostream>
#include <vector>
#include <cmath>

#define LIMIT 1000000

using namespace std;

int main() {
	vector<bool> prime(LIMIT, true);
	prime[0] = false;
	prime[1] = false;
	for(int i = 2; i < LIMIT; ++i)
		if(prime[i] == true)
			for(int j = i * i; j < LIMIT; j += i)
				prime[j] = false;
	for(bool b : prime) cout << b;
}
