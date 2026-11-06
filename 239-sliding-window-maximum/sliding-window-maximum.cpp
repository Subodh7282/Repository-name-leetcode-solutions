

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> dq;
        std::vector<int> res;
        
        // 1st window
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for (int i = k; i < nums.size(); ++i) {
            res.push_back(nums[dq.front()]);
            
            // remove not part of curr wind
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // remove the smaller vals
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        res.push_back(nums[dq.front()]);
        return res;
    

    }
};