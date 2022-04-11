

// Question Link :: "https://leetcode.com/problems/shift-2d-grid/"


// Solution //

class Solution {
public:
    
    void calculateIndexes(int &i, int &j, int &m, int &n, int k){
        
        while( (j+k) >= n ){
            
            k -= (n-j);
            j = 0, i = (++i % m);
        }
        
        j += k;
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        if( k == 0 ) return grid;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> newMat(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                int x = i, y = j;
                calculateIndexes(x, y, m, n, k);
                newMat[x][y] = grid[i][j];
            }
        }
        return newMat;
    }
};