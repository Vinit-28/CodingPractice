

// Question Link :: "https://leetcode.com/problems/longest-palindromic-substring/submissions/"


// Solution //

class Solution {
public:
    
    string longestPalindrome(string s) {
        
        string ans;
        int n = s.length(), start=0, end=0, maxi=1, dp[n][n];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<n;i++){
            
            for(int row=0, col=i; (row<n && col<n); row++,col++){
                
                if( row == col ) dp[row][col] = 1;
                
                else if( s[row] == s[col] )
                    dp[row][col] = (dp[row+1][col-1] > -1)? dp[row+1][col-1] + 2 : -1;
                
                else dp[row][col] = -1;
                
                if( maxi < dp[row][col] ) maxi= dp[row][col], start=row, end=col;
            }
        }
        
        while(start <= end) ans+=s[start], start++;
        return ans;
    }
};