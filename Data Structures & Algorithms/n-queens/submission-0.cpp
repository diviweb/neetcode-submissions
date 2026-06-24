class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    vector<vector<string>> ans;

    void backtrack(int r, int n, vector<string> board) {
        if(r == n) {
            ans.push_back(board);
        }

        for(int c = 0; c < n; c++) {
        if(cols.count(c) || posDiag.count(r+c) || negDiag.count(r-c)) {
            continue;
        }

        cols.insert(c);
        posDiag.insert(c+r);
        negDiag.insert(r-c);
        board[r][c] = 'Q';

        backtrack(r+1, n, board);

        cols.erase(c);
        posDiag.erase(c+r);
        negDiag.erase(r-c);
        board[r][c] = '.';
    }
    }

    vector<vector<string>> solveNQueens(int n) {
       vector<string> board(n , string(n, '.'));
       backtrack(0, n, board);
       return ans;
    }
};
