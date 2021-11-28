

// Question Link :: "https://leetcode.com/problems/01-matrix/"


// Solution //

class Solution {
public:
    int m,n;
    int x[4] = {0,0,1,-1}, y[4] = {-1,1,0,0};
    
    bool isValid(int &i, int &j){
        return !(i<0 || i>=m || j<0 || j>=n);
    }
    
    int DFS(vector<vector<int>>& mat, vector<vector<int>>& dist, vector<vector<int>>& isVisited, int &i, int &j){
        
        if( mat[i][j] == 0)
            return dist[i][j]+1;
        
        else if( dist[i][j] != INT_MAX ){
            
            for(int k=0;k<4;k++){
                int nx = i + x[k], ny = j + y[k];
                if( isValid(nx, ny) &&  dist[nx][ny] != INT_MAX )
                    dist[i][j] = min(dist[i][j], dist[nx][ny]+1); 
            }
            return dist[i][j]+1;
        }
        
        isVisited[i][j] = 1;
        for(int k=0;k<4;k++){
            int nx = i + x[k], ny = j + y[k];
            if( isValid(nx, ny) && isVisited[nx][ny] == 0 )
                dist[i][j] = min(dist[i][j], DFS(mat, dist, isVisited, nx, ny)); 
        }
        isVisited[i][j] = 0;
        return (dist[i][j] == INT_MAX)? dist[i][j] : dist[i][j]+1;
    }
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        m= mat.size(), n=mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n)), isVisited(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = (mat[i][j] == 0)? 0 : INT_MAX;
        
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if( mat[i][j] == 1 )
                    DFS(mat, dist, isVisited, i, j);
      
        return dist;
    }
};
