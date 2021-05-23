class Solution {
public:
    bool isUnique(string astr) {
        int mark[26] = {0};
        for(char c : astr) {
            if(mark[c - 'a'] == 1) return false;
            else mark[c - 'a']++;
        }
        return true;
    }
}
