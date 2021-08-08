#include <iostream>

using namespace std;


int main() {
    int n; cin >> n;

    int evenness[2] = {0, 0};
    int lastodd(0), lasteven(0);

    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;
        evenness[a & 1]++;

        if(a & 1) lastodd = i;
        else      lasteven = i;

        if(evenness[0] && evenness[1] && evenness[0] + evenness[1] > 2) {
            if(evenness[0] == 1) cout << lasteven << endl;
            if(evenness[1] == 1) cout << lastodd << endl;
            return 0;
        }
    }
}
