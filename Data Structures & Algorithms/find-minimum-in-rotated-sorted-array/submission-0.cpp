class Solution {
public:
    int findMin(vector<int> &nums) {
        int minEle = INT_MAX;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            // If already sorted
            if (nums[left] <= nums[right]) {
                minEle = min(minEle, nums[left]);
                break;
            }
            int mid = left + (right - left)/2;
            if(nums[left] <= nums[mid]) { 
                minEle = min(minEle, nums[left]);
                left = mid+1; 
            }
            else {
                minEle = min(minEle, nums[mid]);
                right = mid-1;
            }    
        }
        return minEle;
    }
};
