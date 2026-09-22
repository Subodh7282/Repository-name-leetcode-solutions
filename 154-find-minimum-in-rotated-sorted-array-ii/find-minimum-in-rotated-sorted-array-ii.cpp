class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[end]) {
                // Minimum lies in the right unsorted portion
                st = mid + 1;
            } 
            else if (nums[mid] < nums[end]) {
                // Minimum lies in the left portion or at mid
                end = mid;
            } 
            else {
                // When nums[mid] == nums[end], safely reduce search space by 1
                end--;
            }
        }

        return nums[st];
    }
};