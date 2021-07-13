

// Question Link :: "https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1"


// Solution //

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int v, vector<int> adj[])
	{
	    // Code here
	    vector<int> ans;
	    queue<int> q;
	    vector<bool> inQueue(v,false);
	    
	    q.push(0);
	    inQueue[0] = true;
	    while(q.empty()==false){
	        
	        auto n = q.front();
	        q.pop();
	        ans.push_back(n);
	        
	        for(auto node : adj[n])
	            if(inQueue[node] == false)
	                q.push(node),inQueue[node] = true;
	    }
	    
	    return ans;
	}
};
