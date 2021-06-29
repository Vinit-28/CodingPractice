

// Question Link :: "https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1"


// Solution //

class Solution{
    public:
        
        vector<string> Paths;
        vector<string> findPath(vector<vector<int>> &m, int n) {
            // Your code goes here
            
            Paths.clear();
            
            if( m[0][0] )
                find_path(m, n, "", 0, 0, { {0,0} });
            
            sort(Paths.begin(), Paths.end());
            return Paths;
        }
        
        void find_path(vector<vector<int>> &mat, int &n, string curr_path, int row, int col, vector<pair<int,int>> curr_path_positions){
            
            if( row == n-1 && col == n-1 ){
                
                Paths.push_back(curr_path);
                return;
            }
            
            
            // Moving Downwards //
            if( row+1 < n && mat[row+1][col] == 1 && is_step_already_taken(curr_path_positions,{row+1,col}) == false ){
            
                curr_path_positions.push_back({row+1,col});
                find_path(mat, n, curr_path+"D", row+1, col, curr_path_positions);
                curr_path_positions.pop_back();
                
            }
            
            
            // Moving Upwards //
            if( row-1 >= 0 && mat[row-1][col] == 1 && is_step_already_taken(curr_path_positions,{row-1,col}) == false ){
            
                curr_path_positions.push_back({row-1,col});
                find_path(mat, n, curr_path+"U", row-1, col, curr_path_positions);
                curr_path_positions.pop_back();
                
            }
            
            
            // Moving Rightwards //
            if( col+1 < n && mat[row][col+1] == 1 && is_step_already_taken(curr_path_positions,{row,col+1}) == false ){
            
                curr_path_positions.push_back({row,col+1});
                find_path(mat, n, curr_path+"R", row, col+1, curr_path_positions);
                curr_path_positions.pop_back();
                
            }
            
            
            // Moving Leftwards //
            if( col-1 >= 0 && mat[row][col-1] == 1 && is_step_already_taken(curr_path_positions,{row,col-1}) == false ){
            
                curr_path_positions.push_back({row,col-1});
                find_path(mat, n, curr_path+"L", row, col-1, curr_path_positions);
                curr_path_positions.pop_back();
                
            }
            
            
        }
        
        
        bool is_step_already_taken(vector<pair<int,int>> curr_path, pair<int,int> pos){
            
            for(auto p : curr_path){
                if(p == pos)
                    return true;
            }
            return false;
        }
};
