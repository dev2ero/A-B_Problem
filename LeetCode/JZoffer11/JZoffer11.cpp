class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]) {
                right = mid;
            } else {
                right -= 1;
            }
        }
        return numbers[left];
    }
};
