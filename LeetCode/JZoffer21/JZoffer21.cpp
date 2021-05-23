class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() == 0) return nums;

        int i = 0, j = nums.size() - 1;
        while( i != j) {
            while(nums[i] % 2 != 0 && i != j) ++i;
            while(nums[j] % 2 == 0 && i != j) --j;

            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        return nums;
    }
};
