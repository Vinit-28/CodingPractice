

// Question Link :: "https://leetcode.com/problems/shortest-path-in-binary-matrix/"



// Solution //

class Solution {
public:
    
    int dirR[8] = {1,-1,0,0,1,1,-1,-1};
    int dirC[8] = {0,0,1,-1,1,-1,1,-1};
    
    bool isValid(int &i, int &j, int &m, int &n){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if( grid[0][0] ) return -1;
        
        int m = grid.size(), n = grid[0].size();
        int mat[m][n];
        queue<pair<int, int>> q;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = INT_MAX;
        
        
        // Implementing BFS //  
        q.push({0,0});
        mat[0][0] = 1;
        
        while( q.empty() == false ){
            
            auto curr = q.front();
            int currLen = mat[curr.first][curr.second];
            q.pop();
            
            for(int i=0;i<8;i++){
                int x = dirR[i] + curr.first;
                int y = dirC[i] + curr.second;
                
                if( isValid(x, y, m, n) && grid[x][y] == 0 && mat[x][y] > (currLen+1) ){
                    mat[x][y] = (currLen+1);
                    q.push({x, y});
                }
            }
        }
        
        return (mat[m-1][n-1] == INT_MAX)? -1 : mat[m-1][n-1];
    }
};