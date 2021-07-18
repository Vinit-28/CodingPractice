

// Question Link :: "https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1#"



// Solution //

class Solution{
    public:
    vector<vector<int>> dp;

    int recursion(string &str, int i, int j){
    
        if( i<j && dp[i][j] == -1 ){
            
            if( str[i] == str[j] )
                dp[i][j] = recursion(str,i+1,j-1);
        
            else{
                
                int inertionStart = recursion(str, i, j-1);
                int inertionLast = recursion(str, i+1, j);
                dp[i][j] = min(inertionStart, inertionLast)+1;
            }
        }
        else if( dp[i][j] == -1 )
            dp[i][j] = 0;
        
        return dp[i][j];
    }
    
    int countMin(string str){
        
        int n = str.length();
        dp.clear();
        dp.resize(n, vector<int>(n,-1));
        recursion(str, 0, n-1);
        return dp[0][n-1];
    }
};
