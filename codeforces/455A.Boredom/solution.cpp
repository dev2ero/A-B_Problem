#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n; cin >> n;
    vector<int> array(n);
    for(int i = 0; i < array.size(); ++i) cin >> array[i];
    
    long long count[100001];
    for(int i = 0; i < array.size(); ++i) count[array[i]]++;
    
    sort(array.begin(), array.end());
    array.erase(unique(array.begin(), array.end()), array.end());

    long long dp[100001][2] = {0};
    dp[1][1] = 1*count[1];
    dp[1][0] = 0;

    for(int i = 2; i < 100001; ++i) {
        dp[i][1] = dp[i-1][0] + (long long)count[i]*i;
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
    }

    cout << max(dp[100000][1], dp[100000][0]) << endl;
    
    return 0;
}
