

// Question Link :: "https://leetcode.com/problems/ones-and-zeroes/"


// Solution //

class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        for(auto &str : strs){
            
            int zero=0,one=0;
            getCount(str, zero, one);
            
            for(int i=m;i>=zero;i--){
                
                for(int j=n;j>=one;j--){
                    
                    dp[i][j] = max(dp[i][j], dp[i-zero][j-one]+1);
                }
            }
        }
        return dp[m][n];
    }
    
    
    void getCount(string &str, int &zero, int &one){
        
        for(auto &ch : str)
            ch == '0'? zero+=1 : one+=1;
    }
};