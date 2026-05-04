class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
            suffix[i] = suffix[i-1] * nums[n-i];
        }
        for(int i = 0; i < n; i++) {
            ans.push_back(prefix[i] * suffix[n-1-i]);
        }
        return ans;
    }
};
