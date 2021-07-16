

// Question Link :: "https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#"


// Solution //

class Solution 
{
    public:
    
    int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
    int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
    
    bool isValid(pair<int, int> pos, int n){
        
        if( pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n)
            return false;
        return true;
    }
    
    int BFS(vector<int> &target,vector<int> &start, int &n){
        
        queue<pair<int,int>> q;
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        vector<vector<int>> dist(n, vector<int>(n,0));
        
        q.push({start[0]-1, start[1]-1});
        
        dist[start[0]-1][start[1]-1] = 0;
        
        isVisited[start[0]-1][start[1]-1] = true;
        
        while(q.empty() == false){
            
            auto p = q.front();
            q.pop();
            
            for(int i=0; i<8; i++){
                
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                
                if( isValid({x,y}, n) && isVisited[x][y] == false  ){
                    
                    dist[x][y] = 1 + dist[p.first][p.second];
                    q.push({x,y});
                    isVisited[x][y] = true;
                }
                if( (x+1) == target[0] && (y+1) == target[1] )
                    return dist[x][y];
            }
        }
        return 0;
    }
    
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int> &KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    return BFS(TargetPos, KnightPos , n);
	}
};
