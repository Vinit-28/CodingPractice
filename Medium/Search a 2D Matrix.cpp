

// Question Link :: "https://leetcode.com/problems/search-a-2d-matrix/"


// Solution //

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int rows=mat.size(), cols = mat[0].size(), l=0, u=(rows*cols)-1, m=(l+u)/2;
        
        // Applying Binary Serach //
        while(l<=u){
            
            int i=(m/cols), j=(m%cols);
            
            if( mat[i][j] == target ) return true;
            else if( mat[i][j] > target ) u=m-1;
            else l=m+1;
            
            m = (l+u)/2;
        }
        return false;
    }
};