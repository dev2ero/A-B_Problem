class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> NumMap;
        for(int num : nums) {
            if(NumMap[num] == true) {
                return num;
            } else {
                NumMap[num] = true;
            }
        }
        return -1;
    }
};
