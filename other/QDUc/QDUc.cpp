#include<iostream>
#include<vector>

using namespace std;

int main() {
    int loop;
    cin >> loop;
    while(loop--) {

        int N, K;
        cin >> N >> K;

        vector<int> target(K, 0);
        for(int i = 0; i < K; ++i) {
            cin >> target[i];
        }

        vector<vector<int>> Tmap(N, vector(N, 0));

    }
    return 0;
}
