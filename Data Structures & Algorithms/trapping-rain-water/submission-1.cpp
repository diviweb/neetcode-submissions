class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        int leftMax = height[0];
        int rightMax = height[n-1];
        while(l < r) {
            if(leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                ans = ans + (leftMax - height[l]);
            }
            else {
                r--;
                rightMax = max(rightMax, height[r]);
                ans = ans + (rightMax - height[r]);
            }
        }
        return ans;
    }
};
