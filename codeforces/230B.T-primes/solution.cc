#include <iostream>
#include <vector>
#include <cmath>

#define LIMIT 1000010

using namespace std;

bool isPrime(long long n)
{
    int skip=0;
    if(n<2)
        return false;
    else if(n==2)
        return true;
    long long limit=sqrt(n);
    if(n%2==0)
        return false;
        for(int j=3; j<=limit; j+=2){
            if(n%j==0)
                return false;
            }
    return true;
}

int main() {
	int n;
	cin >> n;
	long long cur;
	while(n--) {
		cin >> cur;
		long long sq = sqrt(cur);
		if(sq*sq == cur
		  && isPrime((long long)sqrt(cur)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
