

// Question Link :: "https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1#"


// Solution //

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    
	
	void DijkstraAlgo(vector<vector<int>> &grid, vector<vector<int>> &dist, int n){
	    
	   // Heap to store lowest distance vertex along with their coordinates //
	    set<pair<int, pair<int,int>>> nodes;
	    
	    vector<vector<bool>> isVisited(n,(vector<bool>(n,false)));
	    
	    dist[0][0] = grid[0][0];
	    nodes.insert({grid[0][0], {0,0}});
	    
	    while(nodes.empty() == false && isVisited[n-1][n-1] == false){
	        
	        auto p = *(nodes.begin());
	        nodes.erase(nodes.begin());
	        
	        int x = p.second.first, y = p.second.second, cost = p.first;
	        
	       
	        isVisited[x][y] = true;
	        
	        if( x+1 < n && isVisited[x+1][y] == false ){
	            
	            if( dist[x+1][y] >  ( dist[x][y] + grid[x+1][y] ) ){
	                
	                if( dist[x+1][y] != INT_MAX )
	                    nodes.erase(nodes.find({dist[x+1][y], {x+1,y}}));
	                
	                dist[x+1][y] = dist[x][y] + grid[x+1][y];
	                nodes.insert({ dist[x+1][y], {x+1,y} });
	            }
	        }
	        
	        if( x-1 >= 0 && isVisited[x-1][y] == false ){
	            
	            if( dist[x-1][y] >  ( dist[x][y] + grid[x-1][y] ) ){
	                
	                if( dist[x-1][y] != INT_MAX )
	                    nodes.erase(nodes.find({dist[x-1][y], {x-1,y}}));
	                
	                dist[x-1][y] = dist[x][y] + grid[x-1][y];
	                nodes.insert({ dist[x-1][y], {x-1,y} });
	            }
	        }
	        
	        
	        if( y+1 < n && isVisited[x][y+1] == false ){
	            
	            if( dist[x][y+1] >  ( dist[x][y] + grid[x][y+1] ) ){
	                
	                if( dist[x][y+1] != INT_MAX )
	                    nodes.erase(nodes.find({dist[x][y+1], {x,y+1}}));
	                
	                dist[x][y+1] = dist[x][y] + grid[x][y+1];
	                nodes.insert({ dist[x][y+1], {x,y+1} });
	            }
	        }
	        
	        
	        if( y-1 >= 0 && isVisited[x][y-1] == false ){
	            
	            if( dist[x][y-1] >  ( dist[x][y] + grid[x][y-1] ) ){
	                
	                if( dist[x][y-1] != INT_MAX )
	                    nodes.erase(nodes.find({dist[x][y-1], {x,y-1}}));
	                
	                dist[x][y-1] = dist[x][y] + grid[x][y-1];
	                nodes.insert({ dist[x][y-1], {x,y-1} });
	            }
	        }
	    }
	}
	
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        
        int n = grid.size();
        
        vector<vector<int>> dist(n);
        vector<vector<bool>> isVisited(n);
        
        
        for(int i=0;i<n;i++){
            dist[i] = (vector<int>(n,INT_MAX));
            isVisited[i] = (vector<bool>(n, false));
        }
        
        DijkstraAlgo(grid, dist, n);
       
        return dist[n-1][n-1];
    }
};