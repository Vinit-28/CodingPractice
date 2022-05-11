

// Question Link :: "https://leetcode.com/problems/count-sorted-vowel-strings/"


// Solution //

class Solution {
public:
    int countVowelStrings(int n) {
        
        int dp[n+1][5];
        int sum = 0;
        memset(dp[0], 0, sizeof(dp[0]));
        
        for(int i=1;i<=n;i++)
            for(int j=0;j<5;j++)
                dp[i][j] = (j==0)? 1 : (dp[i][j-1] + dp[i-1][j]);

        for(int i=0;i<5;i++) sum += dp[n][i];
        
        return sum;
    }
};