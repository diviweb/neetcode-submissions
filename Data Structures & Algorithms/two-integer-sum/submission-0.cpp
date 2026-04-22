class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(!mp.empty() && mp.find(target-nums[i]) != mp.end()) {
                int j = mp[target-nums[i]];
                ans.push_back(j);
                ans.push_back(i);
            }
            mp[nums[i]] = i;    
        }
        return ans;
    }
};
