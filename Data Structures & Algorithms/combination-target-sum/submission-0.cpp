class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(0, target, cur, nums);
        return ans;
    }

    void backtrack(int i, int target, vector<int>& cur, vector<int>& nums) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }

        if(i >= nums.size() || target < 0)
            return;

        cur.push_back(nums[i]);
        backtrack(i, target-nums[i], cur, nums);
        cur.pop_back();
        backtrack(i+1, target, cur, nums);
    }
};
