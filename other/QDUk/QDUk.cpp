#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int loop;
    cin >> loop;
    while(loop--) {

        int coops_num, mates_num;
        cin >> coops_num >> mates_num;

        vector<int> coops(coops_num, 0);
        vector<int> mates(mates_num, 0);

        for(int i = 0; i < coops_num; ++i)  cin >> coops[i];
        for(int i = 0; i < mates_num; ++i)  cin >> mates[i];

        sort(coops.begin(), coops.end());
        sort(mates.begin(), mates.end());

        int count = 0;
        while(!mates.empty() && !coops.empty()) {
            int aMate = mates.back(); mates.pop_back();
            while(aMate < coops.back()) {
                coops.pop_back();
                if(coops.empty()) goto f;
            }

            coops.pop_back();
            count++;
        }
        f:

        cout << count << endl;

    }
    return 0;
}
