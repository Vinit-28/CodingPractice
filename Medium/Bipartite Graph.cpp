

// Question Link :: "https://practice.geeksforgeeks.org/problems/bipartite-graph/1"


// Solution //

class Solution{
    public:

    bool BFS(int v, vector<int> adj[], vector<int> &sets, int node){
        
        queue<int> q;
        
        q.push(node);
        sets[node] = 0;
        
        while(q.empty() == false){
            
            int currNode = q.front();
            q.pop();
            
            for(int i=0; i<adj[currNode].size(); i++){
                
                if( sets[currNode] == sets[adj[currNode][i]] )
                    return false;
                
                else if( sets[adj[currNode][i]] == -1 ){
                    sets[adj[currNode][i]] = (sets[currNode] == 0)? 1 : 0;
                    q.push(adj[currNode][i]);
                }
            }
        }
        return true;
    }

	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    
	    vector<int> sets(v, -1);
	    
	    for(int i=0; i<v; i++){
	        
	        if( sets[i] == -1 ){
	            
	            if( BFS(v, adj, sets, i)==false )
	                return false;
	        }
	    }
	    return true;
	}
};