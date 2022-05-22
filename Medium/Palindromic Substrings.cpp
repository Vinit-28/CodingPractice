

// Question Link :: "https://leetcode.com/problems/palindromic-substrings/"


// Solution //

class Solution {
public:
    int countSubstrings(string s) {
        
        int len = s.length(),ans=0;
        bool dp[len][len];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<len;i++){
            
            for(int r=0, c=i; (r<len&&c<len); r++,c++){
                
                if( r == c ) dp[r][c] = true;
                else if( s[r] == s[c] && (abs(c-r-1) == 0 || dp[r+1][c-1]) ) dp[r][c] = true, ans+=1;
            }
        }
        return ans + len;
    }
};