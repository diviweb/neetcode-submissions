class Solution {
public:
    unordered_map<string, vector<string>> dp;

    vector<string> dfs(string s, vector<string>& wordDict) {
        if(dp.count(s) > 0)
            return dp[s];
        
        if(s.empty())
            return {""};

        vector<string> ans;
        
        for(string w: wordDict) {
            int sz = w.size();
            if(s.substr(0, sz) == w) {
                vector<string> rest = dfs(s.substr(sz), wordDict);
                for(string &r: rest) {
                    ans.push_back(w + (r.empty() ? "" : " ") + r);
                }
            }
        }
        
        return dp[s] = ans;

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict);
    }
};