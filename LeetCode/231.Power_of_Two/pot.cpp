#include<iostream>

using namespace std;

class Solution {
public:
    int isPowerOfTwo(int n) {
        if(n == 0)  return false;
        long x = n;
        return (x&(x-1))==0 ;
    }
};

int main() {
    Solution s;
    cout<<s.isPowerOfTwo(2)<<endl;
    cout<<s.isPowerOfTwo(3)<<endl;
    cout<<s.isPowerOfTwo(4)<<endl;
}
