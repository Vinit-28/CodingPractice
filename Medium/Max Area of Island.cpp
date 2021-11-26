

// Question Link :: "https://leetcode.com/problems/max-area-of-island/"


// Solution //

class Solution {
public:
    
    int r, c;
    
    bool isValid(int &x, int &y){
        return !(x<0 || x>=r || y<0 || y>=c);
    }
    
    int doBFS(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int &i, int &j){
        
        int x[4] = {1, -1, 0, 0}, y[4] = {0, 0, 1, -1}, counter=0;
        
        queue<pair<int, int>> q;
        q.push({i, j});
        isVisited[i][j] = true;
        
        while(q.empty()==false){
            
            auto p = q.front();
            q.pop();
            
            for(int index=0;index<4;index++){
                int newX = x[index]+p.first, newY = y[index]+p.second;
                if( isValid(newX, newY) && grid[newX][newY] == 1 && isVisited[newX][newY]==false ) q.push({newX, newY}), isVisited[newX][newY]=true;
            }
            counter++;
        }
        return counter;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans=0;
        r=grid.size(), c=grid[0].size();
        vector<vector<bool>> isVisited(r, vector<bool>(c, false));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if( grid[i][j] && !isVisited[i][j] )
                    ans = max(doBFS(grid, isVisited, i, j), ans);
            }
        }
        return ans;
    }
};