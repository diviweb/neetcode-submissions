class Solution {
public:
    int calculateSum(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = max(rob2, rob1 + nums[i]);
            rob1 = rob2;
            rob2 = sum;
        }
        return sum;
    }

    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());
        return max({nums[0], calculateSum(nums1), calculateSum(nums2)});
    }
};
