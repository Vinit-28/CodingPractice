

// Question Link :: "https://leetcode.com/problems/set-matrix-zeroes/"


// Solution //

class Solution {
public:
    
    void fill(int &r, int &c, int i, int j, vector<vector<int>>& mat){
        
        for(int k=0;k<c;k++) mat[i][k] = 0;
        for(int k=0;k<r;k++) mat[k][j] = 0;
    }
    
    void setZeroes(vector<vector<int>>& mat) {
        
        int r=mat.size(), c=mat[0].size();
        map<pair<int,int>, bool> hash;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if( mat[i][j] == 0 ) hash[{i,j}] = true;
            }
        }
        
        for(auto &p : hash)
            fill(r, c, p.first.first, p.first.second, mat);
    }
};