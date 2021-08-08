#include<iostream>
#include<vector>

using namespace std;

int main() {
    int loop;
    cin >> loop;
    while(loop--) {

        int n;
        cin >> n;
        
        int count[3] = {0, 0, 0};
        for(int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            count[num % 3]++; 
        }

        count[0] += min(count[1], count[2]);
        count[0] += (max(count[1], count[2]) - min(count[1], count[2])) / 3;
        
        cout<<count[0]<<endl;

    }
    return 0;
}
