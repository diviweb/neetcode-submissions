class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& pac, vector<vector<int>>& heights) {
        pac[r][c] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++) {
        int rl = r + dx[k];
        int cl = c + dy[k];    
        if(rl >= 0 && cl >= 0 && rl < heights.size() && cl < heights[0].size() && !pac[rl][cl] && heights[r][c] <= heights[rl][cl]) {
            dfs(rl, cl, pac, heights);
        }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++) {
            dfs(i, 0, pac, heights);
            dfs(i, cols-1, atl, heights);
        }
        for(int i = 0; i < cols; i++) {
            dfs(0, i, pac, heights);
            dfs(rows-1, i, atl, heights);
        }
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};