#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> mates;
    for(int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        mates.push(temp);
    }

    int time = 0;
    vector<int> pipe(m, 0);

    while(!mates.empty()) {
        sort(pipe.begin(), pipe.end());
        pipe[0] += mates.front();
        mates.pop();
    }

    sort(pipe.begin(), pipe.end());
    cout << pipe[m-1] + 1 <<endl;
    return 0;
}
