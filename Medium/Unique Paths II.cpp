

// Question Link :: "https://leetcode.com/problems/unique-paths-ii/"


// Solution //

class Solution {
public:
    
    long getTotalPaths(int &place, long &value){
        
        return (place==0)? value : 0;
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        long dp[m][n];
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                if( grid[i][j] ) dp[i][j] = 0; 
                else if( i==m-1 && j==n-1 ) dp[i][j] = !grid[i][j];
                else if( i==m-1 ) dp[i][j] = getTotalPaths(grid[i][j+1], dp[i][j+1]);
                else if( j==n-1 ) dp[i][j] = getTotalPaths(grid[i+1][j], dp[i+1][j]);
                else dp[i][j] = getTotalPaths(grid[i+1][j], dp[i+1][j]) + getTotalPaths(grid[i][j+1], dp[i][j+1]);
                
            }
        }
        return dp[0][0];
    }
};