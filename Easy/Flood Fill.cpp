

// Question Link :: "https://leetcode.com/problems/flood-fill/"


// Solution //

class Solution {
public:
    
    bool isValid(int &x, int &y, int &r, int &c){
        return !(x<0 || x>=r || y<0 || y>=c);
    }
    
    void doBFS(vector<vector<int>>& image, int &i, int &j, int &newColor){
        
        int x[4] = {1, -1, 0, 0}, y[4] = {0, 0, 1, -1}, r=image.size(), c=image[0].size();
        
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while(q.empty()==false){
            
            auto p = q.front();
            q.pop();
            
            for(int index=0;index<4;index++){
                int newX = x[index]+p.first, newY = y[index]+p.second;
                if( isValid(newX, newY, r, c) && image[newX][newY] == image[p.first][p.second] && image[p.first][p.second]!=newColor ) q.push({newX, newY});
            }
            image[p.first][p.second]=newColor;
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        doBFS(image, sr, sc, newColor);
        return image;
    }
};