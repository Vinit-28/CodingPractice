

// Question Link :: "https://leetcode.com/problems/path-with-minimum-effort/"


// Solution //

class Solution {
public:
    
    
    bool isValidIndexes(int &i, int &j, int &r, int &c){
        return !(i<0 || j<0 || i>=r || j>=c);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int r = heights.size(), c = heights[0].size();
        int hashTable[r][c];
        int rDir[4] = {1, -1, 0, 0};
        int cDir[4] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++) 
                hashTable[i][j] = INT_MAX;
        
        
        hashTable[0][0] = 0;
        q.push({0,0});
        
        while(q.empty() == false){
            
            auto p = q.front();
            int currX = p.first, currY = p.second;
            q.pop();

            for(int i=0;i<4;i++){
                
                int x = rDir[i]+currX, y = cDir[i]+currY;
                if( isValidIndexes(x, y, r, c) ){
                    
                    int newValue = max(hashTable[currX][currY], abs(heights[currX][currY] - heights[x][y]));
                    if( newValue < hashTable[x][y] ){
                        q.push({x, y});
                        hashTable[x][y] = newValue;
                    }
                }
            }
        }
        
        return hashTable[r-1][c-1];
    }
};