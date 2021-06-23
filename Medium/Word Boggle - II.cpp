

// Question Link :: "https://practice.geeksforgeeks.org/problems/72cf44eabd18006810efad06fbb623a0682acee2/1#"


// Solution //

class Solution{
    
    public:

        vector<vector<char>> mat;
        int m,n;
    	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
    	    // Code here
    	    
    	    mat = board;
    	    m = board.size();
    	    n = board[0].size();
    	    int i, j, dict_index;
    	    vector<string> matched_words;
    	    
    	    for(dict_index=0; dict_index<dictionary.size(); dict_index++){

                if( is_word_already_exists(matched_words,dictionary[dict_index]) )
                    continue;
    	        for(i=0;i<m;i++){
    	        
        	        for(j=0;j<n;j++){
        	            
        	            if( dictionary[dict_index][0] == board[i][j] ){
    	                    
        	                string temp = "";
        	                temp += board[i][j];
        	                
        	                if( is_possible(i, j, 1, temp, dictionary[dict_index], {{i,j}}) ){
        	                        
        	                    matched_words.push_back(dictionary[dict_index]);
        	                    
        	                    goto if_matched_come_here;
        	                }
        	                    
        	            }
        	        }
        	    }
        	    
        	    if_matched_come_here:{}
    	    }
    	    
    	    return matched_words;
    	}
    	
    	
    	bool is_word_already_exists(vector<string> &Words, string &word){
    	    
    	    for(int i=0;i<Words.size();i++){
    	        if(word==Words[i])
    	            return true;
    	    }
    	    return false;
    	}
    	
    	bool is_possible(int row, int col, int target_index, string till, string &target, vector<pair<int, int>> path){
    	    
    	    
    	    if( till == target ){
    	        return true;
    	    }
    	    
    	    
    	    // Checking Horizontally and Vertically //
    	    {
        	    // Moving Down Side //
        	    if( (row+1) < m && mat[row+1][col] == target[target_index] && is_same_step({row+1,col},path)==false ){
        	        
        	        path.push_back({row+1,col});
        	        
        	        if(is_possible(row+1, col, target_index+1, (till+target[target_index]), target, path ))
        	            return true;
        	        
        	        path.pop_back();
        	    }
        	    
        	    
        	    // Moving Up Side //
        	    if( (row-1) >= 0 && mat[row-1][col] == target[target_index] && is_same_step({row-1,col},path)==false ){
        	        
        	        path.push_back({row-1,col});
        	        
        	        if(is_possible(row-1, col, target_index+1, (till+target[target_index]), target, path ))
        	            return true;
        	        
        	        path.pop_back();
        	    }
        	    
        	    
        	    // Moving Right Side //
        	    if( (col+1) < n && mat[row][col+1] == target[target_index] && is_same_step({row,col+1},path)==false ){
        	        
        	        path.push_back({row,col+1});
        	        
        	        if(is_possible(row, col+1, target_index+1, (till+target[target_index]), target, path ))
        	            return true;
        	        
        	        path.pop_back();
        	    }
        	    
        	    
        	    // Moving Up Side //
        	    if( (col-1) >= 0 && mat[row][col-1] == target[target_index] && is_same_step({row,col-1},path)==false ){
        	        
        	        path.push_back({row,col-1});
        	        
        	        if(is_possible(row, col-1, target_index+1, (till+target[target_index]), target, path ))
        	            return true;
        	        
        	        path.pop_back();
        	    }
    	    }
    	    
    	    
    	    
    	    
    	    // Checking Diagonally //
    	    {
        	    // Moving Down Side along diagonal in right side //
        	    if( (row+1) < m && (col+1) < n && mat[row+1][col+1] == target[target_index] && is_same_step({row+1,col+1},path)==false ){
        	        
        	        path.push_back({row+1,col+1});
        	        
        	        if(is_possible(row+1, col+1, target_index+1, (till+target[target_index]), target, path ))
        	            return true;
        	        
        	        path.pop_back();
        	    }
        	    
        	    
        	    // Moving Up Side along diagonal in left side  //
        	    if( (row-1) >= 0 && (col-1) >= 0 && mat[row-1][col-1] == target[target_index] && is_same_step({row-1,col-1},path)==false ){
        	        
        	        path.push_back({row-1,col-1});
        	        
        	        if(is_possible(row-1, col-1, target_index+1, (till+target[target_index]), target, path ))
        	            return true;
        	        
        	        path.pop_back();
        	    }
        	    
        	    
        	    // Moving Up Side along diagonal in right side //
        	    if( (row-1) >= 0 && (col+1) < n && mat[row-1][col+1] == target[target_index] && is_same_step({row-1,col+1},path)==false ){
        	        
        	        path.push_back({row-1,col+1});
        	        
        	        if(is_possible(row-1, col+1, target_index+1, (till+target[target_index]), target, path ))
        	            return true;
        	        
        	        path.pop_back();
        	    }
        	    
        	    
        	    // Moving Down Side along diagonal in left side //
        	    if( (row+1) < m && (col-1) >= 0 && mat[row+1][col-1] == target[target_index] && is_same_step({row+1,col-1},path)==false ){
        	        
        	        path.push_back({row+1,col-1});
        	        
        	        if(is_possible(row+1, col-1, target_index+1, (till+target[target_index]), target, path ))
        	            return true;
        	        
        	        path.pop_back();
        	    }
    	    }
    	    
    	    return false;
    	}
    	
    	
    	bool is_same_step(pair<int, int> step, vector<pair<int, int>> &path){
    	    
    	    for(int i=0;i<path.size();i++){
    	        if(step==path[i])
    	            return true;
    	    }
    	    return false;
    	}
};