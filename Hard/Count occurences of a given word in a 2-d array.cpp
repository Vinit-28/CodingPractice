

//   Question Link :: "https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1"




// Solution //


class Solution{
    
    public:
    
    string target;
    bool is_match;
    vector<vector<char>> matrix;
    int t_len,r,c,ways=0;
    int findOccurrence(vector<vector<char> > &mat, string str){
        
        ways=0;
        target = str;
        matrix=mat;
        t_len = target.length();
        r=mat.size(), c= mat[0].size();
        
        // vector<pair> path ;
        
        for(int i=0;i<r;i++){
            
        
            for(int j=0;j<c;j++){
                
                if(mat[i][j] == target[0]){
                    
                    // path = {{i,j}};
                    
                    check(i,j,1, {{i,j}} );
                    // cout<<ways<<endl;
                }
                
            }
            
        }
        
        return ways;
        
    }
    
    
    void check(int mat_i, int mat_j, int string_i, vector<pair<int ,int>> path ){
        
        
        if(string_i == t_len){
            
            ways+=1;
            return;
            
        }
        
        if( (mat_i+1) < r && (is_already_visited(path,{mat_i+1,mat_j}) == false) && target[string_i] == matrix[mat_i+1][mat_j] ){
            
            path.push_back({mat_i+1,mat_j});
            check(mat_i+1, mat_j, string_i+1,path);
            path.pop_back();
            
        }
        
        if( (mat_i-1) >=0  && (is_already_visited(path,{mat_i-1,mat_j}) == false) && target[string_i] == matrix[mat_i-1][mat_j] ){
            
            path.push_back({mat_i-1,mat_j});
            check(mat_i-1, mat_j, string_i+1,path);
            path.pop_back();
            
        }
        
        
        if( (mat_j+1) <c  && (is_already_visited(path,{mat_i,mat_j+1}) == false) && target[string_i] == matrix[mat_i][mat_j+1] ){
            
            path.push_back({mat_i,mat_j+1});
            check(mat_i, mat_j+1, string_i+1,path);
            path.pop_back();
            
        }
        
        
        if( (mat_j-1) >=0  && (is_already_visited(path,{mat_i,mat_j-1}) == false) && target[string_i] == matrix[mat_i][mat_j-1] ){
            
            path.push_back({mat_i,mat_j-1});
            check(mat_i, mat_j-1, string_i+1,path);
            path.pop_back();
            
        }
        
        
    }
    
    
    bool is_already_visited(vector<pair<int , int>> path, pair<int,int> coordinate){
        
        
        for(int i=0;i<path.size();i++){
            
            if(path[i] == coordinate)
                return true;
        }
        return false;
        
    }
    
    
    
};