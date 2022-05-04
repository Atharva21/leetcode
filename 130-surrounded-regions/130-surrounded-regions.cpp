class Solution {
private:
    int m, n;
    bool valid(int i, int j) {
        return i>=0&&i<m&&j>=0&&j<n;
    }
    vector<pair<int, int>> dirs = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(!valid(i, j) || board[i][j] != 'O') return;
        board[i][j] = '#';
        for(auto& dir: dirs) dfs(board, i+dir.first, j+dir.second);
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if((i==0||i==m-1||j==0||j==n-1) && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};