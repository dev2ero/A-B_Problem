class Solution {
public:
    void backtrace(vector<vector<int>>& res, vector<int>& output, int layer, int len) {
        if(layer == len) {
            res.emplace_back(output);
            return;
        }
        for(int i = layer; i<len; i++) {
            swap(output[i], output[layer]);
            backtrace(res, output, layer+1, len);
            swap(output[i], output[layer]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrace(res, nums, 0, (int)nums.size());
        return res;
    }
};
