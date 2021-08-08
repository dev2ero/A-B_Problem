class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n = s.size();

        for( int i=0; i<n/2; i++) {
            exchange( s[i], s[n-i-1]);
        }
    }
    
    void exchange(char& a, char& b) {
        char x = a;
        a = b;
        b = x;
    }
};
