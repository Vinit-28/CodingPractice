

// Question Link :: "https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#"


// Solution //

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    
    vector<int> order;
    int kosaraju(int V, vector<int> adj[]){

        int counter = 0;
        vector<bool> is_visited1(V), is_visited2(V);
        vector<int> rev_adj[V];
      
        order.clear();
        
        for(int i=0; i<V; i++)
            if( is_visited1[i]==false )
                dfs(i,is_visited1,adj,true);
        
        get_reverse(V, adj, rev_adj);
    
        for(int i=order.size()-1;i>=0;i--)
            if( is_visited2[order[i]]==false ){
                dfs(order[i],is_visited2,rev_adj,false);
                counter+=1;
            }
        
        return counter;
    }
    
    void get_reverse(int v, vector<int> adj[], vector<int> rev_adj[]){
        
        for(int i=0; i<v; i++)
            for(auto node : adj[i])
                rev_adj[node].push_back(i);

    }

    void dfs(int index, vector<bool> &is_visited, vector<int> adj[],bool fill_order){
        
        is_visited[index] = true;
        for(auto node : adj[index]){
            
            if(!is_visited[node])
                dfs(node,is_visited,adj,fill_order);
        }
        if(fill_order)
            order.push_back(index);
    }
};
