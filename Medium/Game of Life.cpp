

// Question Link :: "https://leetcode.com/problems/game-of-life/"


// Solution //

class Solution {
public:
    
    bool isValid(int &m, int &n, int &i, int &j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int getLiveCells(vector<vector<int>>& board, int &m, int &n, int &x, int &y){
            
        int dirX[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dirY[] = {0, 0, 1, -1, 1, -1, -1, 1};
        int liveCells = 0;
        
        for(int i=0; i<8; i++){
            
            int newX = dirX[i]+x, newY = dirY[i]+y;
            
            if( isValid(m, n, newX, newY) ) liveCells += (board[newX][newY] == INT_MAX)? 0 : (board[newX][newY] == INT_MIN)? 1 : board[newX][newY];
        }
        return liveCells;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        // 0 => INT_MAX => 1           
        // 1 => INT_MIN => 0
        
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                int liveCells = getLiveCells(board, m, n, i, j);
                if( board[i][j] == 1 ){
                    board[i][j] = (liveCells == 3 || liveCells == 2)? 1 : INT_MIN;
                }
                else{
                    board[i][j] = (liveCells == 3)? INT_MAX : 0;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] = (board[i][j] == INT_MIN)? 0 : (board[i][j] == INT_MAX)? 1 : board[i][j];
            }
        }
    }
};