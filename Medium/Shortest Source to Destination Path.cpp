

// Question Link :: "https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1"


// Solution //

class Solution {
    public:
    
    void bfs(int &n, int &m, vector<vector<int>> &mat, vector<vector<int>> &dist, pair<int,int> destination){
        
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> is_visited;
        pair<int,int> temp;
        
        q.push({0,0});
        is_visited[{0,0}] = true;
        
        while(q.empty()==false){
            
            temp = q.front();
            int x = temp.first, y = temp.second;
            q.pop();
            
            
            // Moving Downwards //
            if( x + 1 < n && mat[x+1][y] == 1 && is_visited[{x+1,y}] == false ){
                
                temp = {x+1,y};
                q.push(temp);
                dist[x+1][y] = dist[x][y]+1;
                is_visited[temp] = true;
                
                if( destination ==  temp )
                    return;
            }
            
            // Moving Upwards //
            if( x - 1 >= 0 && mat[x-1][y] == 1 && is_visited[{x-1,y}] == false ){
                
                temp = {x-1,y};
                q.push(temp);
                dist[x-1][y] = dist[x][y]+1;
                is_visited[temp] = true;
                
                if( destination ==  temp )
                    return;
            }
            
            // Moving Rightwards //
            if( y + 1 < m && mat[x][y+1] == 1 && is_visited[{x,y+1}] == false ){
                
                temp = {x,y+1};
                q.push(temp);
                dist[x][y+1] = dist[x][y]+1;
                is_visited[temp] = true;
                
                if( destination ==  temp )
                    return;
            }
            
            // Moving Leftwards //
            if( y - 1 >= 0 && mat[x][y-1] == 1 && is_visited[{x,y-1}] == false ){
               
                temp = {x,y-1};
                q.push(temp);
                dist[x][y-1] = dist[x][y]+1;
                is_visited[temp] = true;
                
                if( destination ==  temp )
                    return;
            }
        }
    }
    
    
    int shortestDistance(int N, int M, vector<vector<int>> mat, int X, int Y) {
       
        // code here
        vector<vector<int>> dist;
        for(int i=0;i<N;i++)
            dist.push_back(vector<int>(M,-1));
        
        if( mat[0][0] == 0)
            return -1;
        
        dist[0][0]=0;
        bfs(N, M, mat, dist, {X,Y});
        
        return dist[X][Y];
    }
    
    
};
