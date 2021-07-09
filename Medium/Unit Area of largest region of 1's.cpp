

// Question Link :: "https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1"


// Solution //

class Solution
{
    public:
    
    int dx[8] = {1,-1,0,0,1,-1,1,-1};
    int dy[8] = {0,0,1,-1,1,-1,-1,1};


    bool inRange(int x, int y, int r, int c){

        if( x<0 || y<0 || x>=r || y>=c )
            return false;
        
        return true;
    }
    

    void bfs(vector<vector<bool>> &isVisited, vector<vector<int>> &grid, pair<int,int> node, int &maxAns, int &r, int &c){
        
        queue<pair<int,int>> q;
        
        q.push(node);
        
        int counter = 1;
        maxAns = max(maxAns, counter);
        
        while(q.empty()==false){
            
            auto n = q.front();
            q.pop();
            
            isVisited[n.first][n.second] = true;
            
            for(int i=0;i<8;i++){
                
                int x = dx[i] + n.first;
                int y = dy[i] + n.second;
                
                if( inRange(x,y, r, c) == false )
                    continue;

                if( isVisited[x][y]==false && grid[x][y] == 1 ){
                    
                    counter+=1;
                    q.push({x,y});
                    maxAns = max(maxAns, counter);
                    isVisited[x][y] = true;
                }
                    
            }
        }
    }
    
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        
        int r = grid.size(), c = grid[r-1].size(), maxAns = INT_MIN;
        
        vector<vector<bool>> isVisited(r, vector<bool>(c,false));
        
        // cout<<"working\n";
        for(int i=0;i<r;i++){
            
            for(int j=0;j<c;j++){
                
                if( isVisited[i][j] == false && grid[i][j] == 1 )
                    bfs(isVisited, grid, {i,j}, maxAns, r, c);
                
            }
            
        }
        
        return maxAns;
    }
};