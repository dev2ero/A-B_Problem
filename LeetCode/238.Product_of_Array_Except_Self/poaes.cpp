class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> right_m(nums.size());

        for( int i = nums.size()-1; i>=0; i-- ) {
            if( i == nums.size()-1 )    right_m[i] = 1;
            else {
                right_m[i] = nums[i+1] * right_m[i+1];
            }  
        }

        int cache1 = 1, cache2 = 1;
        for( auto i = nums.begin(); i!=nums.end(); i++ ) {
            cache2 = *i;
            if(i == nums.begin())   *i = 1;
            else                    *i = cache1 * *(i-1);
            cache1 = cache2; 
        }

        for( int i = 0; i<nums.size(); i++ ){
            nums[i] *= right_m[i];
        }

        return nums;

    }
};
