

// Question Link :: "https://leetcode.com/problems/rotting-oranges/"


// Solution //

class Solution {
public:
    
    int m,n;
    int x[4] = {0,0,1,-1}, y[4] = {-1,1,0,0};
    
    bool isValid(int &i, int &j){
        return !(i<0 || i>=m || j<0 || j>=n);
    }

    int BFS(vector<vector<int>> &grid, queue<pair<int,int>> &q, int &rotten){
        
        int curr=rotten, counter=0, next=0, minutes=0;
        while(q.empty()==false){
            
            auto p = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                
                int nx = x[i] + p.first, ny = y[i] + p.second;
                if( isValid(nx, ny) && grid[nx][ny] == 1 ){
                    q.push({nx, ny}), grid[nx][ny] = 2, rotten++,next++;
                }
            }
            counter++;
            if( counter==curr ) curr = next, next=0, counter = 0, minutes++;
        }
        return (minutes==0)? 0 : minutes-1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        m=grid.size(), n=grid[0].size();
        int oranges = 0, rotten = 0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( grid[i][j] != 0 ) oranges++;
                if( grid[i][j] == 2 ) q.push({i, j}), rotten++;
            }
        }
        int minutes = BFS(grid, q, rotten);
        return (oranges==rotten)? minutes : -1;
    }
};