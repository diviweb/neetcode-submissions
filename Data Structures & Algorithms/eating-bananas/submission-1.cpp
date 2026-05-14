class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;
        while(left <= right) {
            long long sum = 0;
            int mid = left + (right - left)/2;
            for(auto it: piles) {
                sum += (it + mid - 1)/ mid;
            }
            if(sum <= h) {
                ans = min(mid, ans);
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return ans;
    }
};
