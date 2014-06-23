class Solution {
private:
    bool valid(vector<vector<char>> &board, pair<int, int> &p) {
        int x = p.first;
        int y = p.second;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return false;
        }
        return board[x][y] == 'O';
    }
    
    void BFS(vector<vector<char>> &board, pair<int, int> s) {
        const int dx[] = {0, -1, 0, 1};
        const int dy[] = {1, 0, -1, 0};
        
        if (board[s.first][s.second] != 'O') {
            return;
        }
        
        queue<pair<int, int>> Q;
        Q.push(s);
        board[s.first][s.second] = 'Y';
        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < 4; i++) {
                auto q = make_pair(x+dx[i], y+dy[i]);
                if (valid(board, q)) {
                    Q.push(q);
                    board[q.first][q.second] = 'Y';
                }
            }
        }
    }
    
public:
    // Time: O(mn)
    // Space: O(mn)
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            BFS(board, make_pair(i, 0));
            BFS(board, make_pair(i, n-1));
        }
        for (int j = 0; j < n; j++) {
            BFS(board, make_pair(0, j));
            BFS(board, make_pair(m-1, j));
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
