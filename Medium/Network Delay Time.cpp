

// Question Link :: "https://leetcode.com/problems/network-delay-time/"



// Solution //

class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int totalTimeTaken[n+1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int ans = INT_MIN;
        
        for(int i=1;i<=n;i++) totalTimeTaken[i] = INT_MAX;
        
        minHeap.push({0, k});
        while( minHeap.empty() == false ){
            
            auto node = minHeap.top();
            minHeap.pop();
            
            while( minHeap.empty() == false && totalTimeTaken[node.second] != INT_MAX ){
                node = minHeap.top();
                minHeap.pop();
            }
            
            if( totalTimeTaken[node.second] != INT_MAX )
                break;
            
            totalTimeTaken[node.second] = node.first;
            
            for(auto &nb : times){
                
                if( nb[0] == node.second && totalTimeTaken[nb[1]] == INT_MAX ){
                    minHeap.push({ (nb[2] + node.first), nb[1]});
                }
            }
        }
        
        for(int i=1;i<=n;i++) ans = max(ans, totalTimeTaken[i]);

        return (ans == INT_MAX)? -1 : ans;
    }
};


