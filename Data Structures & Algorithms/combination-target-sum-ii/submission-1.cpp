class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        backtrack(0, target, cur, candidates);
        return ans;
    }

    void backtrack(int i, int target, vector<int>& cur, vector<int>& candidates) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }

        if(i >= candidates.size() || target < 0) 
            return;
        
        cur.push_back(candidates[i]);
        backtrack(i+1, target - candidates[i], cur, candidates);
        cur.pop_back();
        while(i + 1 < candidates.size() && candidates[i] == candidates[i+1])
            i++;
        backtrack(i+1, target, cur, candidates);
    }
};
