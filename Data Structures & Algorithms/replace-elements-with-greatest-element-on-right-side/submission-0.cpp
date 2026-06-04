class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxVal = -1;
        for(int i = arr.size()-1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = maxVal;
            maxVal = max(maxVal, temp);
        }
        return arr;
    }
};