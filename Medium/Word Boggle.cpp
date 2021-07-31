

// Qestion Link :: "https://practice.geeksforgeeks.org/problems/word-boggle4143/1"


// Solution //

class Solution{
public:
    
    int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    
    
    bool isValid(pair<int,int> pos, int &M, int &N){
        
        if( pos.first < 0 || pos.first >= M || pos.second < 0 || pos.second >= N )
            return false;
        return true;
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    int M = board.size(), N = board[0].size();
	    
	    vector<vector<bool>> visited(M, vector<bool>(N, false));
	    vector<string> res;
	    
	    for(auto s : dictionary){
	        
	        for(int i=0;i<M;i++){
	            for(int j=0;j<N;j++){
	                
	                if( board[i][j] == s[0] ){
	                    visited[i][j] = true;
	                    if( DFS(board, s, i, j, 1, M, N, visited) ){
	                        res.push_back(s);
	                        visited[i][j] = false;
	                        goto breakLoop;
	                    }
	                    visited[i][j] = false;
	                }
	            }
	        }
	        breakLoop:{}
	    }
	    return res;
	}
	
	
	bool DFS(vector<vector<char>> &board, string &Word, int i, int j, int wIndex, int &M, int &N, vector<vector<bool>> &visited){
	    
	    if( wIndex >= Word.length() )
	        return true;
	       
	    for(int dir=0;dir<8;dir++){
	        
	        int x = dx[dir]+i;
	        int y = dy[dir]+j;
	        
	        if( isValid({x,y}, M, N) && visited[x][y] == false && board[x][y] == Word[wIndex] ){
	            
	            visited[x][y] = true;
	            if( DFS(board, Word, x, y, wIndex+1, M, N, visited) ){
	                visited[x][y]=false;
	                return true;
	            }
	            
	            visited[x][y]=false;
	        }
	    }
	    
	    return false;
	}
};
