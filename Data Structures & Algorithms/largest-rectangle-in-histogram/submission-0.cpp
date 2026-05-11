class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st;
        for(int i = 0; i < heights.size(); i++) {
            int start = i;
            while(!st.empty() && st.top().second > heights[i]) {
                pair<int, int> topEl = st.top();
                int index = topEl.first;
                int currHt = topEl.second;
                maxArea = max(maxArea, (i - index) * currHt);
                start = index;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while(!st.empty()) {
            pair<int, int> topEl = st.top();
            int index = topEl.first;
            int currHt = topEl.second;
            maxArea = max(maxArea, static_cast<int>(heights.size() - index) * currHt);
            st.pop();
        }
        return maxArea;
    }
};
