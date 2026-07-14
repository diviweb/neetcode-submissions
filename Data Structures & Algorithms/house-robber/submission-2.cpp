class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = max(a + nums[i], b);
            a = b;
            b = sum;
        }
        return sum;
    }
};
