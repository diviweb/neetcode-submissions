class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = *max_element(piles.begin(), piles.end());
        int left = 1;
        int right = maxVal;
        while(left <= right) {
            int mid = left + (right - left)/2;
            long long sum = 0;
            for(int i = 0; i < piles.size(); i++) {
                sum += (piles[i] + mid - 1)/mid;
            }
            if(sum <= h) {
                maxVal = min(mid, maxVal);
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return maxVal;
    }
};
