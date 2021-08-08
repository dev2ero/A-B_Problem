#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        unordered_set<char> occ;

        int right = 0;
        for( int left=0; left<s.size(); left++ ){
            while( right != s.size() && !occ.count(s[right]) ){
                occ.insert( s[right] );
                right++;
            }

            ans = max( ans, right-left );

            occ.erase( s[left] );
        }


        return ans;

    }
};

int main() {
    Solution solu;
    int a = solu.lengthOfLongestSubstring( "a" );
    cout<<a<<endl;
}
