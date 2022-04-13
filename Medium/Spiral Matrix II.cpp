

// Question Link :: "https://leetcode.com/problems/spiral-matrix-ii/"


// Solution //

class Solution {
public:
    
    
    void moveVertical(int currRow, int currCol, int limit, int &val, int increment, vector<vector<int>> &mat){
        
        while( (increment==-1 && currRow > limit) || (increment==1 && currRow < limit) ){
            
            mat[currRow][currCol] = val;
            val += 1;
            currRow += increment;
        }
    }
    
    void moveHorizontal(int currRow, int currCol, int limit, int &val, int increment, vector<vector<int>> &mat){
        
        while( (increment==-1 && currCol > limit) || (increment==1 && currCol < limit) ){
            
            mat[currRow][currCol] = val;
            val += 1;
            currCol += increment;
        }
    }
    
    
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        int currRow = 0, currCol = 0, val = 1;
        int rowL = 0, rowUP = n, colL = 0, colUP = n;
        
        while( (rowL <= rowUP) && (colL <= colUP) ){
            
            moveHorizontal(rowL, colL, colUP, val, 1, mat);
            moveVertical(rowL+1, colUP-1, rowUP, val, 1, mat);
            moveHorizontal(rowUP-1, colUP-2, colL-1, val, -1, mat);
            moveVertical(rowUP-2, colL, rowL, val, -1, mat);
            
            rowL += 1, colL += 1, rowUP -= 1, colUP -= 1;
        }
        return mat;
    }
};