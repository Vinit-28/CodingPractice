

// Question Link :: "https://practice.geeksforgeeks.org/problems/make-zeroes4042/1#"


// Solution //

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dupmat(n, vector<int>(m, -1));
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                
                if( matrix[i][j] == 0 ){
                    int sum=0;
                    
                    ((i+1)<n)? (sum += matrix[i+1][j], dupmat[i+1][j] = 0) : 0;
                    
                    ((i-1)>=0)? (sum += matrix[i-1][j], dupmat[i-1][j] = 0) : 0;
                    
                    ((j+1)<m)? (sum += matrix[i][j+1], dupmat[i][j+1] = 0) : 0;
                    
                    ((j-1)>=0)? (sum += matrix[i][j-1], dupmat[i][j-1] = 0) : 0;
                    
                    dupmat[i][j] = sum;
                }
                else
                    dupmat[i][j] = (dupmat[i][j] != -1)? dupmat[i][j] : matrix[i][j];
            }
        }
        
        matrix=dupmat;
    }
};