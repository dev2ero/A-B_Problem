class Solution {
public:
    string replaceSpace(string s) {
        string result;

        for(char c : s) {
            if(c == ' ') {
                result += "%20";
            } else {
                result += c;
            }
        }

        return result;
    }
};
