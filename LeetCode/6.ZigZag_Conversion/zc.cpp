#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if( s.size() == 1 )   return s; 
        if( numRows == 1)   return s;
        
        vector<string> rows(numRows);
        int i = 0, flag = -1;

        for( char c : s ){
            rows[i] += c;
            if(i == 0 || i == numRows-1)    flag = -flag;
            i += flag;            
        }     

        string ret;
        for( string row : rows )    ret += row;
        return ret;

    }
};

int main() {
    Solution solu;
    string a = solu.convert("AB", 1);
    cout<<a<<endl;
}
