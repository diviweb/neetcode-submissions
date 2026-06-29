class Solution {
public:
    int calculateSum(int start, int end, vector<int>& nums) {
        int a = 0;
        int b = 0;
        int sum = 0;
        for(int i = start; i <= end; i++) {
            sum = max(a + nums[i], b);
            a = b;
            b = sum;
        }
        return sum;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int n = nums.size();
        return max(calculateSum(0, n-2, nums), calculateSum(1, n-1, nums));
    }
};
