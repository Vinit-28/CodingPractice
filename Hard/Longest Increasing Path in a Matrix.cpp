

// Question Link :: "https://leetcode.com/problems/longest-increasing-path-in-a-matrix/"


// Solution //

class Solution {
public:
    
    int dirR[4] = {1,-1,0,0};
    int dirC[4] = {0,0,1,-1};
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, DFS(dp, mat, i, j, m, n));
            }
        }
        return ans;
    }
    
    bool isValid(int &i, int &j, int &m, int &n){
        
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    int DFS(vector<vector<int>> &dp, vector<vector<int>>& mat, int &i, int &j, int &m, int &n){
        
        if( dp[i][j] != -1 ) return dp[i][j];
        
        for(int k=0;k<4;k++){
            
            int r = i + dirR[k];
            int c = j + dirC[k];
            
            if( isValid(r, c, m, n) && mat[r][c] > mat[i][j] ){
                dp[i][j] = max(dp[i][j], DFS(dp, mat, r, c, m, n));
            }
        }
        dp[i][j] = (dp[i][j] == -1)? 1 : dp[i][j]+1;
        return dp[i][j];
    }
};