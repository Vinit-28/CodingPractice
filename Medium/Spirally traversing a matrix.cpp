

// Question Link :: "https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1"



// Solution //

class Solution
{   
    public: 
    vector<vector<int>> mat;
    vector<int> path;
    int path_len=0;
    //Function to return a list of integers denoting spiral traversal of matrix.
    
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        mat=matrix;
        path={};
        int rounds, rounds_limit, prev_len = 0;
        
        rounds_limit = (r%2==0)? (r/2) : ((r/2)+1);
        
        for(rounds=0; rounds<rounds_limit; rounds++){
            
            move_horizontal( rounds, rounds, 'r', (c-rounds) );

            if( path_len == prev_len )
                break;
            else
                prev_len = path_len;

            move_vertical( (rounds+1), (c-rounds)-1, 'd', (r-rounds) );

            if( path_len == prev_len )
                break;
            else
                prev_len = path_len;
            
            move_horizontal( (r-rounds)-1, (c-rounds)-2, 'l', (rounds-1) );

            if( path_len == prev_len )
                break;
            else
                prev_len = path_len;
        
            move_vertical( (r-rounds)-2, rounds, 'u', rounds );

            if( path_len == prev_len )
                break;
            else
                prev_len = path_len;
            
        }
        return path;
    }
    
    
    void move_horizontal( int row, int col, char direction, int col_limit ){
        
        while(true){
            
            if( col_limit == col )
                break;
                
            path.push_back(mat[row][col]);
            col = ( direction == 'r' )? (col+1) : (col-1);
            path_len+=1;
        }
    }
    
    
    void move_vertical( int row, int col, char direction, int row_limit ){
        
        while(true){
            
            if( row_limit == row )
                break;
                
            path.push_back(mat[row][col]);
            row = ( direction == 'u' )? (row-1) : (row+1);
            path_len+=1;
        }
    }
};

