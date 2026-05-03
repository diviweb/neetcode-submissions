class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        for(auto &it: count) {
            freq[it.second].push_back(it.first);
        }
        for(int i = freq.size()-1; i >= 0; i--) {
            for (int n : freq[i]) {
            ans.push_back(n);
            if(ans.size() == k)
                return ans;
            }
        }
        return ans;
    }
};
