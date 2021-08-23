

// Question Link :: "https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1#"


// Solution //

class Solution
{
	public:
	
	void initialize(int arr[], int size, int val){
	    
	    for(int i=0;i<size;i++) arr[i] = val;
	}
	
	
	void DFS(vector<int> adj[], int node, int &defaultParent, int parent[], int inStack[], vector<int> &stackScc, vector<vector<int>> &ans){
	    
	    parent[node] = defaultParent;
	    defaultParent++;
	    inStack[node] = 1;
	    stackScc.push_back(node);
	    
	    int temp = parent[node];
	    
	    for(auto n : adj[node]){
	        
	        if( parent[n] == -1 ){
	            
	            DFS(adj, n, defaultParent, parent, inStack, stackScc, ans);
	            parent[node] = min(parent[node], parent[n]);
	        }
	        else if( inStack[n] == 1 )
	            parent[node] = min(parent[node], parent[n]);
	    }

	    if( parent[node] == temp ){
	        
	        vector<int> scc;
	        int top;
	        do{
	            top = stackScc.back();
	            scc.push_back(top);
	            inStack[top] = 0;
	            stackScc.pop_back();
	            
	        }while(top != node);
	        
	        sort(scc.begin(), scc.end());
	        ans.push_back(scc);
	    }
	}
	
	
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<vector<int>> ans;
        int parent[V], inStack[V], defaultParent=0;
        vector<int> stackScc;
        initialize(parent, V, -1);
        initialize(inStack, V, 0);
        
        for(int i=0;i<V;i++)
            if( parent[i] == -1 )
                DFS(adj, i, defaultParent, parent, inStack, stackScc, ans);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
