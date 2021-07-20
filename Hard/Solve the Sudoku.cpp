

// Question Link :: "https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1#"



// Solution //

class Solution 
{
    public:
    
    bool isNumberValid(int x, int y, int num, int mat[N][N]){
        
        for(int i=0;i<N;i++)
            if( mat[i][y] == num || mat[x][i] == num )
                return false;
        
        int row = (x/3)*3, col = (y/3)*3;
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(mat[row+i][col+j] == num)
                    return false;
        
        return true;
    }
    
    bool solveProblem(int grid[N][N], int i, int j){
        
        for(;i<N;i++,j=0){
            
            for(;j<N;j++){
                
                if( grid[i][j] == 0 ){
                    
                    for(int num=1;num<=9;num++){
                        
                        if( isNumberValid(i, j, num, grid) ){
                            
                            grid[i][j] = num;
                            if( solveProblem(grid, i, j) )
                                return true;
                            else
                                grid[i][j] = 0;
                        }
                    }
                }
                if( grid[i][j]==0 )
                    return false;
            }
        }
        return true;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solveProblem(grid, 0, 0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<grid[i][j]<<" ";
        }
    }
};