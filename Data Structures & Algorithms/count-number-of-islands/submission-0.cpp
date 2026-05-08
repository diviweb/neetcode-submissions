class Solution {
public:

    void bfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;
        grid[i][j] = '2';
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++) {
            bfs(grid, i+dx[k], j+dy[k]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
