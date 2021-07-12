

// Question Link :: "https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1"


// Solution //

class Solution{
public:
    vector<vector<int>> answer;
    
    vector<vector<int>> nQueen(int n) {
        // code here
        answer.clear();
        vector<int> positions;
        recursion(0, positions, n);
        return answer;
    }
    
    
    bool isPositionValid(pair<int,int> currPos, vector<int> &positions){
        
        for(int i=0; i<positions.size(); i++)
            if( i == currPos.first || positions[i] == currPos.second || abs( i-currPos.first ) == abs(positions[i]-currPos.second) )
                return false;
        return true;
    }
    
    void recursion(int r, vector<int> &positions, int &n){
        
        if( r >= n ){
            
            answer.push_back(positions);
            return;
        }
        
        for(int c=0; c<n; c++)
            if( isPositionValid({r,c+1}, positions) ){
                
                positions.push_back(c+1);
                recursion(r+1, positions, n);
                positions.pop_back();
            }
    }
};
