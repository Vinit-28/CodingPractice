

// Question Link :: "https://leetcode.com/problems/jump-game-iii/"


// Solution //

class Solution {
public:
    
    bool isValid(int &pos, int &n){
        return !(pos >=n || pos<0);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        queue<int> q;
        int n=arr.size(), isVisited[n], forward, backward;
        memset(isVisited, 0, sizeof(isVisited));
        
        q.push(start);
        isVisited[start] = 1;
        
        while(q.empty()==false){
            
            auto index = q.front();
            q.pop();
            
            if( !arr[index] ) return true;
                
                
            forward = arr[index] + index, backward = index - arr[index];
            if( isValid(forward, n) && isVisited[forward] == 0 ){
                q.push(forward);
                isVisited[forward] = 1;
            } 
            if( isValid(backward, n) && isVisited[backward] == 0 ){
                q.push(backward);
                isVisited[backward] = 1;
            }
        }
        
        return false;
    }
};