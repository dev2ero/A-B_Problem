#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main() {
    int loop;
    cin>>loop;

    while(loop--) {

        int N;
        cin>>N;
        vector<uint64_t> timeP(N, 0);
        unordered_map<uint64_t, int> value_index;

        for(int i = 0; i < N; ++i) {
            cin>>timeP[i];
        }

        sort(timeP.begin(), timeP.end());

        for(int i = 0; i < N; ++i) {
            value_index[timeP[i]] = i;
        }
        

        int M;
        cin>>M;
        while(M--) {
            uint64_t left, right;
            cin>>left>>right;

            if(value_index[left] != 0 && value_index[right] != 0) {
                cout << value_index[right] - value_index[left] + 1 << endl;
                continue;
            } else {
                int sum = 0;
                for(int i = 0; i < N; ++i) {
                    if(timeP[i] > right) break;
                    if(left <= timeP[i] && timeP[i] <= right) ++sum;
                }
                cout<<sum<<endl;
            }
        }
    }

    return 0;
}
