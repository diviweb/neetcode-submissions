class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, board, n);
        return ans;
    }

    void backtrack(int i, vector<string>& board, int n) {
        if(i == n) {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++) {

        if(cols.count(j) || posDiag.count(i+j) || negDiag.count(i-j))
            continue;

        cols.insert(j);
        posDiag.insert(i+j);
        negDiag.insert(i-j);
        board[i][j] = 'Q';
        backtrack(i+1, board, n);
        cols.erase(j);
        posDiag.erase(i+j);
        negDiag.erase(i-j);
        board[i][j] = '.';
        }
    }
};
