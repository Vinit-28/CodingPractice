

// Question Link :: "https://leetcode.com/problems/critical-connections-in-a-network/"



// Solution //

class Solution {
public:
    
    vector<vector<int>> ans;
    
    int DFS(vector<int> graph[], int &node, int disc[], int low[], int time, int &parent){
        
        if( low[node] != INT_MAX ) return low[node];
        
        disc[node] = low[node] = time;
        
        for(auto &nb : graph[node]){
            
            if( parent != nb ){
                int l = DFS(graph, nb, disc, low, time+1, node);
                low[node] = min(low[node], l);
                if( disc[node] < l ) ans.push_back({node, nb});
            }
        }
        return low[node];
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        ans.clear();
        vector<int> graph[n];
        int disc[n], low[n];
        int startNode = 0, parent=-1;
        
        for(int i=0;i<n;i++) low[i] = INT_MAX;
        
        for(auto &cn : connections){
            graph[cn[0]].push_back(cn[1]);
            graph[cn[1]].push_back(cn[0]);
        }
        DFS(graph, startNode, disc, low, 0, parent);
        return ans;
    }
};