


// Question Link :: "https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1"



// Solution //


class Solution{

    public:
    
    map<int, vector<int>> graph;
    bool isHamiltonian=false;
    int target_vertices;
    
    bool check(int n,int m,vector<vector<int>> edges)
    {
        // code here
        graph.clear();
        isHamiltonian = false;
        target_vertices = n;
        
        createGraph(edges);
    
        for(auto vertex : graph){
            
            findPath({vertex.first},vertex.first,1);
            if( isHamiltonian )
                return isHamiltonian;
        }
        return isHamiltonian;
    }
    
    void findPath(vector<int> curr_path, int curr_vertex, int vertices_covered){
        
        if( vertices_covered == target_vertices )
        {
            isHamiltonian = true;
            return;
        }
        
        for(int i=0;i<graph[curr_vertex].size();i++){
            
            if( isHamiltonian )
                return;
            
            if( is_exist(curr_path, graph[curr_vertex][i]) == false ){
                
                curr_path.push_back(graph[curr_vertex][i]);
                
                findPath(curr_path, graph[curr_vertex][i], vertices_covered+1);
                
                curr_path.pop_back();
            }
            
        }
        
        
    }
    
    bool is_exist( vector<int> path, int vertex ){
        
        for(int i=0;i<path.size();i++){
            if( path[i] == vertex )
                return true;
        }
        return false;
    }
    
    void createGraph(vector<vector<int>> edges){
        
        
        for(int i=0;i<edges.size();i++){
            
            graph[edges[i][0]].push_back(edges[i][1]);
            
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
    }
    
};