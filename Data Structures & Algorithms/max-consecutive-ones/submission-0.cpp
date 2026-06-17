class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currMax = 0, ans  = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                currMax++;
                ans = max(currMax, ans);
            }
            else {
                currMax = 0;
            }
        }
        return ans;
    }
};