class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        queue <pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
            int rows = q.front().first;
            int cols = q.front().second;
            q.pop();
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++) {
                if(rows + dx[k] < 0 || cols + dy[k] < 0 || rows + dx[k] >= grid.size() || cols + dy[k] >= grid[0].size() || grid[rows + dx[k]][cols + dy[k]] != 1)
                    continue;
                grid[rows + dx[k]][cols + dy[k]] = 2;
                q.push({rows + dx[k], cols + dy[k]});
                fresh--;
            }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
