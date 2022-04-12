class Solution {
private:
    bool is_in_bound(int i, int j, int m, int n) {
        return i>=0&&i<m&&j>=0&&j<n;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> cp = board;
        const int m = board.size();
        const int n = board[0].size();
        vector<pair<int, int>> nbrs = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1},
        };
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                int livenbrs = 0;
                for(auto& nbr: nbrs) {
                    if(is_in_bound(i+nbr.first, j+nbr.second, m, n)) {
                        if(board[i+nbr.first][j+nbr.second]) ++livenbrs;
                    }
                }
                if(board[i][j]) {
                    if(livenbrs < 2) cp[i][j] = 0;
                    else if(livenbrs > 3) cp[i][j] = 0;
                } else {
                    if(livenbrs == 3) cp[i][j] = 1;
                }
            }
        }
        board = cp;
    }
};