class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i]) > 0)
                return true;
            mp[nums[i]]++;
        }
        return false;
    }
};