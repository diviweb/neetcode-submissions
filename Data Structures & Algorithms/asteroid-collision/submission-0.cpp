class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(auto a: asteroids) {
            while(!st.empty() && st.top() > 0 && a < 0) {
                int diff = a + st.top();
                if(diff > 0) {
                    a = 0;
                }
                else if(diff < 0) {
                    st.pop();
                }
                else {
                    a = 0;
                    st.pop();
                }
            }
            if(a != 0)
                st.push(a);
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};