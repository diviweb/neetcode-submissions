class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> pq;
        for(int i = 0; i < points.size(); i++) {
            long long dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({dist, i});
            while(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back({points[pq.top().second][0], points[pq.top().second][1]});
            pq.pop();
        }
        return ans;
    }
};
