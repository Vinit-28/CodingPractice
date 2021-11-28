

// Question Link :: "https://leetcode.com/problems/all-paths-from-source-to-target/"


// Solution //

class Solution {
public:
    vector<vector<int>> paths;
    int target;
    
    void DFS(vector<vector<int>>& graph, int currNode, vector<int> &path, vector<bool> &isVisited){
        
        if( currNode == target ){
            paths.push_back(path);
            return;
        }
        isVisited[currNode] = true;
        for(auto cn : graph[currNode]){
            if( isVisited[cn]==false ){
                path.push_back(cn);
                DFS(graph, cn, path, isVisited);
                path.pop_back();
            }
        }
        isVisited[currNode] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> path = {0};
        vector<bool> isVisited(n, false);
        paths.clear(), target = n-1;
        DFS(graph, 0, path, isVisited);
        return paths;
    }
};