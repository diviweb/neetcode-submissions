class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(target > matrix[mid][m-1])
                low = mid + 1;
            else if(target < matrix[mid][0])
                high = mid - 1;
            else {
                int left = 0;
                int right = m-1;
                while(left <= right) {
                    int mid2 = left + (right - left)/2;
                    if(matrix[mid][mid2] == target)
                        return true;
                    else if(target < matrix[mid][mid2])
                        right = mid2 - 1;
                    else
                        left = mid2 + 1;
                }
                return false;
            }
        }
        return false;
    }
};
