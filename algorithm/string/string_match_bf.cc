#include <iostream>
#include <vector>

using namespace std;

const string s = "abc";

int main() {
    string input;
    vector<int> ans;

    cin >> input;
    int i, j;
    for(i = 0; i < input.size() - s.size() + 1; i++) {
        for(j = 0; j < s.size(); j++)
            if(s[j] != input[i + j]) break;
        if(j == s.size()) ans.push_back(i);
    }

    for(int i : ans) cout << i << " ";
}
