class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = INT_MIN;
        int left = 0;
        int right = heights.size()-1;
        while(left <= right) {
            ans = max(ans, (min(heights[right],heights[left])*(right-left)));
            if(heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};
