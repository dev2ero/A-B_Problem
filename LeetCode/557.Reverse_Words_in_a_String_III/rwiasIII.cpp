class Solution {
public:
    string reverseWords(string s) {
        int word_head = 0, word_tail = 0;
        for(char c:s) {
            if(c!=' ')  word_tail++;
            else {
                reverse(s.begin()+word_head, s.begin()+word_tail);
                word_tail++;
                word_head = word_tail;
            }
        }
        reverse(s.begin()+word_head, s.begin()+word_tail);
        return s;
    }
};
