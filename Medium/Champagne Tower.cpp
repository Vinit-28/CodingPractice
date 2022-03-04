

// Question Link :: "https://leetcode.com/problems/champagne-tower/"


// Solution //

class Solution {
public:
    
    double mat[101][101];
    
    double champagneTower(int poured, int query_row, int query_glass) {
        
        memset(mat, 0, sizeof(mat));
        mat[0][0] = poured;
        
        for(int i=0;i<=query_row;i++){
            
            for(int j=0;j<=i;j++){
                
                if( mat[i][j] > 1 ){
                    
                    double left = mat[i][j]-1;
                    mat[i][j] = 1, mat[i+1][j] += (left/2), mat[i+1][j+1] += (left/2);
                }
            }
        }
        return mat[query_row][query_glass];
    }
    
};