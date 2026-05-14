class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0;
        int b = 0;
        int c = INT_MAX;
        for(int i = 2; i <= cost.size(); i++) {
            c = min(cost[i-1]+b, cost[i-2]+a);
            a = b;
            b = c;
        }
        return c;
    }
};
