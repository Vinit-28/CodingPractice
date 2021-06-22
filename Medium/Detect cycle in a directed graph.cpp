

// Question Link :: "https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#"


// Soltuion //

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
        
        vector<bool> is_visited(V), stack(V);
        
        for(int i=0;i<V;i++)
            if( !is_visited[i] && dfs(is_visited, i, adj, stack) )
                return true;
        
        return false;
	}
	
	bool dfs(vector<bool> &is_visited, int node, vector<int> adj[], vector<bool> &stack){
	    
	    if( !is_visited[node] ){
	        
	        stack[node]=true;
	        is_visited[node]=true;
	        
	        for(auto n : adj[node])
	            if( stack[n] || dfs(is_visited,n,adj,stack) )
	                return true;
	    }
	    
	    stack[node]=false;
	    return false;
	}
};