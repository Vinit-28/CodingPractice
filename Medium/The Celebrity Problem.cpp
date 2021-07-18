

// Question Link :: "https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1"


// Solution //

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat, int n) 
    {
        // code here
        for(int j=0;j<n;j++){
            
            if( mat[0][j] == 1 || j==0 ){
                
                if( isCelebrity(mat, n, j) )
                    return j;
            }
        }
        return -1;
    }
    
    bool isCelebrity(vector<vector<int>> &mat, int n, int col){
        
        for(int row = 1; row<n; row++){
            
            if( mat[row][col] == 0 && row != col )
                return false;
        }
        
        for(int j=0; j<n; j++)
            if( mat[col][j] )
                return false;
        return true;
    }
};
