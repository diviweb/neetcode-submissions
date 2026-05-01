class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int result = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++) {
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            result = max(result, right-left+1);
        }
        return result;
    }
};
