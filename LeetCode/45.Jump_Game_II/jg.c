int jump(int* nums, int numsSize){
    
    int result = 0;
    int start = 0; 
    int end = 1;
    int max_pos = 0;

    while(end < numsSize){
        
        for(int i = start; i < end; ++i) {
            max_pos = max(max_pos, nums[i] + i);
        }

        start = end;
        end = max_pos + 1;

        result++;

    }

    return result;
}
