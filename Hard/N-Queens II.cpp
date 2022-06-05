

// Question Link :: "https://leetcode.com/problems/n-queens-ii/"


// Solution //

class Solution {
public:
    int totalNQueens(int n) {
        
        vector<pair<int, int>> pos;
        int ans = 0;
        DFS(pos, 0, n, ans);
        return ans;
    }
    
    void DFS(vector<pair<int, int>> &pos, int row, int &n, int &ans){
        
        if( row >= n ){
            ans += 1;
            return;
        }
        
        for(int j=0;j<n;j++){
            
            if( isPossibleToPlaceQueen(row, j, pos) ){
                
                pos.push_back({row,j});
                DFS(pos, row+1, n, ans);
                pos.pop_back();
            }
        }
    }
    
    bool isPossibleToPlaceQueen(int &i, int &j, vector<pair<int, int>> &pos){
        
        for(auto &p : pos){
            
            if( p.first == i || p.second == j || abs(p.first - i) == abs(p.second-j) ) return false;
        }
        return true;
    }
};