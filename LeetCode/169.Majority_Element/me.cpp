class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max_value = 0, max_key = 0;
        unordered_map<int, int> nmap;
        for(int num : nums) {
            ++nmap[num];
            if(nmap[num] > max_value) {
                max_value = nmap[num];
                max_key = num;
            }
        }
        return max_key;
    }
};
