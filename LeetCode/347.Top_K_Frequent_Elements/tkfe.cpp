class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nc;
        vector<vector<int>> bucket(nums.size()+1);
        vector<int> result;

        for(int num : nums) nc[num]++;
        for(const auto& [num, count] : nc) bucket[count].push_back(num);

        for(int i = bucket.size() - 1; i > 0 && k > 0; --i) {
            if(bucket[i].size() == 0) continue;
            result.insert(result.end(), bucket[i].begin(), bucket[i].end());
            k -= bucket[i].size();
        }

        return result;
    }
};
