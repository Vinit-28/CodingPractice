

// Question Link :: "https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1"


// Solution //

class Solution{
  public:
  
    // Function to detect cycle in an undirected graph.
    bool doBFS(vector<int> adj[], int root, int isVisited[]){
        
        queue<int> q, p;
        q.push(root), p.push(-1);
        isVisited[root] = 1;
        
        while(q.empty()==false){
            
            auto currNode = q.front(), parent = p.front();
            q.pop(), p.pop();
            
            for(auto node : adj[currNode]){
                
                if( isVisited[node] ){
                    if( parent != node ) return true;
                }
                else{
                    q.push(node), p.push(currNode);
                    isVisited[node]=1;
                }
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
    
        int isVisited[V];
        memset(isVisited, 0, sizeof(isVisited));
        
        for(int i=0;i<V;i++){
            if( isVisited[i]==0 &&  doBFS(adj, i, isVisited) ) return true;
        }
        return false;
    }
};
