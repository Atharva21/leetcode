class Solution {
private:
    vector<bool> getmemo() {
        vector<bool> v(10, false);
        return v;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i) {
            auto v = getmemo();
            for(int j=0;j<9;++j) {
                if(board[i][j] == '.') continue;
                if(v[board[i][j]-'0']) return false;
                v[board[i][j]-'0'] = true;
            }
        }
        for(int i=0;i<9;++i) {
            auto v = getmemo();
            for(int j=0;j<9;++j) {
                if(board[j][i] == '.') continue;
                if(v[board[j][i]-'0']) return false;
                v[board[j][i]-'0'] = true;
            }
        }
        for(int i=0;i<9;i+=3) {
            for(int j=0;j<9;j+=3) {
                auto v = getmemo();
                for(int s=0;s<3;++s) {
                    for(int t=0;t<3;++t) {
                        if(board[i+s][j+t] == '.') continue;
                        if(v[board[i+s][j+t]-'0']) return false;
                        v[board[i+s][j+t]-'0'] = true;
                    }
                }
            }
        }
        return true;
    }
};