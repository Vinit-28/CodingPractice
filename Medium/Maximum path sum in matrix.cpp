

// Question Link :: "https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#"


// Solution //

class Solution{
public:

    
    bool isValid(int x, int y, int &n){
        
        return !( x<0 || y<0 || x>=n || y>=n );
    }

    int maximumPath(int N, vector<vector<int>> mat)
    {
        // code here
        int n = mat.size(), dp[n][n], x[]={1, 1, 1}, y[]={0, 1, -1}, ans=0;
        
        for(int i=n-1;i>=0;i--){
            
            for(int j=n-1;j>=0;j--){
                
                dp[i][j] = mat[i][j];
                
                if( i!= n-1 ){
                    int maxi = INT_MIN;
                    for(int pos=0;pos<3;pos++) 
                        if( isValid(x[pos]+i, y[pos]+j, n) ) 
                            maxi = max(maxi, dp[x[pos]+i][y[pos]+j]);
                    dp[i][j] += maxi;
                }
                
                ans = (i==0)? max(ans, dp[i][j]) : ans;
            }
        }
        return ans;
    }
};