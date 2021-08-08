

// Question Link :: "https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1"


// Solution //

class Solution
{
    public:
    int maxLength;
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        maxLength = 0;
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(),-1));
        LCS(s1, s2, 0, 0, dp);
        return maxLength;
    }
    
    int LCS(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        
        if( s1[i] == 0 || s2[j] == 0 )
            return 0;
      
        else if( s1[i] == s2[j] && dp[i][j] == -1 )
            dp[i][j] = 1 + LCS(s1, s2, i+1, j+1, dp);
            
        else if( dp[i][j] == -1 )
            dp[i][j] = max(LCS(s1, s2, i+1, j, dp), LCS(s1, s2, i, j+1, dp));
        
        maxLength = max(maxLength, dp[i][j]);
        return dp[i][j];
    }
};
