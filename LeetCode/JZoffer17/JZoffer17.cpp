class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;

        if(n == 1) {
            return vector<int>{1,2,3,4,5,6,7,8,9};
        }

        for(int i = 0; i <= 9; ++i) {
            dfs(ans, n-1, i);    
        }    

        return ans;
    }

    void dfs(vector<int> &ans, int level, int preNum) {
        for(int i = 0; i <= 9; ++i) {
            if(level == 1) {
                if(preNum * 10 + i != 0)
                    ans.push_back( preNum*10 + i);
            } else {
                dfs(ans, level - 1, preNum*10 + i);
            }
        }
        return;
    }
};
