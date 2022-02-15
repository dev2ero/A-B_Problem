#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    int n, abc[3], dp[4010];
    memset(dp, -40, sizeof(dp));
    dp[0] = 0;

    cin >> n >> abc[0] >> abc[1] >> abc[2];
    for(int i = 0; i < 3; ++i)
	for(int j = abc[i]; j <= n; ++j)
	    dp[j] = max(dp[j], dp[j-abc[i]] + 1);

    cout << dp[n] << endl;
    return 0;
}
