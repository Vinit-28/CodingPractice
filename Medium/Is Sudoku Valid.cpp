

// Question Link :: "https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1"


// Solution //

class Solution{
public:

    
    bool isNumberValid(int x, int y, int num, vector<vector<int>> &mat){
        
        for(int i=0;i<9;i++)
            if( (i!=x && mat[i][y] == num) || (i!=y && mat[x][i] == num) )
                return false;
        
        int row = (x/3)*3, col = (y/3)*3;
        
        for(int i=0;i<3;i++){
            
            for(int j=0;j<3;j++){
                
                if( ((i+row)!=x && (j+col)!=y ) && mat[row+i][col+j] != 0 && mat[row+i][col+j] == num )
                    return false;
            }
        }
        return true;
    }
    
    int isValid(vector<vector<int>> mat){
        // code here
        for(int i=0;i<9;i++){
            
            for(int j=0;j<9;j++){
                
                if( mat[i][j] != 0 && isNumberValid(i, j, mat[i][j], mat)==false )
                    return 0;
            }
        }
        
        return 1;
    }
};