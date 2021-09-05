

// Question Link :: "https://leetcode.com/problems/sum-of-distances-in-tree/"


// Solution //

class Solution {
public:
    
    
    int countNodes(vector<int> adjList[], int totalNodes[], int isVisited[], int node, vector<int> &ans, int dist){
        
        int nodes = 1;
        ans[0] += dist, isVisited[node] = 1;
        
        for(auto n : adjList[node])
            if( !isVisited[n] )
                nodes += countNodes(adjList, totalNodes, isVisited, n, ans, dist+1);
        
        totalNodes[node] = nodes;
        return nodes;
    }
    
    
    
    void DFS(vector<int> adjList[], int totalNodes[], int isVisited[], int parent, int node, vector<int> &ans){
        
        if( parent!=-1 ){
            
            int currAns = ans[parent] + totalNodes[parent]; // its parent dist + extra dist of 1 for every node //
            currAns -= 2; // deducting self dist //
            currAns -= ((totalNodes[node]-1)*2); // deducting its child nodes dist //
            ans[node] = currAns, totalNodes[node] = totalNodes[parent];
        }
        
        isVisited[node]=1;
        for(auto n : adjList[node])
            if( !isVisited[n] )
                DFS(adjList, totalNodes, isVisited, node, n, ans);
    }
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> ans(n, 0), adjList[n];
        int totalNodes[n], isVisited[n];
        
        for(auto v : edges)
            adjList[v[0]].push_back(v[1]), adjList[v[1]].push_back(v[0]);
        
        
        memset(isVisited, 0, sizeof(isVisited));
        countNodes(adjList, totalNodes, isVisited, 0, ans, 0);
        
        memset(isVisited, 0, sizeof(isVisited));
        DFS(adjList, totalNodes, isVisited, -1, 0, ans);
        
        return ans;
    }
};